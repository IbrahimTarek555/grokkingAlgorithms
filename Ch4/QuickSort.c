/*Needed libraries*/
#include <stdio.h>

/*Functions' prototype*/
void QuickSort(int NumbersArr[], int ArrSize);

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
		
	/*Sort the array*/
	QuickSort(NumbersArr, 20);
	
	/*Print the array elements after sorting*/
	for(int i = 0; i < 20; i++)
	{
		printf("Element %d is: %d\n", (i + 1), NumbersArr[i]);
	}

	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
void QuickSort(int NumbersArr[], int LowIndex, int HighIndex)
{
	/*Define Variables*/
	int PivotIndex = HighIndex;
	int Pivot = NumbersArr[HighIndex];
	
	/**/
	
	/*Recursive Case*/
	QuickSort(NumbersArr, LowIndex, PivotIndex - 1);
	QuickSort(NumbersArr, PivotIndex + 1, HighIndex);
}