#include <stdio.h>
#include "STD_TYPES.h"
#include "grad_interface.h"


int main()
{   
 while (1)
 {
	u8 choice ;
   printf("*************************************\n");
   printf("If admin enter 1, if client enter 2 :");
   scanf(" %d",&choice);

  switch(choice)
  { case 1: name_pass();               break;
							          
    case 2: Client_window();           break;
	
	default: printf("Invalid choice"); break;   
  }
  
 }	
	
	
	
}