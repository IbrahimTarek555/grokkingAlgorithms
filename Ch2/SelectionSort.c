/*Needed libraries*/
#include <stdio.h>

/*Functions' prototype*/
void SelectionSort(int NumbersArr[], int ArrSize);

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
	SelectionSort(NumbersArr, 20);
	
	/*Print the array elements after sorting*/
	for(int i = 0; i < 20; i++)
	{
		printf("Element %d is: %d\n", (i + 1), NumbersArr[i]);
	}

	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
void SelectionSort(int NumbersArr[], int ArrSize)
{
	/*Define Variables*/
	int i, j;
	int SmallestNumber;
	int SmallestNumberIndex;
	
	/*Loop over each element inside the array*/
	for(i = 0; i < ArrSize; i++)
	{
		/*make the element you stands on temporarily the smallest one*/
		SmallestNumber = NumbersArr[i];
		SmallestNumberIndex = i;
		
		/*Loop over the rest of the array and find the smallest number through it*/
		for(j = i + 1; j < ArrSize; j++)
		{
			if(NumbersArr[j] < SmallestNumber)
			{
				SmallestNumberIndex = j;
				SmallestNumber = NumbersArr[SmallestNumberIndex];
			}
		}
		
		/*Now, if you find an element smaller than the element you stands on, swap them*/
		if(SmallestNumberIndex != i)
		{
			NumbersArr[i] = NumbersArr[i] + NumbersArr[SmallestNumberIndex];
			NumbersArr[SmallestNumberIndex] = NumbersArr[i] - NumbersArr[SmallestNumberIndex];
			NumbersArr[i] = NumbersArr[i] - NumbersArr[SmallestNumberIndex];
		}
		
		/*Now with every iteration you put an element in its proper place*/
	}
}