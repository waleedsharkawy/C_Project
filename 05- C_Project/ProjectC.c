/********************************This is Prograamed by****************************
************************************WaleedSharawy*********************************
************************************Main program**********************************
**********************************************************************************/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#include "macros.h"
#include "typedefine.h"
/*varibales decleration*/
u8 Window;
u8 AdminSub;
u8 AdminSSub;
u8 ClientSub;
u8 ExisitingAccount_sub;
u8 Number_Of_Accounts=0;
u16 Client_Password;
u16 New_Password;
u32 ID_Number;
u32 Random_Number;
u8 AdminUser_check[5];
u8 AdminPass_check[5];
Account_S Accounts[100]={};
u8 Bank_Account_index;

/*functions decleration*/
Account_S Create_New_Account(void);
u32 Open_Exisiting_Account(void);
void Make_Transaction(void);
void Change_Account_Status(void);
void GetCash(void);
void Deposit_In_Account(void);
void Change_Account_Password_client(void);



void main(void)
{
	//loop to excute commands continuosly
	while (1)
	{
	/*condiditions of 2 windows*/
	printf("\t\t(1) Admin window \n\t\t(2) Client window \n\t\t(3) Exit System\n\t\tNumber: ");
	/*taking the desired window input either admin or client*/
	scanf("%d",&Window);
	
	
	/*check it the desired window is admin window*/ 

	if (Window==AdminWindow)
	{
		/*get user and password of admin menu from user*/
		printf("please enter admin user: ");
		scanf("%s",AdminUser_check);
		fflush(stdin);
		printf("please enter admin pass: ");
		scanf("%s",AdminPass_check);
		
		/*loop to stay at Admin window until willing to get out of it*/
		while (1)
		{
			/*check if password is wrong to enter it again*/
			if (strcmp(AdminUser,AdminUser_check)!=0 || strcmp(AdminPass,AdminPass_check)!=0)
			{
				printf ("\n    \t\tyou have entered invalid user or password please try again\n");
				break;
			}	
			
			/*asking user about desired sub windows*/
			printf("\n\t\twelcome to admin window");
			printf("\n\t\t(1) Create New Account\n\t\t(2) Open exisiting account\n\t\t(3) Return to Main Window \n\t\tNumber: ");
			/*taking the desired input into varibale*/
			scanf("%d",&AdminSub);
			
			/*check which subwindow the program would excute*/
			if (AdminSub==CreateNewAccount)
			{
				/*Creating new accout*/
				Accounts[Number_Of_Accounts] = Create_New_Account();
				/*indication when process is done*/
				printf("\n\t\t\t\tAccount no : [%u] is successfuly created\n",++Number_Of_Accounts);
				
			}
			else if (AdminSub==OpenExisitingAccount)
			{
				/*open ExisitingAccount*/
				printf("\n\t\twelcome to open exisiting Account");
				/*getting index of desired element in the array of struct*/
				Bank_Account_index=Open_Exisiting_Account();
				
				/*taking desired operation from user*/ 
				printf("\n\t\t(1) Make Transaction\n\t\t(2) Change Account Status\n\t\t(3) Get Cash \n\t\t(4) Deposit in Account \n\n\tNumber: ");
				scanf("%u",&ExisitingAccount_sub);
				/*check which operation to be excuted*/
				if (ExisitingAccount_sub==MakeTransaction_Admin)
				{
					/*Make Transaction window*/
					Make_Transaction();
				}
				else if (ExisitingAccount_sub==ChangeAccountStatus_Admin)
				{
					/*change account window*/
					Change_Account_Status();
				}
				else if (ExisitingAccount_sub==GetCash_Admin)
				{
					/*get cash window*/
					GetCash();
				}
				else if (ExisitingAccount_sub==DepositInAccount_Admin)
				{
					/*Deposit In Account Window*/
					Deposit_In_Account();
				}
				else if (ExisitingAccount_sub==ReturnToMainMenu_Admin)
				{
					/*get out of this account*/
					printf("\nClosing Window\n");
					break;
				}
			}
			else if (AdminSub==ExitAdminWindow)
			{
				printf("\n\t\t Exiting Admin Window\n");
				break;
			}
			else
			{
				/*warning when entering Wrong choice*/
				printf("\n\t\t you have choose Wrong option please try again\n");
				continue;
			}
		}
	
	}
	
	
	/*Client Window*/
	else if (Window==ClientWindow)
	{
		u8 i;
		u8 check=0;
			printf("\nwelcome to client window\n");
			/*gettig Bank ID number and password from client user*/
			printf("\nplease enter Account ID Number: ");
			scanf("%u",&ID_Number);
			printf("\nplease enter Account Password: ");
			scanf("%u",&Client_Password);
			
			/*loop to get the index of desired Account in intialized array of struct*/
			for (i=0;i<Number_Of_Accounts;++i)
			{
				if (Accounts[i].Bank_Account_ID==ID_Number && Accounts[i].Password==Client_Password)
				{
					/*getting the index value in the array of struct*/
					Bank_Account_index=i;
					/*for indicate successful operation*/
					check = 1;
					break;
				}
			}
			if (check!=1)
			{
				printf("\nyou've enter invalid ID or password\n");
				break;
			}
		
		//loop to excute commands continuosly
		while (1)
		{
			printf("\n\t\t(1) Make Transaction\n\t\t(2) Change Account Password\n\t\t(3) Get Cash\n\t\t(4) Deposit In Account\n\t\t(5) Return To Main Menu \n\t\tNumber: ");
			scanf("%d",&ClientSub);
			if (ClientSub==MakeTransaction_client)
			{
				/*Make Transaction window*/
				Make_Transaction();
			}
			else if (ClientSub==ChangeAccountPassword_client)
			{
				/*change Password window*/
				Change_Account_Password_client();
			}
			else if (ClientSub==GetCash_client)
			{
				/*get Cash Window*/
				GetCash();
			}
			else if(ClientSub==DepositInAccount_client)
			{
				/*Deposit In Account Window*/
				Deposit_In_Account();
			}
			else if (ClientSub==ExitClientWindow_client)
			{
				/*Returing to main window*/
				printf("\n\t\t ExitClientWindow\n");
				break;
			}
			else
			{
				/*warining when user enter wrong choice*/
				printf("\n\t\t you have choose Wrong option please try again\n");
				continue;
			}
		
		
		}
	}
	else if (Window==3)
	{
		/*closing whole application window*/
		printf("Closing Application");
		break;
	}
	else
	{
		/*warining when user enter wrong choice*/
		printf("\n\t\t you have choose Wrong option please try again\n");
		continue;
	}
	
	}
	
}


