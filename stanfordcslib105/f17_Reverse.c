/*
// a.k.a back-middle-front strategy
void Reverse(struct node **headRef) {
  assert(Length(*headRef) > 1);

  struct node *backPtr = NULL, *mainPtr = *headRef, *frontPtr = mainPtr->next;
  while (1){
    mainPtr->next = backPtr;
    if (frontPtr == NULL) break;
    backPtr = mainPtr;
    mainPtr = frontPtr;
    frontPtr = frontPtr->next;
  }
  *headRef = mainPtr;
}
*/

// Moving nodes
void Reverse(struct node **headRef) {
  assert(*headRef);

  struct node *result = 0, *current = *headRef;
  do {
    struct node *temp = current->next;
    current->next = result;
    result = current;
    current = temp;
  } while (current);
  *headRef = result;
}
