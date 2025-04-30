#include<stdio.h>
#include<string.h>
const maxAc = 50; // maximum number of accounts.
int accountNumbers[50]; // global array variavle for account numbers.
char accountNames[50][50]; // global 2D array variable for account names.
float accountBalances[50]; // global array for numbers with decimals.
int i, count; // global integer variables.
void clearInput() // Function to Clear previous inputs and continue reading even if it's a new line and not the end of file. 
{
	int choice;
	while((choice = getchar()) !='\n' && choice !=EOF);
}

void createAccount() // declairing of create account function.
{
	int acNumber; // declaration of local varibale integer to use inside create account function.
	char acName[50]; // declaration of local varibale character to use inside create account function.
	float acBalance; // declaration of local varibale float to use inside create account function.
	if(count >= maxAc) // checking if the number of recrods or rows reached maximum allowed records.
	{
		printf("Maximum accounts reached.\n"); // displaying message if maximum reached.
        return;
	}
	printf("Enter account number: "); // prompt for account number.
    scanf("%d", &acNumber); // scanning the input and storing in local varable account number. 
    clearInput(); // calling the clear input function.
    
    for(i = 0 ; i < count; i++) // looping through account numbers.
    {
    	if(accountNumbers[i] == acNumber) // checking if local varibale account number matches global variable array account numbers.
    	{
    		printf("Account number: %d Exists.\n",acNumber); // display error message for duplicate account number.
    		return;    		
		}    	
	}
	printf("Enter A/C name: "); // if no duplication found. prompt for account name.
	fgets(acName,99,stdin); // scans account name as strings and store in local variable account name array.
	printf("Enter initial deposit: "); // prompt for initial deposit.
	scanf("%f",&acBalance); // scans account balance and stores in local variable account balance float.
	if(acBalance < 50) // setting a limitation of 50 and checking minimum balance for account opening.
	{
		printf("Minimum balance 50.00\n"); // display error if minimum balance is less than 50.
		return;
	}
	accountNumbers[count] = acNumber; // storing local variable account number into global variable account numbers array.
	strcpy(accountNames[count],acName); // storing local variable account name into  global variable account names array.
	accountBalances[count] = acBalance; // storing local variable balance into global variable account balance array.
	count++; // incrementing the count (index of the row) to insert next record.
	printf("Account successfully created.\n");	// display success message for account creation.
	clearInput(); // calling the clear input function.
}
void depositMoney() // declairing of deposit money function.
{
	if(count == 0) // check if any account exists.
	{
		printf("No Accounts found.\n"); // display account not found message.
		return;
	}	
	int acNumber; // declaration of local varibale integer to use inside deposit money function.
	float amount; // declaration of local varibale character to use inside deposit money function
	printf("Enter account number:"); // prompt for account number.
	scanf("%d",&acNumber); // scanning the input and storing in local varable account number.
	clearInput(); // calling the clear input function.
	
	for(i = 0; i < count; i++) // looping through account numbers.
	{
		
		if(accountNumbers[i] == acNumber) // verifying if account number exists before excepting the deposit.
		{
			printf("Enter Amount: "); // prompt for amount.
			scanf("%f",&amount); // scanning and storing into local varibale amount.
			clearInput(); // calling the clear input function.
			
			if(amount <= 0) // restricting deposit value 0 and negative values.
			{
				printf("Amount should be greater than 0.00\n"); // displaying error message if zero or negative.
				return;
			}
			
			accountBalances[i] += amount; // addition of local variable amount to global variable previous account balance.
			printf("Deposited Successfully. Current balance = %.2f\n",accountBalances[i]); // dislpaying current global variable balance after successful deposit.
			return; 
		}
	}
	printf("Account does not exist.\n"); // display account not found message.
	return;
}
void withdrawMoney() // declaraing of withdraw money function
{
	if(count == 0) // check if any account exists.
	{
		printf("No Accounts found.\n"); // display message if no account found.
		return;
	}
	int acNumber; // declaration of local varibale integer to use inside withdraw money function.
	float amount; // declaration of local varibale character to use inside withdraw money function
	printf("Enter account number:"); // prompt for account number.
	scanf("%d",&acNumber); // scanning and storing into local variable account number.
	clearInput(); // calling the clear input function.
	for(i = 0; i < count; i++) // looping through account numbers.
	{
		if(accountNumbers[i] == acNumber) // verifying account number before prompting for withdrawal amount.
		{
			printf("Enter withdrawal Amount: "); //  prompt for withdrawal amount.
			scanf("%f",&amount); // scanning and storing into local valirable amount.
			clearInput(); // calling the clear input function.
			if(amount <= 0) // checking if the amount is zero or negative.
			{
				printf("Amount not valid.\n"); // displaying error if amount is negative or zero.
				return;
			}
			else if (amount > accountBalances[i]) // checking if the withdral amount is higher than available balance/current balance of account.
			{
				printf("Insufficient fund.\n"); // displaying error if amount is higher than available balance.
				return;
			}
			else // if the amount is not zero or negative and if the amount is not higher than available balance. 
			{
				accountBalances[i] -= amount; // substract withdrawal local variable amount from global variable account balance.
				printf("Withdrawal success. New Balance %.2f: ",accountBalances[i]); // display withdrawal success message and new updated account balance in two decimal places.
				return;
			}
		}
		printf("Account does not exist.\n"); // display account not found message.
		return;
	}
}
void displayAccount()
{
	int acNumber; // declaration of local varibale integer to use inside withdraw money function.
	printf("Enter account number:"); // prompt for account number.
	scanf("%d",&acNumber); // scanning and storing into local variable account number.
	clearInput(); // calling the clear input function.
	int acIndex = findAccountIndex(acNumber); // calling the account index find function and retreiving row index.
	if(accountNumbers[acIndex] == acNumber)
	{
		printf("Account Holder: %s",accountNames[acIndex]); // displaying acount holder name.
		printf("Account Number: %d\n",accountNumbers[acIndex]); // displaying acount holder's account number.	
		printf("Current Balance: %.2f\n",accountBalances[acIndex]); // displaying current Balance.		
	}	
}
int findAccountIndex(int accNo)
{
	int accIndex; // local varibale for storing account number index.
	for(i = 0; i < count; i++) // looping through account numbers.
	{
		if(accountNumbers[i] == accNo) // verifying account number before getting the account index.
		{
			accIndex = i; // storing account number index to local variable.
			return;
		}
	}
	printf("Account does not exist.\n"); // display account not found message.
	return;	
}
int main()
{
	int option;
	do
	{
		printf("\nSimple Banking System:\n"); // name of the software.
		printf("1. Create Account\n"); // Option Create Account.
		printf("2. Deposit Money\n"); // Option Deposit Money.
		printf("3. Withdraw Money\n"); // Option Withdraw Money.
		printf("4. Display Account Details\n"); // Option Display Account Details.
		printf("5. Exit\n"); // Option Exit Program.
		printf("Enter Your Choice :"); // User Selected Option.
		scanf("%d",&option); // Storing Selected option in the variable for functions to use based on program.
		clearInput(); // calling clear input function.
		switch(option)
		{
			case 1:
				createAccount(); // if option 1 call account create function.
				break;
			case 2:
				depositMoney(); // if option 2 call deposit money function.
				break;
			case 3:
				withdrawMoney(); // if option 3 call withdrawal function.
				break;
			case 4:
				displayAccount(); // if option 4 call display account details function.
				break;
			case 5:
				printf("Exiting...\n"); // if option 5 display exiting message.
				break;
			default :
				printf("Invalid Option, Please try again.\n"); // if user input is undefined (other than options available),display error message.
		}
	}
	while (option != 5 ); // keep the program running untill the user chooses, option to exit.
	return 0;
}
