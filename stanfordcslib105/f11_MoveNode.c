void MoveNode(struct node** destRef, struct node** sourceRef) {
  assert(*sourceRef != NULL);

  struct node *temp = *sourceRef;
  *sourceRef = (*sourceRef)->next; //Rearrange source

  temp->next = *destRef; //Move node
  *destRef = temp;
}
