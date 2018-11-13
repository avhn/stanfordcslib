int Pop(struct node** headRef) {
  assert(*headRef != NULL);
  struct node* head = *headRef;
  int data = head->data;

  *headRef = (*headRef)->next, free(head);
  return data;
}
