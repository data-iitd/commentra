
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to read input from stdin
int read_int(void) {
  int n = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = (n * 10) + (c - '0');
    c = getchar();
  }
  return n;
}

// Function to print output to stdout
void print_int(int n) {
  printf("%d\n", n);
}

// Function to print output to stdout
void print_str(char *s) {
  printf("%s\n", s);
}

// Function to check if c is greater than b
bool is_greater(int c, int b) {
  return c > b;
}

// Function to check if a is greater than d
bool is_greater_2(int a, int d) {
  return a > d;
}

// Function to check if a is less than c
bool is_less(int a, int c) {
  return a < c;
}

// Function to check if a, b, c, and d are in sorted order
bool is_sorted(int a, int b, int c, int d) {
  return a <= b && b <= c && c <= d;
}

// Function to calculate the difference between the smaller and larger of b and d
int calculate_difference(int b, int d) {
  return (b < d)? (d - b) : (b - d);
}

// Function to sort the List in ascending order
void sort_list(int *l) {
  int i, j, temp;
  for (i = 0; i < 4; i++) {
    for (j = i + 1; j < 4; j++) {
      if (l[i] > l[j]) {
        temp = l[i];
        l[i] = l[j];
        l[j] = temp;
      }
    }
  }
}

// Function to calculate the difference between the second and third elements of the List
int calculate_difference_2(int *l) {
  return l[2] - l[1];
}

// Main function
int main(void) {
  // Read input integers a, b, c, and d
  int a = read_int();
  int b = read_int();
  int c = read_int();
  int d = read_int();

  // Check if c is greater than b
  if (is_greater(c, b)) {
    // If yes, print 0 and exit
    print_int(0);
    return 0;
  }

  // Check if a is greater than d
  if (is_greater_2(a, d)) {
    // If yes, print 0 and exit
    print_int(0);
    return 0;
  }

  // Check if a is less than c
  if (is_less(a, c)) {
    // If yes, calculate the difference between the smaller and larger of b and d
    int difference = calculate_difference(b, d);
    // Print the difference
    print_int(difference);
    return 0;
  }

  // If none of the above conditions are true, then a, b, c, and d are in sorted order
  if (is_sorted(a, b, c, d)) {
    // Create a List of integers a, b, c, and d
    int l[4] = {a, b, c, d};

    // Sort the List in ascending order
    sort_list(l);

    // Calculate the difference between the second and third elements of the List
    int difference = calculate_difference_2(l);

    // Print the difference
    print_int(difference);
  }

  return 0;
}

