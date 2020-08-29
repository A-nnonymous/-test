#include<iostream>
#include"head.h"
using namespace std;
void main()
{
	/*-----------input testing part------------------------*/

	/*int* array;
	int length;
	int i;
	cout << "please input the length of your array" << endl;
	init_array(array, length);
	for (int i = 0; i < length; i++) {
		cout << "the" << i << "th item is" << array[i] << endl;
	}

	/*-----------input testing part------------------------*/

	/*-------------head insertion testing part_____________*/

	/*LNode* head, * current;
	int HI_length;
	HI_length = init_linklist_head(head);
	current = head->next;
	/*for (int i = 0; i < linside; i++)
	{
		cout << "the" << i << "th item is:" << current->data << endl;
		current = current->next;
	}
	linked_traverse_and_print(head, HI_length);

	/*-------------head insertion testing part_____________*/

	/*------------array merging test------------------------*/
	/*int a1[MAXSIZE], a2[MAXSIZE], c[2 * MAXSIZE];
	int l1, l2;
	init_array(a1, l1); init_array(a2, l2);
	array_mergingN(a1, l1, a2, l2, c);
	for (int i = 0; i < l1 + l2; i++)
	{
		cout << "The " << i << "th item is" << c[i] << endl;
	}
	/*------------array merging test------------------------*/

	/*--------------array piv parting test------------------*/
	int test_array[MAXSIZE]; int t_length;
	int piv_index;
	init_array(test_array, t_length);
	piv_index = piv_partingP(test_array, t_length, 0);
	for (int i = 0; i < t_length; i++)
	{
		cout << "The " << i << "th item is" << test_array[i] << endl;
	}
	cout << "The " << piv_index << " item is the piv" << endl;
	/*--------------array piv parting test------------------*/

	/*-------------linked list merging test--------------------*/
	/*LNode* llst1, * llst2, * output;
	int l1, l2;
	l1 = init_linklist_rear(llst1); l2 = init_linklist_rear(llst2);
	output = llst1;
	linked_mergeingN(llst1, l1, llst2, l2, output);
	linked_traverse_and_print(output);

	/*-------------linked list merging test--------------------*/
}