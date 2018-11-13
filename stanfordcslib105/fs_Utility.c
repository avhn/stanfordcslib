int Length(struct node* head) {
  int count = 0;
  for (struct node* current = head; current != NULL; current = current->next) count++;
  return count;
}

void Push(struct node** headRef, int newData) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->next = NULL, newNode->data = newData;

  newNode->next = *headRef;
  *headRef = newNode;
}

void PushTail(struct node** headRef, int newData) {
  struct node **tail = headRef;
  for(; *tail != NULL; tail = &((*tail)->next) );

  Push(tail, newData);
}

struct node* BuildOneTwoThree() {
  struct node* head = NULL;
  for (int i = 3; i > 0; i--) {
    Push(&head, i);
  }
  return head;
}

void ChangeToNull(struct node** headRef) {
  *headRef = NULL;
}

void PrintList(struct node* head) {
  for (struct node* current = head; current != NULL; current = current->next) printf("%d\t", current->data);
  puts("End of list.");
}
