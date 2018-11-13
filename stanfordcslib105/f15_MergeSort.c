void MergeSort(struct node **headRef) {
  if(*headRef == NULL || (*headRef)->next == NULL) return;

  struct node *a = NULL, *b = NULL;
  FrontBackSplit(*headRef, &a, &b);

  MergeSort(&a);
  MergeSort(&b);

  *headRef = SortedMerge(a,b);
}
