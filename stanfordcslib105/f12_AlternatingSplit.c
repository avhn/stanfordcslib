/*void AlternatingSplit(struct node *source, struct node **aRef, struct node **bRef) {
  struct node *current = source;
  for (int i = 0; current != NULL; current = current->next, i++) {
    if (i%2 == 0) Push(aRef, current->data);
    else Push(bRef, current->data);
  }
}

*/
void AlternatingSplit(struct node *source, struct node **aRef, struct node **bRef) {
  assert(source != NULL);
  struct node *current = source;

  for(int i = 0; current != NULL; i++) {
    struct node *temp = current;
    current = current->next;

    if (i % 2 == 0) MoveNode(aRef, &temp );
    else MoveNode(bRef, &temp );
  }
}
