#include "lists.h"


/**
 * insert_node - frees a listint_t list
 * @head: pointer to list to be freed
 * @number: number to insert
 * Return: address of the new node or null if fail
 */
listint_t *insert_node(listint_t **head, int number)
{

	struct listint_s *temp = NULL;
	struct listint_s *new = NULL;


	new = (struct listint_s *)malloc(sizeof(struct listint_s));
	if (new == NULL || head == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	else
	{
		temp = *head;
		if (temp->n > new->n)
		{
			new->next = temp;
			*head = new;
			return (*head);
		}
		else
		{
			while (temp->next != NULL && temp->next->n < new->n)
			{
				temp = temp->next;
			}
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
	}
}
