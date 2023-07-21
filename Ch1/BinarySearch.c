/*Needed libraries*/
#include <stdio.h>

/*Functions' prototype*/
int BinarySearch(int NumbersArr[], int ArrSize, int SearchNumber);

/*It is the main*/
int main()
{
	/*Define Variables*/
	int NumbersArr[20];
	int SearchNumber;
	int SearchNumberIndex;
	
	/*Scan Numbers from the user*/
	for(int i = 0; i < 20; i++)
	{
		printf("Please, Enter Number %d: ", (i + 1));
		scanf("%d", &NumbersArr[i]);
	}
	
	/*Ask the user to enter a number to search*/
	printf("Enter a number to search: ");
	scanf("%d", &SearchNumber);
	
	/*Search for the number*/
	SearchNumberIndex = BinarySearch(NumbersArr, 20, SearchNumber);
	
	/*Print the search number index to the user*/
	if(SearchNumberIndex != -1)		//Successful search
	{		
		printf("%d is at index %d.", SearchNumber, (SearchNumberIndex + 1));
	}
	else
	{
		/*Number does not exist*/
		printf("Number does not exist!");
	}
	
	/*Return to the operating system*/
	return 0;
}

int BinarySearch(int NumbersArr[], int ArrSize, int SearchNumber)
{
	/*Define Variables*/
	int LowIndex = 0;
	int MidIndex = ArrSize / 2;
	int HighIndex = ArrSize - 1;
	int SearchNumberIndex = -1;
	
	while(LowIndex <= HighIndex)
	{
		if(NumbersArr[MidIndex] == SearchNumber)
		{
			SearchNumberIndex = MidIndex;
			break;
		}
		else if(SearchNumber < NumbersArr[MidIndex])
		{
			HighIndex = MidIndex - 1;
		}
		else if(SearchNumber > NumbersArr[MidIndex])
		{
			LowIndex = MidIndex + 1;
		}
		MidIndex = (LowIndex + HighIndex)/2;
	}
	return SearchNumberIndex;
}