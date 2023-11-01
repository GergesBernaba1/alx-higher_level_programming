#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle.
 * @list: A pointer to the head of the linked list.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list) {
    listint_t *tortoise = list;  /* Slow pointer */
    listint_t *hare = list;     /* Fast pointer */

    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;    /* Move the tortoise one step */
        hare = hare->next->next;     /* Move the hare two steps */

        if (tortoise == hare) {
            /* The tortoise and hare have met, indicating a cycle */
            return (1);
        }
    }

    /* If we reach the end of the list, there is no cycle */
    return (0);
}

