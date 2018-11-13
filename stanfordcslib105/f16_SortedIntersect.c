/*
struct node* SortedIntersect(struct node *a, struct node (b) {
  struct node* newHead = NULL;
  while (a != NULL && b != NULL) {
    if ( a->data == b->data ) {
      PushTail(&newHead, a->data);
      a = a->next;
      b = b->next;
    }
    else if ( a->data > b->data) b = b->next;
    else a = a->next;
  }
  return newHead;
}
*/

//Local referance
struct node* SortedIntersect(struct node *a, struct node *b) {
  struct node *newHead = NULL;
  struct node **tailRef = &newHead;

  while (a != NULL && b != NULL) {
    if ( a->data == b->data ) {
      Push(tailRef, a->data);
      tailRef = &((*tailRef)->next);
      a = a->next, b = b->next;
    }
    else if ( a->data < b->data) a = a->next;
    else b = b->next;
  }
  return newHead;
}
