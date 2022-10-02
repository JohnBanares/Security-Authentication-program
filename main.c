/*
Program Description: This program gives the user a menu for a security authentication program, where the user code entered is encrypted and is compared to the access code 4523.
             -option 1 asks user the enter a 4 digit code.
             -option 2 encrypts this code and compares it to the authorised access code and counts the number of times the user code matches and doesn't match the access code. It also displays whether the code is correct or wrong.
             -option 3 decrypts the user code. 
             -option 4 displays to the user the number of times the code is right or wrong. 
             -option 5 exits the program gracefully.
Date:06/03/2021

Author: John Matthew Banares

Using VS code
*/
#include <stdio.h>

#define SIZE 4

//Function signatures
int userInput(int [SIZE]);
int encrypt(int [SIZE], int [SIZE], int *, int*, int*);
int decrypt(int [SIZE], int [SIZE], int *);
int show(int *, int*);
int endMenu(void);
int main()
{
    int choice;
    int userCode[SIZE];
    int i;
    static int check = 0;
    static int correct = 0;
    static int incorrect = 0;
    int accessCode[SIZE] = {4,5,2,3};
    do
    {   //Displays the menu and the following options the user can use
        printf("\nThis is the menu, please select one of the following\n");
        printf("1. Enter any code\n");
        printf("2. Encrypt code entered and verify if correct\n");
        printf("3. Decrypt code\n");
        printf("4. Display the number of times your encrypted code matches the authorised code\n");
        printf("5. Exit Program\n");
        scanf("%d", &choice);
            
        //clears input buffer
        while(getchar() != '\n');

        //This will carry out the instructions the user wants i.e user enters 1 to any 4 digit code.
        switch(choice)
        {
            case 1:
            { 
                //calls the function userInput with the following parameters.
                userInput(userCode);
                break;
            }//end case 1
            case 2:
            {   
                //calls the function encrypt with the following parameters.
                encrypt(userCode, accessCode, &correct, &incorrect, &check);
                break;
            }// end case 2
            case 3:
            {
                //calls the function decrypt with the following parameters.
                decrypt(userCode, accessCode, &check);
                break;
            }//end case 3
            case 4:
            {
                //calls the function show with the following parameters.
                show(&correct, &incorrect);
                break;
            }//end case 4
            case 5:
            {   
                //calls the function endMenu.
                endMenu();
                break;
            }//end case 5
            default:
            {
                //Checks if the user inputs an option not 1-5 or a character and displays a message
                printf("Invalid input, please try again\n");
                break;
            }//end default
        }//end switch

    }//end do while
    while(choice!= 5);

    return 0;
}//end main
int userInput(int userCode[])
{
    int i;
    int check;

    //Asks user to input a 4 digit code and stores it in array userCode. Only the first 4 digits of the user input is taken.
    printf("Please enter a 4 digit code\n");
    for(i = 0; i<SIZE; i++)
    {
        scanf("%1d", & *(userCode + i));
    }//end for

    //Displays what the user entered.
    printf("You entered\n");
    for(i = 0; i<SIZE; i++)
    {
        printf("%d", *(userCode + i));
    }//end for

    //checks if the code is more than 9999. But only works if 1 character is entered eg. 'a'.
    for(i = 0; i<SIZE; i++)
    {
        if(*(userCode) >= 9999)
        {
           check = 1;
        }//end if
    }//end for
    
    if(check == 1)
    {   //prints ERROR message to user.
        printf("\nERROR!\n");
    }//end if
    while(getchar() != '\n');
}//end userInput
int encrypt(int userCode[], int accessCode[], int *correct, int *incorrect, int *check)
{

    int i = 0;
    int temp1;
    int temp2; 
    //This if statement makes sure that the user cant encrypt a code twice in a row. 
    if(*check == 0)
    {  
        //swaps the first and third digits in the code.
        temp1 = *(userCode + i); 
        *(userCode + i) = *(userCode + i + 2);
        *(userCode + i + 2) = temp1;
        
        //swaps the seconds and fourth digits in the code.
        temp2 = *(userCode + i + 1); 
        *(userCode + i + 1) = *(userCode + i + 3);
        *(userCode + i + 3) = temp2;

        /*
        for(i = 0; i<SIZE; i++)
        {
            printf("%d", *(userCode + i));
        }
        printf("Before adding 1\n"); */

        // adding 1
        for(i = 0; i<SIZE; i++)
        {
            //increments each digit in the code by 1.
            *(userCode + i) = *(userCode + i) + 1;

            //if the digit incremented becomes 10 it becomes a 0.
            if(*(userCode + i) == 10)
            {
                *(userCode + i) = 0;
            }//end if 
        }//end for

        //Displays the user their encrypted code.
        printf("\nYour code is encrypted to\n ");
        for(i = 0; i<SIZE; i++)
        {
            printf("%d", *(userCode + i));
        }//end for
        i = 0;
        //To Verify if the encrypted code is equal the authorised access code. And counts the number of times the code is entered correctly
        if (userCode[i] == accessCode[i] && userCode[i+1] == accessCode[i+1] && userCode[i+2] == accessCode[i+2] && userCode[i+3] == accessCode[i+3])
        {
            printf("\nCorrect code entered!\n");
            *correct = *correct + 1;
        }//end if 
                    
        //This checks if the encrypted code does not equal their code, and counts the number of times the encrypted code doesn't match the authorised access code 
        else
        {
            printf("\nWrong code entered\n");
            *incorrect = *incorrect + 1;
        }// end else
    }//end if

    //if check is '1' user cannot encrypt again and is brought back to the menu
    else
    {
        printf("\nYou cannot encrypt your code!\n");
    }//end else
    *check = 1;
}//end encrypt
int decrypt(int userCode[], int accessCode[], int *check)
{
    int i = 0;
    int temp1;
    int temp2;
    //This if statement makes sure that the user cant decrypt a code twice in a row.
    if(*check == 1)
    {   
        //swaps the first and third digits in the code.
        temp1 = *(userCode + i); 
        *(userCode + i) = *(userCode + i + 2);
        *(userCode + i + 2) = temp1;
    
        //swaps the second and fourth digits in the code.
        temp2 = *(userCode + i + 1); 
        *(userCode + i + 1) = *(userCode + i + 3);
        *(userCode + i + 3) = temp2;
        
        /* debugging
        for(i = 0; i<SIZE; i++)
        {
            printf("%d", *(userCode + i));
        }
        printf("\nBefore minus 1\n"); */
        
        // minus 1
        for(i = 0; i<SIZE; i++)
        {
            //minus 1 from every digit in the code
            *(userCode + i) = *(userCode + i) - 1;

            //if the digit is -1 after the subtraction it becomes a '9'
            if(*(userCode + i) == -1)
            {
                *(userCode + i) = 9;
            }//end if
        }//end for
        printf("\nYou decrypted your code\n");
    }//end if
    //if check is 0 the user cannot decrypt their code.
    else
    {
        printf("\nYou cannot decrypt your code!\n");
    }//end else
    *check = 0;
}//end decrypt
int show(int *correct, int *incorrect)
{
    //Displays the number of times the user entered the their code correctly and incorrectly
    printf("You entered code correctly %d times\n", *correct);
    printf("You entered code incorrectly %d times\n", *incorrect);
}//end show
int endMenu(void)
{
    //Exits the program and displays a message to them.
    printf("You exited the menu, thank you\n");
    return 0;
}//end endMenu