#include<stdio.h>
struct node
{
	int data;
	struct node *next;
}typedef NODE;
int AddFirst(NODE ** first, int data)
{
	NODE *newNode = NULL;
	newNode = (NODE *)malloc(sizeof(NODE));
	if (newNode == NULL)
		return -1;
	newNode->data = data;
	newNode->next = NULL;
	if (*first == NULL)
		*first = newNode;
	else
	{
		newNode->next = *first;
		*first = newNode;
	}
}
int AddLoopInList(NODE *head)
{
	NODE *temp1 = head, *temp2 = head;
	int flag = 0;
	while (temp2->next !=NULL)
	{
		if (flag)
		{
			temp1 = temp1->next;
			flag = 0;
		}
		else
		{
			flag = 1;
		}
		temp2 = temp2->next;
	}
	temp2->next=temp1;
}
int CheckLoop(NODE *head)
{
	int isLoopExist = 0;
	NODE *temp1 = head, *temp2 = head;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
		if (temp2->next == NULL)
			break;
		if (temp1 == temp2)
		{
			isLoopExist = 1;
			break;
		}
		temp2 = temp2->next;
		temp1 = temp1->next;
	}
	return isLoopExist;
}
int deleteLoop(NODE *head)
{
	NODE *temp1 = head, *temp2 = head;
	if (CheckLoop(head))
	{
		
		while (temp2->next != temp1)
		{
			temp2 = temp2->next;
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		temp2->next = NULL;
	}
}
void main()
{
	NODE *head = NULL;
	int i = 0;
	for (i = 1; i < 10; i++)
	{
		AddFirst(&head, 10*i);
	}
	if (CheckLoop(head))
	{
		printf("Loop exist\n");
	}
	else
	{
		printf("Loop not exist\n");
	}
	AddLoopInList(head);
	if (CheckLoop(head))
	{
		printf("Loop exist\n");
	}
	else
	{
		printf("Loop not exist\n");
	}
	deleteLoop(head);
	if (CheckLoop(head))
	{
		printf("Loop exist\n");
	}
	else
	{
		printf("Loop not exist\n");
	}	
}
