void Append(struct node **aRef, struct node **bRef) {
  if (*aRef == NULL) *aRef = *bRef;
  else {
    struct node *current = *aRef;
    while (current->next != NULL) current = current->next;
    current->next = *bRef;
  }
  *bRef = NULL;
}
