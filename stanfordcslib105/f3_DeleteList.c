int DeleteList(struct node** headRef) {
  /* Drags head to end of the list while deallocating */
  while (*headRef != NULL) {
    struct node* temp = *headRef;
    *headRef = (**headRef).next, free(temp);
  }
}