Account_S Create_New_Account(void)
{
	/*decleare struct to be returned after storing inputs from user*/
	Account_S Acc;
	printf("\n==================================================\n");
	/*getting inputs from user*/
	printf("please enter full Name: ");
	fflush(stdin);
	scanf("%[^\n]s",Acc.Name);
	fflush(stdin);
	printf("please enter full address: ");
	scanf("%[^\n]s",Acc.Address);
	fflush(stdin);
	printf("please enter National_ID: ");
	scanf("%[^\n]s",Acc.National_ID);
	
	printf("please enter your age: ");
	scanf("%u",&Acc.Age);
	if (Acc.Age>=21)
	{
		fflush(stdin);
		strcpy(Acc.Guardian_National_ID,"None");
	}
	else
	{
		printf("please enter Guardian National ID: ");
		fflush(stdin);
		scanf("%[^\n]s",Acc.Guardian_National_ID);
	}
	printf("please enter Account Balance: ");
	scanf("%d",&Acc.Balance);
	/*automatic set account to active mode*/
	Acc.Account_Status=Active;
	/*generating random Account ID and password*/
    srand(time(0));
	Acc.Bank_Account_ID = rand()%(End_ID+1-Start_ID)+Start_ID;
	srand(time(0));
	Acc.Password = rand()%(End_Password+1-Start_Password)+Start_Password;
	
	/*giving user the automatated info password and Bank ID aslo indicates successufly process*/
	printf("\n\t \t=============================================================================\n \t \t Bank ID of name [%s] is [%u] Password Is [%u]\n\t \t=============================================================================\n",Acc.Name,Acc.Bank_Account_ID,Acc.Password);
	/*returning the struct*/
	return Acc;
}

