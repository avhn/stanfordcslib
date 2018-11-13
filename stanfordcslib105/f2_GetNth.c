int GetNth(struct node* head, int index) {
  struct node* current = head;
  for (int i = 0; i < index; i++, current = current->next) assert(current != NULL);
  return current->data;
}
