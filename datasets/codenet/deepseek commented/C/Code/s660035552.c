#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Declare global arrays to be used in the quicksort algorithm
int low[200000];
int high[200000];
int a[200000];

// Partition function to rearrange elements in array 'a' based on values in array 'b'
int part(int a[], int b[], int l, int r) {
  int i, j, x, t;

  i = l - 1;
  j = r;
  x = b[r];

  while (1) {
    while (b[++i] < x);
    while (i < --j && x < b[j]);

    if (i >= j) break;

    // Swap elements in array 'a'
    t = a[i]; a[i] = a[j]; a[j] = t;
    // Swap elements in array 'b'
    t = b[i]; b[i] = b[j]; b[j] = t;
  }

  // Swap elements in array 'a' and 'b' to place pivot in the correct position
  t = a[i]; a[i] = a[r]; a[r] = t;
  t = b[i]; b[i] = b[r]; b[r] = t;
  return i;
}

// Quicksort function to sort arrays 'a' and 'b' based on values in array 'b'
void quicksort(int a[], int b[], int n) {
  int l, r, v;
  int sp;

  // Initialize the stack with the first range to be sorted
  low[0] = 0;
  high[0] = n - 1;
  sp = 1;

  while (sp > 0) {
    sp--;
    l = low[sp];
    r = high[sp];

    if (l >= r);
    else {
      // Partition the array and get the pivot index
      v = part(a, b, l, r);

      // Push the sub-ranges onto the stack based on the pivot position
      if (v - l < r - v) {
        low[sp] = v + 1;
        high[sp++] = r;
        low[sp] = l;
        high[sp++] = v - 1;
      } else {
        low[sp] = l;
        high[sp++] = v - 1;
        low[sp] = v + 1;
        high[sp++] = r;
      }
    }
  }
}

int main() {
  int n, m;
  int i;
  int a[100006];
  int b[100006];
  int cnt = 0;
  int t;

  // Read the number of elements and the number of pairs
  scanf("%d %d", &n, &m);

  // Read the pairs of integers into arrays 'a' and 'b'
  for (i = 0; i < m; i++) scanf("%d %d", &a[i], &b[i]);

  // Sort the pairs using the quicksort function
  quicksort(a, b, m);

  // Count the number of unique intervals
  t = 0;
  for (i = 0; i < m; i++) {
    if (t <= a[i]) {
      t = b[i];
      cnt++;
    }
  }

  // Print the count of unique intervals
  printf("%d\n", cnt);

  return 0;
}
