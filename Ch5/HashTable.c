/*Needed libraries*/
#include <stdio.h>
#include <stdlib.h>

/*Functions' Prototypes*/
int Hash(int Key);
static void FixCapacity(void);
void InitializeHashTable(void);
void DisplayHashTable(void);
void InsertNode(int Key, int Value);
void RemoveNode(int Key);

/*Define Struct type for every node inside hash table*/
typedef struct Node
{
	int Key;
	int Value;
}
Node_t;

/*Define the pointer to the hash table*/
static Node_t *HashTable = NULL;

/*Define hash table variables*/
static int Capacity = 83;
static int Size = 0;


/*It is the main*/
int main()
{
	/*Define Variables*/
	int Choice;
	int Key;
	int Value;
	
	/*Hash Table Initialization*/
	InitializeHashTable();

	/*Program Super Loop*/
	while(1)
	{
		/*Scan the program choice from the user*/
		printf(	"1.Insert item in the Hash Table"
				"\n2.Remove item from the Hash Table"
				"\n3.Check the size of Hash Table"
				"\n4.Display a Hash Table"
				"\n5.Exit"
				"\n\nPlease enter your choice: ");
		scanf("%d", &Choice);
		
		printf("\n---------------------------\n");
		
		/*Excute the order according to the user choice*/
		if(Choice == 1)
		{
			/*Scan key and value from the user*/
			printf("Key: ");
			scanf("%d", &Key);
			printf("Value: ");
			scanf("%d", &Value);
			
			/*Insert the node*/
			InsertNode(Key, Value);
		}
		else if(Choice == 2)
		{
			/*Scan the key which needed to be removed*/
			printf("Key: ");
			scanf("%d", &Key);
			
			/*Remove the key*/
			RemoveNode(Key);
		}
		else if(Choice == 3)
		{
			/*Print the size to the user*/
			printf("Hash Table Size is: %d\n", Size);
		}
		else if(Choice == 4)
		{
			/*Print all the hash table elements to the user*/
			DisplayHashTable();		
		}
		else if(Choice == 5)
		{
			break;
		}
		else
		{
			printf("Invalid Input\n");
		}
		
		printf("---------------------------\n\n");
	}
	
	/*Return to the operating system*/
	return 0;
}

/*Functions' Implementation*/
static void FixCapacity(void)	// Function which force the capacity to be the nearest biggest prime number to the entered capacity.
{
	/*Define variables*/
	int PrimeFlag = 0;
	int i;
	
	/*If the capacity is odd number, change it to even number*/
	if((Capacity % 2) == 0)
	{
		Capacity++;
	}

	/*While the number is still not prime, continue to fix it*/
	do
	{
		/*Check if the number is prime or not*/
		if((Capacity == 0) || (Capacity == 1))
		{
			PrimeFlag = 0;
		}
		else
		{
			PrimeFlag = 1;
			
			for(i = 2; i <= (Capacity / 2); i++)
			{	
				if((Capacity % i) == 0)
				{
					PrimeFlag = 0;
					break;
				}
			}
		}
		
		/*If the number is prime, break the while loop*/
		if(PrimeFlag == 1)
		{
			/*Do nothing*/
		}
		/*Else increment it by 2 until we reached a prime number*/
		else
		{
			Capacity = Capacity + 2;
		}
	}
	while(PrimeFlag == 0);
}

void InitializeHashTable(void)
{
	/*Fix the capacity*/
	FixCapacity();
	
	/*Reserve number of nodes equal to the capacity*/
	HashTable = (Node_t *) malloc(Capacity * sizeof(Node_t));
	
	/*Initialize all keys and values by zero*/
	for (int i = 0; i < Capacity; i++)
	{
		HashTable[i].Key = 0;
		HashTable[i].Value = 0;
	}
}

void InsertNode(int Key, int Value)
{
	/*Get the hash index for the key*/
	int Index = Hash(Key);
	
	/*Validate the values received, as I reserved this condition (key(0) = 0) for the empty elements*/
	if(!((Key == 0) && (Value == 0)))
	{
		/*If the key is empty, insert the new node*/
		if((HashTable[Index].Key == 0) && (HashTable[Index].Value == 0))
		{
			HashTable[Index].Key = Key;
			HashTable[Index].Value = Value;
			Size++;
			printf("\nKey (%d) has been inserted\n", Key);
		}
		/*Else if the key is not empty, update its value with the new value*/
		else if(HashTable[Index].Key == Key)
		{
			HashTable[Index].Value = Value;
			printf("\nKey (%d) value has been updated\n", Key);
		}
		/*Else the key hash value is in collision with another reserved key, do nothing*/
		else
		{
			printf("\nCollision occured\n");
		}		
	}
	else
	{
		printf("\nKey and value you entered are reserved\n");
	}
}

void RemoveNode(int Key)
{
	/*Get the hash value for the key*/
	int Index = Hash(Key);

	/*If the key does not exist, tell the user*/
	if((HashTable[Index].Key == 0) && (HashTable[Index].Value == 0))
	{
		printf("\nThis key does not exist\n");
	}
	/*Else, remove the node from the hash table*/
	else
	{
		HashTable[Index].Key = 0;
		HashTable[Index].Value = 0;
		Size--;
		printf("\nKey (%d) has been removed\n", Key);
	}
}


void DisplayHashTable(void)
{
	/*Define variables*/
	int i = 0;
	
	/*If the size is zero, do not print it, else, print the hash table*/
	if(Size == 0)
	{
		printf("Hash Table is embty!\n");
	}
	else
	{
		/*Pass over all nodes, then if you find the node is not empty print its values*/
		for(i = 0; i < Capacity; i++)
		{
			if(!((HashTable[i].Key == 0) && (HashTable[i].Value == 0)))
			{
				printf("Key (%d) -> %d\n", HashTable[i].Key, HashTable[i].Value);			
			}
		}		
	}
}

int Hash(int Key)
{
	/*Return the value of the hash function of the key*/
	return (Key % Capacity);
}