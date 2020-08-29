#pragma once
#include<iostream>
#define MAXSIZE 10
using namespace std;
/*------------------node defining---------------------*/
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

/*----------array-------------------------------------*/
int init_array(int array[], int& length)
{
	cout << "input the array length:";
	cin >> length;
	if (length > MAXSIZE) {
		return 0;
	}
	for (int i = 0; i < length; i++)
	{
		cout << "please input the" << i << "th item:"; cin >> array[i];
	}
	return 1;
}

/*-----------merging--------------*/
void array_mergingP(int a1[], int l1, int a2[], int l2, int output[])
{
	int i = 0, j = 0, k = 0;
	while (i < l1 && j < l2)
	{
		if (a1[i] < a2[j])
		{
			output[k++] = a1[i++];
		}
		else
		{
			output[k++] = a2[j++];
		}
	}
	while (i < l1)
	{
		output[k++] = a1[i++];
	}
	while (j < l2)
	{
		output[k++] = a2[j++];
	}
}

void array_mergingN(int a1[], int l1, int a2[], int l2, int output[])
{
	int i = 0, j = 0, k = l1 + l2 - 1;
	while (i < l1 && j < l2)
	{
		if (a1[i] < a2[j])
		{
			output[k--] = a1[i++];
		}
		else
		{
			output[k--] = a2[j++];
		}
	}
	while (i < l1)
	{
		output[k--] = a1[i++];
	}
	while (j < l2)
	{
		output[k--] = a2[j++];
	}
}

/*-----------piv parting----------*/

int piv_partingP(int array[], int length, int piv_position)
{
	if (length > MAXSIZE)return 0;
	int temp;
	int left = 0, right = length - 1;
	temp = array[0];
	array[0] = array[piv_position];
	array[piv_position] = temp;
	temp = array[0];

	while (left < right)
	{
		while (left<right && array[right]>temp)right--;
		if (left < right)
		{
			array[left++] = array[right];
		}
		while (left < right && array[left] < temp)left++;
		if (left < right)
		{
			array[right--] = array[left];
		}
	}
	array[left] = temp;
	return left;
}

/*-------------linked list----------------------------*/
int init_linklist_rear(LNode*& head)
{
	head = (LNode*)malloc(sizeof(LNode));
	int n;
	LNode* front, * behind;
	front = head;
	cout << "input link`s length:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		behind = (LNode*)malloc(sizeof(LNode));
		behind->next = NULL;
		cout << "input the " << i << "th item:"; cin >> behind->data;
		front->next = behind;
		front = behind;
	}
	return n;
}

int init_linklist_head(LNode*& head)
{
	head = (LNode*)malloc(sizeof(LNode));
	int n;
	LNode* insert;
	head->next = NULL;
	cout << "input link`s length:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		insert = (LNode*)malloc(sizeof(LNode));
		insert->next = head->next;
		cout << "input the " << i << "th item:"; cin >> insert->data;
		head->next = insert;
	}
	return n;
}

/*-----------merging--------------*/
void linked_mergeingP(LNode* llst1, int l1, LNode* llst2, int l2, LNode*& output)
{
	LNode* p, * q, * r;
	p = llst1->next; q = llst2->next;
	r = llst1; r->next = NULL; free(llst2);
	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			r->next = p; p = p->next; r = r->next;
		}
		else
		{
			r->next = q; q = q->next; r = r->next;
		}
	}
	if (p != NULL)r->next = p;
	if (q != NULL)r->next = q;
}

void linked_mergeingN(LNode* llst1, int l1, LNode* llst2, int l2, LNode*& output)
{
	LNode* p, * q, * newhead, * insertion;
	p = llst1->next; q = llst2->next;
	newhead = llst1; newhead->next = NULL; free(llst2);
	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			insertion = p; p = p->next;
			insertion->next = newhead->next;
			newhead->next = insertion;
		}
		else
		{
			insertion = q; q = q->next;
			insertion->next = newhead->next;
			newhead->next = insertion;
		}
	}
	while (p != NULL)
	{
		insertion = p; p = p->next;
		insertion->next = newhead->next;
		newhead->next = insertion;
	}
	while (q != NULL)
	{
		insertion = q; q = q->next;
		insertion->next = newhead->next;
		newhead->next = insertion;
	}
}

/*-----------traversing-----------*/
void linked_traverse_and_print(LNode* head)
{
	LNode* current_item = head;
	int i = 0;
	while (current_item->next != NULL) {
		cout << "The " << i << "th item`s data is:" << current_item->next->data << endl;
		i++; current_item = current_item->next;
	}
}
