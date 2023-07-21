/*Needed libraries*/
#include <stdio.h>

/*Functions' prototype*/
int Factorial(int Num);

/*It is the main*/
int main()
{
	/*Define Variables*/
	int Num;
	int Fact;
	
	/*Scan a number from the user*/
	printf("Please, Enter a number: ");
	scanf("%d", &Num);
	
	/*Calculate the factorial of the number*/
	Fact = Factorial(Num);
	
	/*Print the result to the user*/
	if(Fact != -1)
	{		
		printf("%d! = %d", Num, Fact);
	}
	else
	{
		printf("Enter a valid number!");
	}
	
	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
int Factorial(int Num)
{
	/*Factorial works with only positive numbers, so we need to validate the number inputed*/
	if(Num >= 0)
	{
		/*Base Condition: If the number is zero, return 1*/
		if(Num == 0)
		{
			return 1;
		}
		/*Recursive Condition: If the number is any number except zero, return the same number multiplied by Factorial of the previous number*/
		else
		{
			return Num * Factorial(Num - 1);
		}		
	}
	else
	{
		/*Return the inputed number*/
		return -1;
	}
}