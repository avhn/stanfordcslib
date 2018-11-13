#include "f6_SortedInsert.c"
void InsertSort(struct node** headRef) {
  struct node *current = *headRef, *temp, *result = NULL;
  while (current != NULL) {
    temp = current->next;
    SortedInsert(&result, current);
    current = temp;
  }
  *headRef = result;
}
