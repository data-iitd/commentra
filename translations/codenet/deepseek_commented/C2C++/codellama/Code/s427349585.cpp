#include <iostream>
#include <cstring>

// Define the card structure
struct card {
  char s;
  int v;
};

// Define arrays for left and right subarrays
card L[100000/2+2], R[100000/2+2];

// Merge function to merge two subarrays
void me(card *a, int n, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l;
  int n2 = r - m;

  // Copy elements to left and right subarrays
  for (i = 0; i < n1; i++) L[i] = a[l + i];
  for (i = 0; i < n2; i++) R[i] = a[m + i];
  
  // Sentinel values to avoid checking for array boundaries
  L[n1].v = R[n2].v = 2000000000;
  
  i = 0;
  j = 0;
  
  // Merge the two subarrays back into the original array
  for (k = l; k < r; k++) {
    if (L[i].v <= R[j].v) {
      a[k] = L[i++];
    } else {
      a[k] = R[j++];
    }
  }
}

// Merge sort function to sort the array
void ms(card *a, int n, int l, int r) {
  int m;
  if (l + 1 < r) {
    m = (l + r) / 2;
    ms(a, n, l, m);
    ms(a, n, m, r);
    me(a, n, l, m, r);
  }
}

// Partition function to partition the array around a pivot
int partition(card *a, int n, int p, int r) {
  int i, j;
  card t, x;
  x = a[r];
  i = p - 1;
  for (j = p; j < r; j++) {
    if (a[j].v <= x.v) {
      i++;
      t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }
  t = a[i + 1];
  a[i + 1] = a[r];
  a[r] = t;
  return i + 1;
}

// Quick sort function to sort the array
void qs(card *a, int n, int p, int r) {
  int q;
  if (p < r) {
    q = partition(a, n, p, r);
    qs(a, n, p, q - 1);
    qs(a, n, q + 1, r);
  }
}

// Main function to read input, sort the arrays, check for stability, and print the result
int main() {
  int n, i, v;
  card a[200000], b[200000];
  char s[10];
  int stable = 1;

  // Read the number of cards
  scanf("%d", &n);

  // Read each card's suit and value
  for (i = 0; i < n; i++) {
    scanf("%s%d", s, &v);
    a[i].s = b[i].s = s[0];
    a[i].v = b[i].v = v;
  }

  // Sort the array using merge sort
  ms(a, n, 0, n);
  
  // Sort the array using quick sort
  qs(b, n, 0, n - 1);

  // Check if the sorting is stable
  for (i = 0; i < n; i++) {
    if (a[i].s != b[i].s) {
      stable = 0;
    }
  }

  // Print the stability status
  if (stable == 1) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  // Print the sorted array
  for (i = 0; i < n; i++) {
    printf("%c %d\n", b[i].s, b[i].v);
  }

  return 0;
}

