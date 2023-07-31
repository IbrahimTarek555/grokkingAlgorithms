/*Needed libraries*/
#include <stdio.h>

/*Functions' prototype*/
void QuickSort(int NumbersArr[], int LowIndex, int HighIndex);

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
	QuickSort(NumbersArr, 0, 19);
	
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
	int Temp;
	
	/*If the sub array is still has more than one element*/
	if(LowIndex < HighIndex)
	{
		/*Define i which will carry the new index of pivot*/		
		int i = LowIndex;
		
		/*Pass over the sub array*/
		for(int j = LowIndex; j < HighIndex; j++)
		{
			/*move all elements that are lower than the pivot to the left of the pivot*/
			if(NumbersArr[j] <= Pivot)
			{
				/*Swap between element at i with element at j*/
				Temp = NumbersArr[i];
				NumbersArr[i] = NumbersArr[j];
				NumbersArr[j] = Temp;
				
				/*Increment i, as i is the pointer of the left side sub array*/
				i++;
			}
		}
		
		/*Move pivot from its old index to its new index*/
		Temp = NumbersArr[i];
		NumbersArr[i] = NumbersArr[PivotIndex];
		NumbersArr[PivotIndex] = Temp;
		
		/*Update the pivot index to call quick sort another time*/
		PivotIndex = i;
		
		/*Recursive Case*/
		QuickSort(NumbersArr, LowIndex, PivotIndex - 1);
		QuickSort(NumbersArr, PivotIndex + 1, HighIndex);
	}
}