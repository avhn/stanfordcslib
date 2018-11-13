/*
void InsertNth(struct node** headRef, int index, int data) {
  // index is array representation

  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = data, newNode->next = NULL;

  struct node* current = *headRef;
  for (int i = 1; i < index; i++) { // current = index-1
    current = current->next;
    assert(current != NULL);
  }

  if (index == 0) newNode->next = current, current = newNode;
  else {
    newNode->next = current->next;
    current->next = newNode;
  }
}
*/

void InsertNth(struct node** headRef, int index, int data) {
  if (index == 0) Push(headRef, data);
  else {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data, newNode->next = NULL;

    struct node *current = *headRef;
    for(int i = 1; i < index; current = current->next, i++) assert(current != NULL);
    assert(current != NULL), Push(&(current->next), data);
  }
}
