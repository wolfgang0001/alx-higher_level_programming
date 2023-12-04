#include "lists.h"

/**
 * is_palindrome - checking if  a singly linked list
 * is a palindrome
 * @head: pointer to head
 * Return: 0 if it is not a palindrome,
 * 1 if it is a palndrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *tortoise = *head, *hare = *head, *stack_top = NULL;
	listint_t *temp, *new_node;

	/* Traverse the linked list and push elements onto the stack */
	while (hare != NULL && hare->next != NULL)
	{
		/* Push the value onto the stack */
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (0);
		new_node->n = tortoise->n;
		new_node->next = stack_top;
		stack_top = new_node;
		tortoise = tortoise->next;
		hare = hare->next->next;
	}
	/* If the length of the linked list is odd, skip the middle element */
	if (hare != NULL)
		tortoise = tortoise->next;
	/* Traverse the remaining linked list and compare with the*/
	/* elements popped from the stack */
	while (tortoise != NULL)
	{
		/* Pop the value from the stack */
		if (stack_top == NULL || stack_top->n != tortoise->n)
			return (0);
		temp = stack_top;
		stack_top = stack_top->next;
		free(temp);
		tortoise = tortoise->next;
	}
	return (1);
}
