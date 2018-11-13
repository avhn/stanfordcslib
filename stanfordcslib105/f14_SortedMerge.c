/*
struct node* SortedMerge(struct node *a, struct node *b) {
  struct node *newHead = NULL, *temp;

  while (a != NULL || b != NULL) {
    if (a != NULL) {
      temp = a, a = a->next;
      SortedInsert(&newHead, temp);
    }
    if (b != NULL) {
      temp = b, b = b->next;
      SortedInsert(&newHead, temp);
    }
  }
  return newHead;
}
*/

/*
//Local Reference
struct node* SortedMerge(struct node *a, struct node *b) {
  struct node *newHead = NULL;
  struct node **lastRef = &newHead;

  while (1) {
    if ( a == NULL ) {
      *lastRef = b;
      break;
    }
    else if ( b == NULL ){
      *lastRef = a;
      break;
    }

    if ( a->data >= b->data ) *lastRef = b, b = b->next, (*lastRef)->next = NULL;
    else *lastRef = a, a = a->next, (*lastRef)->next = NULL;
    lastRef = &((*lastRef)->next);
  }
  return newHead;
}
*/

 //Recursion
struct node* SortedMerge(struct node *a, struct node *b) {
  if ( a == NULL ) return b;
  else if ( b == NULL ) return a;

  struct node *newHead = NULL;
  if ( a->data <= b->data) {
    newHead = a;
    newHead->next = SortedMerge(a->next, b);
  } else {
    newHead = b;
    newHead->next = SortedMerge(a, b->next);
  }
  return newHead;
}
