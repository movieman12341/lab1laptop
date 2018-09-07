#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	int position;

};

//function protos
int valueSort(const void *a, const void *b);
int removeDups(struct node * nArr, int nElements);

int main()
{
	printf("How many elements do you want?\n");
	int numElements;
	scanf("%d", &numElements);

	struct node *nodeArr = (struct node*) calloc(numElements, sizeof(struct node));

	int i = 0;
	for (; i < numElements; i++)
	{
		printf("Enter an integer\n");
		int num;
		scanf("%d", &num);
		nodeArr[i].value = num;
		nodeArr[i].position = i;
	}
	//initial value sort
	qsort((void*)nodeArr, numElements, sizeof(nodeArr[0]), valueSort);

	//after sorting
	printf("after sorting.\n\n");
	for (i = 0; i < numElements; i++)
	{
		printf("%d %d\n", nodeArr[i].value, nodeArr[i].position);
	}

	//remove extras
	int newNumElements = removeDups(nodeArr, numElements);
	printf("remove extras\n\n");
	for (i = 0; i < newNumElements; i++)
	{
		printf("%d %d\n", nodeArr[i].value, nodeArr[i].position);
	}



	free(nodeArr);
	nodeArr = NULL;
	return 0;
}

int valueSort(const void * a, const void * b)
{
	int l = ((struct node*) a)->value;
	int r = ((struct node*) b)->value;
	int value = l - r;

	if (value == 0)//both a and b are equal
	{
		return ((struct node*) a)->position - ((struct node*) b)->position;
	}
	else
		return value;
}


int removeDups(struct node * nArr, int nElements)
{
	/*int i = 0, j = 0, index = 0;
	
	for (; i < nElements-1; i++)
	{
		if (nElements == 1 || nElements == 0)//already sorted
			return;


		else if (nArr[i].value != nArr[i+1].value)//j value != value of last array element in correct position
		{
			
			break;
		}
		else
		{
			nArr[index].value = nArr[i].value;
			nArr[index].position = nArr[i].position;
			index++;
		}
		*/
	int i = 0, j = 1, index = 1;
	for (; i < nElements; i++)
	{
		if (nElements == 1 || nElements == 0)//already sorted
			return;


		else if (nArr[j].value != nArr[index].value)//j value != value of last array element in correct position
		{
			nArr[index].value = nArr[j].value;
			nArr[index].position = nArr[j].position;
			j++;
			index++;
		}
		else
		{
			j++;
			//i--;//keep state of next correct position
		}
		//return index;
	}
	//nArr[j++].value = nArr[nElements - 1].value;


	/*
	int val = nArr[0].value;
	int index = 0, i = 0;
	for (; i < nElements; i++)
	{
		if (nArr[i].value != nArr[i + 1].value)
		{
			val = nArr[i].value;
			int position = nArr[i].position;

			nArr[index].value = val;
			nArr[index].position = position;
			index++;
		}
	}

	return index;
	*/
	
}