u32 Open_Exisiting_Account(void)
{
	/*decleare variables counter and ID_Number*/
	u8 i;
	u32 ID_Number;
	/*gettig Bank ID number from admin user*/
	printf("\nplease enter Account ID Number: ");
	scanf("%u",&ID_Number);
	
	/*loop to get the index of desired Account in intialized array of struct*/
	for (i=0;i<Number_Of_Accounts;++i)
	{
		if (Accounts[i].Bank_Account_ID==ID_Number)
		{
			/*return the index*/
			return i;
		}
	}
	/*warning when input wrong ID Number*/
	printf("\nID doesn't exist please try again\n");
}

void Make_Transaction(void)
{
	/*getting ID of the other account and its index in intialized array of struct*/
	printf("\n Data Related to Tranfer Account ");
	u8 Transfer_Bank_Account_index=Open_Exisiting_Account();
	/*getting amount of money to be transfered*/
	u32 Money_Transfer;
	printf("Please enter amount of money to be transfered: ");
	scanf("%u",&Money_Transfer);
	
	/*check if Balance of Account is suffcient and both acccounts are in active state*/
	if (Accounts[Bank_Account_index].Balance<Money_Transfer)
	{
		printf("\n sorry your current balance isn\'t suffcient");
	}
	else if (Accounts[Bank_Account_index].Balance>Money_Transfer && Accounts[Bank_Account_index].Account_Status==Active && Accounts[Transfer_Bank_Account_index].Account_Status==Active)
	{
		Accounts[Bank_Account_index].Balance-=Money_Transfer;
		Accounts[Transfer_Bank_Account_index].Balance+=Money_Transfer;
		printf("\nyou have been transfered %u successufly your balance is: %u",Money_Transfer,Accounts[Bank_Account_index].Balance);
	}
	
	
}

void Change_Account_Status(void)
{
	/*decleare variable to store desired state from Admin user*/
	u8 State;
	
	/*loop to make user enter the desired state again if its wrong*/
	while(1)
	{
	/*getting desired state from user*/
	printf("\nChange your account state to: \n 1) Active 2)Restricted 3)Closed\n\t\t Number: ");
	scanf("%u",&State);
	
	/*check if user entered one of the three decleared states if not loop till its okay*/ 
	if (State==1 || State==2 || State==3)
	{
		Accounts[Bank_Account_index].Account_Status=State;
		printf("Done!\n");
		break;
	}	
	else
		printf("\nyou have entered invalid number\n");
	}
}

void GetCash(void)
{
	/*decleare variable to store amount of money*/
	u32 Amount_Of_Money;
	printf("\nplease enter amount of Money: ");
	scanf("%u",&Amount_Of_Money);
	/*check if amount of money is less than the actual balance*/
	if (Accounts[Bank_Account_index].Balance>Amount_Of_Money)
	{
		Accounts[Bank_Account_index].Balance-=Amount_Of_Money;
		/*printing the result of operation*/
		printf("\nsuccessful operation done get out %u\n your balance is: %u",Amount_Of_Money,Accounts[Bank_Account_index].Balance);
	}
	else
	{
		printf("\nSorry Insuffcient Balance");
	}
}
void Deposit_In_Account(void)
{
	/*decleare varibale to get amount of added money*/
	u32 Added_Money;
	printf("Please Enter Amount of Money to be added: ");
	scanf("%u",&Added_Money);
	/*adding Value to Current Balance*/
	Accounts[Bank_Account_index].Balance+=Added_Money;
	/*printing the result of operation*/
	printf("\nsuccessful operation done your balance is: %u",Accounts[Bank_Account_index].Balance);
}

void Change_Account_Password_client(void)
{
	printf("Please enter old Password : ");
	scanf("%u",&Client_Password);
	printf("old password is: %u\n", Client_Password);
	printf("Please enter New Password 4 digits: ");
	scanf("%u",&New_Password);
	printf("New password is: %u", New_Password);
	/*change password if old pass match with account password*/
	if ( Client_Password == Accounts[Bank_Account_index].Password)
	{
		Accounts[Bank_Account_index].Password = New_Password;
		/*printing operation is done*/
		printf("\noperation is Done! your new password %u\n",Accounts[Bank_Account_index].Password);
	}
	else if (Client_Password != (Accounts[Bank_Account_index].Password))
	{
		printf("\nSorry you've enter wrong Password");
	}
}