void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef) {
  int len = Length(source);
  *frontRef = source;

  if (len < 2) return;
  else {
  int frontend = (len % 2 == 0)? len/2: len/2 + 1;

  struct node* current = source;
  for(int i = 1; i < frontend; current = current->next, i++);
  *backRef = current->next, current->next = NULL; //Cut the lists
  }
}
