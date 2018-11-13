int Count(struct node* head, int searchFor) {
  int count = 0;
  for(struct node* current = head; current != NULL; current = current->next) if(current->data == searchFor) count++;
  return count;
}
