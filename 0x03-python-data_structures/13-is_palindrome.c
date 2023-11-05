#include "lists.h"
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *prev_slow, *second_half, *mid_node;
    int is_palindrome = 1;
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    slow = *head;
    fast = *head;
    prev_slow = *head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }
    if (fast != NULL)
    {
        mid_node = slow;
        slow = slow->next;
    }
    second_half = slow;
    prev_slow->next = NULL;
    reverse_list(&second_half);
    is_palindrome = compare_lists(*head, second_half);
    reverse_list(&second_half);

    if (mid_node != NULL)
    {
        prev_slow->next = mid_node;
        mid_node->next = second_half;
    }
    else
    {
        prev_slow->next = second_half;
    }
    return is_palindrome;
}
void reverse_list(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
int compare_lists(listint_t *head1, listint_t *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->n != head2->n)
            return (0);

        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}
