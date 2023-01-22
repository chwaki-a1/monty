#include "monty.h"

/**
 * free_list - entry point
 *
 * Description: frees a linked list
 * @head: pointer to the first element in the list
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * free_op - entry point
 *
 * Description: frees the op structure
 */
void free_op(void)
{
	if (op.opcode)
		free(op.opcode);

	if (op.arg)
		free(op.arg);

	free_list(op.head);
	fclose(op.input);
}
