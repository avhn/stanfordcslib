/*
void RecursiveReverse(struct node **headRef) {
  assert(*headRef); //Empty list case

  struct node *initial = *headRef, *rest = initial->next;
  if (rest == NULL) return; //End of list, last initial in stack is at (n-1)th node

  RecursiveReverse(&rest);
  *headRef = rest; //Final rest's value(last node's adress) is initialized via reference

  initial->next->next = initial; //Point back
  initial->next = NULL;
}
*/

void RecursiveReverse(struct node **headRef) {
  struct node *first = *headRef, *rest = first->next;
  if (rest == NULL) return;

  RecursiveReverse(&rest);

  first->next->next = first;
  first->next = NULL;

  *headRef = rest;
}
