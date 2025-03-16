#include <iostream>
#include <vector>
#include <algorithm>

// Declare global vectors to be used in the quicksort algorithm
std::vector<int> low(200000);
std::vector<int> high(200000);
std::vector<int> a(200000);

// Partition function to rearrange elements in vector 'a' based on values in vector 'b'
int part(std::vector<int>& a, std::vector<int>& b, int l, int r) {
  int i, j, x, t;

  i = l - 1;
  j = r;
  x = b[r];

  while (true) {
    while (b[++i] < x);
    while (i < --j && x < b[j]);

    if (i >= j) break;

    // Swap elements in vector 'a'
    t = a[i]; a[i] = a[j]; a[j] = t;
    // Swap elements in vector 'b'
    t = b[i]; b[i] = b[j]; b[j] = t;
  }

  // Swap elements in vector 'a' and 'b' to place pivot in the correct position
  t = a[i]; a[i] = a[r]; a[r] = t;
  t = b[i]; b[i] = b[r]; b[r] = t;
  return i;
}

// Quicksort function to sort vectors 'a' and 'b' based on values in vector 'b'
void quicksort(std::vector<int>& a, std::vector<int>& b, int n) {
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

    if (l >= r) continue;

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

int main() {
  int n, m;
  int i;
  std::vector<int> a(100006);
  std::vector<int> b(100006);
  int cnt = 0;
  int t;

  // Read the number of elements and the number of pairs
  std::cin >> n >> m;

  // Read the pairs of integers into vectors 'a' and 'b'
  for (i = 0; i < m; i++) std::cin >> a[i] >> b[i];

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
  std::cout << cnt << std::endl;

  return 0;
}
