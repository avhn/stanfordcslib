/*
void SortedInsert(struct node** headRef, struct node* newNode) {
  if (*headRef == NULL || newNode->data < (*headRef)->data) {
    newNode->next = *headRef;
    *headRef = newNode;
  } else {
    struct node* current = *headRef;
    while (current->next != NULL && current->next->data < newNode->data) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}
*/

void SortedInsert(struct node** headRef, struct node* newNode) {
  struct node** currRef = headRef;
  while (*currRef != NULL && (*currRef)->data < newNode->data) {
    currRef = &((*currRef)->next);
  }
  newNode->next = *currRef;
  *currRef = newNode;
}
