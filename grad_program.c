#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include <string.h>
#include "grad_interface.h"

typedef struct account
{ 
   u8   name [20] ;
   u8   address [20];
   u8   age;
   u64  National_ID;
   u32  balance ;
   u8   account_status [11] ;
   u64 password;
   u64  Account_ID;
  
	
}client ;

client arr [50];
client  bank_account ;
u16 number =0;
s8 index_ =-1;

void name_pass (void )
{  u8 Admin_name []= "Hager" ;
   u8 Admin_pass[] = "123" ;
   u8 name[6] , pass[3];
   u8 i ,name_result , pass_result ;
   printf("Enter your name: ");
   scanf("%s",&name);
   name_result = strcmp(Admin_name, name) ;
   if(name_result ==0)
   { 
       printf("Enter your password:\n");
       scanf("%s",&pass);    

        pass_result = strcmp(Admin_pass, pass) ;
         if(pass_result==0)
		 {printf("welcom in admin window\n");
		     Admin();
		 }
		 else
		     printf("Invalid password\n");
   }			
	else
		printf("Invalid name\n");
}


void Admin(void)
{  u8 choice ;
  client object ;
  printf("If want Create New Account enter 1\nif want Open Existing Account enter 2\nif want Exit System enter 3 :");
  scanf("%d",&choice);
   switch(choice)
  { case 1:   Create_Account() ;
              set_data (number );
			  number++ ;
			  break;
	case 2:   Open_Account  () ; break;
	case 3:   ; break;
    default: printf("Invalid choice"); break;  
  }
  
	
}
u8 Create_Account ()
{
	client obj;
	
	strcpy(obj.account_status ,"active" );
	strcpy(bank_account.account_status ,obj.account_status);
	
	printf("Enter name :\n");
    scanf(" %[^\n]",&obj.name );
	strcpy(bank_account.name , obj.name);
	 
	printf("Enter address:\n");
    scanf(" %[^\n]",&obj.address);
	strcpy(bank_account.address , obj.address);
	 
	printf("Enter age:\n");
    scanf("%d",&obj.age);

	if((obj.age<21)&&(obj.age>0))
	{  bank_account.age =obj.age;

       printf("Enter guardian National ID:\n");
       scanf("%d",&obj.National_ID);
	   
	   // if(!(obj.National_ID>10000000000000) &&(obj.National_ID<99999999999999))
	  // {  printf("error National_ID\n");
	    // return 0 ;
      // } 
     	// else 
         bank_account.National_ID = obj.National_ID;			
	}
    else if((obj.age >=21)&&(obj.age<150))
	{ bank_account.age =obj.age;
      printf("Enter National ID:\n");
      scanf("%d",&obj.National_ID);
	  // if(!(obj.National_ID>10000000000000) &&(obj.National_ID<99999999999999))
	  // {  printf("error National_ID\n");
	   // return 0 ;
      // } 
       // else 
         bank_account.National_ID = obj.National_ID;			
	}
	else
	{
	  printf("error Age\n");
	   return 0 ;
	}		
		
     printf("Enter balance:\n");
     scanf("%d",&obj.balance);
	 bank_account.balance = obj.balance ;	
	 
	obj.password = rand()%(1000+1-100)+1000 ;
	printf("your password is %d\n",obj.password);
	bank_account.password = obj.password ;	
	
	obj.Account_ID = rand()%(9999999999+1-1000000000)+9999999999 ;
	printf("your Account ID is %d\n",obj.Account_ID);
	bank_account.Account_ID = obj.Account_ID ;
}

void set_data (u16 location )
{   
	strcpy(arr[location].name , bank_account.name);
	strcpy(arr[location]. address , bank_account. address);
	arr[location]. age , bank_account. age ;
    arr[location].National_ID = bank_account.National_ID;	
	arr[location].balance = bank_account.balance;	
    strcpy(arr[location]. account_status , bank_account. account_status);
	arr[location].password = bank_account.password;
	arr[location].Account_ID = bank_account.Account_ID;
	
	 printf(" %d\n",location );
}


