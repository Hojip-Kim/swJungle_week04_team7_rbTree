// Created on iPad.

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int data;
  struct _node *next;
} node;

void insert(int, int, node **);
void print_list(node **);

void print_list(node **head)
{
  node *curr = *head;
  printf("[%p] head -> [%p]\n", &head, *head);
  if (curr == NULL)
  {
    printf("empty list\n");
    return;
  }
  while (curr)
  {
    printf("[%p] %4d -> [%p]\n", curr, curr->data, curr->next);
    curr = curr->next;
  }
  return;
}

void insert(int idx, int data, node **head)
{
  // create new node
  node *new = malloc(sizeof(node));
  new->data = data;
  new->next = NULL;

  // find first node
  node *curr = *head;
  if (curr == NULL)
  {
    // if empty list
    *head = new; // set new to
    return;
  }
  for (int i = 0; i < idx; i++)
  {
    curr = curr->next;
    if (curr == NULL)
    {
      printf("out of bound!\n");
      return;
    }
  }
  // find ith node
  node *tmp = curr->next;
  curr->next = new;
  new->next = tmp;
  return;
}

int main()
{
  // create empty pointet 'head'
  node **head;

  insert(0, 0, head);
  insert(0, 1, head);
  print_list(head);

  return 0;
}