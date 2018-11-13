int countTrees(int n) {
  /* 1 to Nth combinations */
  if (n <= 1) return 1;
  else {
    int sum = 0;
    for (int root = 1; root <= n; root++) {
      int right = countTrees(root-1);
      int left = countTrees(n-root);
      sum += right*left;
    }
    return sum;
  }
}