u8 Open_Account  (void)
{   u64 Acc_ID;
    u8 i;
    printf("Enter Client Bank Account ID: ");
	scanf("%d",&Acc_ID);
	for(i=0 ;i<50 ; i++)
	{
		if(Acc_ID ==arr[i].Account_ID)
		{ 
		    index_=i ;
             break;			
		}
		else 
			 continue;
	}
   if(index_ ==-1)
   {
	   printf("Ivalid ID \n");
	   return 0 ;
   }
	 u8 choice ;
     printf("If want Make Transaction  enter 1\nif want  Change Account Status enter 2\nif want  Get Cash enter 3\n ");
	 printf("if want Deposit in Account enter 4\nTo Return to main menu enter 5 ;\n");
     scanf("%d",&choice);
   switch(choice)
  { case 1: Transaction(); break;
  
	case 2:  change_status();  break ;
    case 3:  Get_Cash ();      break;
    case 4:  Deposit ();       break ;
    case 5:  Admin();
  }
}

u8 Transaction(void)
{  
	u64 ID;
    u8 i , money , result;
	s8  index1=-1 ;
    printf("Enter Account ID you want to transfer money to: ");
	scanf("%d",&ID);
	for(i=0 ;i<50 ; i++)
	{
		if(ID ==arr[i].Account_ID)
		  	index1 = i;
		   break;
	}
	if(index1 ==-1)
   {
	   printf("Ivalid ID \n");
	   return 0 ;
   }
	printf("Enter amount of money to transfer it to the this account \n");
	scanf("%d",&money);
	if(money >= arr[index_].balance)
	{
		result =strcmp(arr[index_].account_status ,arr[index1].account_status);
		if (result==0)
		{
			arr[index1].balance += money;
			printf("Done \n");
		}
		else 
		 printf("This transaction cann’t be completed\n");
	}
	else 
		printf("Your balance not enough\n");
	
}

void change_status(void)
{    u8 status[11];
	printf("Enter Status you want for this account :");
	scanf("%s",&status);
	strcpy(arr[index_]. account_status , status);
	
}

void Get_Cash (void)
{
	u8 money ;
	printf("Enter a amount of money you want from this account :\n");
	scanf("%d",&money);
	if(money <= arr[index_].balance)
	{    
          arr[index_].balance -= money;
			printf("Done \n");
	}
	else 
		printf("Your balance not enough\n");
	
}
void Deposit (void)
{
	u8 money ;
	printf("Enter a amount of money you want to add :\n");
	scanf("%d",&money);
	arr[index_].balance += money;
}

void Client_window (void)
{    u64 Acc_ID , pass ;
     u8 i;
	 u8 count=0 ;
    
     printf("Enter your bank account ID :\n");
     scanf("%d",&Acc_ID);
	 for(i=0 ;i<50 ; i++)
	 {
	   if(Acc_ID ==arr[i].Account_ID)
	   {   count+=1 ;
		   printf("Enter your Password:\n");
           scanf("%d",&pass); 
		   for(i=0 ;i<50 ; i++)
	      {
	        if(pass ==arr[i].password);
	        {   count+=1;
			    index_ =i ;
       			printf("Welcom in client window");
			   Client ();
		    }
	      }
	   }
	 }
	  if(count==0)
		 printf("Invalid ID \n");
	else if(count==1)
		   printf("Invalid password \n");
}

void Client (void)
{
    u8 choice ;
     printf("If want Make Transaction  enter 1\nif want Change password enter 2\nif want Get Cash enter 3\n ");
	 printf("if want Deposit in Account enter 4\nTo Return to main menu enter 5 ;\n");
     scanf("%d",&choice);
   switch(choice)
  { case 1:  Transaction();      break;
	case 2:  change_password();  break ;
    case 3:  Get_Cash ();        break;
    case 4:  Deposit ();         break ;
    case 5:  Admin();	
  }
}

void change_password(void)
{   u64 new_pass ;
    printf("Enter new password :");
    scanf ("%d",&new_pass);
    arr[index_].password ,new_pass;
	   
	  
}