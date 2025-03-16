#include <stdio.h>
#include <string.h>

// Declare global arrays to store data and sequences
int data[111111]; // Array to store the frequency of each number
int seq[222222];  // Array to store sequences of consecutive numbers

// Function to return the maximum of two integers
int max(int a, int b);

int main(void)
{
  int n, k, t, i, p, ret = 0;

  // Loop to read input values and process them
  while (1) {
    // Read values of n and k
    scanf("%d %d", &n, &k);
    if (!n && !k) break; // Break the loop if both n and k are zero

    // Initialize the data and seq arrays to zero
    memset(data, 0, sizeof(data));
    memset(seq, 0, sizeof(seq));

    // Read k numbers and store their frequencies in data
    for (i = 0; i < k; i++) {
      scanf("%d", &t);
      data[t]++;
    }

    // Construct the seq array based on the frequencies in data
    p = 0;
    for (i = 1; i <= n; i++) {
      if (data[i]) {
        seq[p]++;
      } else {
        p += 2;
      }
    }
    p++;

    // Calculate the maximum value of ret based on the sequences in seq
    if (data[0]) {
      for (i = 0; i < p; i++) {
        ret = max(ret, seq[i] + seq[i + 2] + 1);
      }
    } else {
      for (i = 0; i < p; i++) {
        ret = max(ret, seq[i]);
      }
    }

    // Print the result
    printf("%d\n", ret);
  }

  return 0;
}

// Function to return the maximum of two integers
int max(int a, int b)
{
  if (a > b) {
    return a;
  }
  return b;
}