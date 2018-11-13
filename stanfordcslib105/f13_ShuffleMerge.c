// data is copied
struct node* ShuffleMerge(struct node *a, struct node *b) {
  struct node *newHead = NULL, *currA = a, *currB = b;
  struct node **tail = &newHead;

  while (currA != NULL || currB != NULL){
    if (currA != NULL) {
      Push(tail, currA->data);
      currA = currA->next, tail = &((**tail).next);
    }
    if(currB != NULL) {
      Push(tail, currB->data);
      currB = currB->next, tail = &((**tail).next);
    }
  }
  return newHead;
}

//parameters' data wasted, not referenced so not dereferenced as NULL to check, not my choice
/*
struct node* ShuffleMerge(struct node *a, struct node *b) {
  struct node *newNode = NULL;

  if(a == NULL) return b;
  else if(b == NULL) return a;
  else {
    struct node *recur = ShuffleMerge(a->next, b->next);

    newNode = a;
    a->next = b;
    b->next = recur;
  }
  return newNode;
}
*/
