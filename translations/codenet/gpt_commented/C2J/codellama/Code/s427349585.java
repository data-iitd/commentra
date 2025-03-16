#include <stdio.h>

// Define a structure to represent a card with a character and an integer value
typedef struct {
  char s; // Character representing the card's suit or type
  int v;  // Integer representing the card's value
} card;

// Arrays to hold the left and right halves during merge sort
card L[100000/2+2], R[100000/2+2];

// Merge function to combine two sorted halves of the array
void me(card *a, int n, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l; // Size of the left half
  int n2 = r - m; // Size of the right half

  // Copy data to temporary arrays L and R
  for (i = 0; i < n1; i++) L[i] = a[l + i];
  for (i = 0; i < n2; i++) R[i] = a[m + i];

  // Sentinel values to avoid out-of-bounds access
  L[n1].v = R[n2].v = 2000000000;

  // Merge the temporary arrays back into the original array
  i = 0; // Index for left array
  j = 0; // Index for right array
  for (k = l; k < r; k++) {
    if (L[i].v <= R[j].v) {
      a[k] = L[i++]; // Take from left if it's smaller or equal
    } else {
      a[k] = R[j++]; // Take from right otherwise
    }
  }
}

// Merge sort function to recursively sort the array
void ms(card *a, int n, int l, int r) {
  int m;
  if (l + 1 < r) { // Base case: if the segment has more than one element
    m = (l + r) / 2; // Find the midpoint
    ms(a, n, l, m); // Sort the left half
    ms(a, n, m, r); // Sort the right half
    me(a, n, l, m, r); // Merge the sorted halves
  }
}

// Partition function for quicksort
int partiton(card *a, int n, int p, int r) {
  int i, j;
  card t, x;
  x = a[r]; // Choose the last element as the pivot
  i = p - 1; // Index of smaller element
  for (j = p; j < r; j++) {
    if (a[j].v <= x.v) { // If current element is smaller than or equal to pivot
      i++; // Increment index of smaller element
      // Swap elements
      t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }
  // Swap the pivot element with the element at i + 1
  t = a[i + 1];
  a[i + 1] = a[r];
  a[r] = t;
  return i + 1; // Return the partitioning index
}

// Quicksort function to recursively sort the array
void qs(card *a, int n, int p, int r) {
  int q;
  if (p < r) { // Base case: if the segment has more than one element
    q = partiton(a, n, p, r); // Partition the array
    qs(a, n, p, q - 1); // Recursively sort the left half
    qs(a, n, q + 1, r); // Recursively sort the right half
  }
}

// Main function
int main() {
  int n, i, v;
  card a[200000], b[200000]; // Arrays to hold the cards for sorting
  char s[10]; // Temporary storage for the character input
  int stable = 1; // Flag to check if the sorting is stable

  // Read the number of cards
  scanf("%d", &n);

  // Read the cards into both arrays a and b
  for (i = 0; i < n; i++) {
    scanf("%s%d", s, &v);
    a[i].s = b[i].s = s[0]; // Store the character
    a[i].v = b[i].v = v; // Store the value
  }

  // Perform merge sort on array a
  ms(a, n, 0, n);
  // Perform quicksort on array b
  qs(b, n, 0, n - 1);

  // Check if the sorting is stable by comparing the original and sorted arrays
  for (i = 0; i < n; i++) {
    if (a[i].s != b[i].s) {
      stable = 0; // If any character differs, it's not stable
    }
  }

  // Output the stability result
  if (stable == 1) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }

  // Print the sorted array
  for (i = 0; i < n; i++) {
    printf("%c %d\n", b[i].s, b[i].v);
  }

  return 0; // Return success
}

