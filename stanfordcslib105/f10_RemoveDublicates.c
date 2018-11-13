void RemoveDublicates(struct node *head) {
  if (head == NULL) return;

  struct node *current = head;
  while (current->next != NULL) {
    if (current->data == current->next->data) {
      struct node* temp = current->next;
      current->next = current->next->next;
      free(temp);
    }
    else current = current->next;
  }
}
