#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utility function to convert a string to a string representation.
char* to_string(char* s) {
  return s;
}

// Utility function to convert a pair to a string representation.
char* to_string(int a, int b) {
  char* ret = (char*)malloc(100 * sizeof(char));
  sprintf(ret, "{%d,%d}", a, b);
  return ret;
}

// Utility function to convert a vector to a string representation.
char* to_string(int* v, int n) {
  char* ret = (char*)malloc(100 * sizeof(char));
  sprintf(ret, "{");
  for (int i = 0; i < n - 1; ++i) {
    sprintf(ret, "%s%d,", ret, v[i]);
  }
  if (n > 0) {
    sprintf(ret, "%s%d}", ret, v[n - 1]);
  }
  return ret;
}

// Debug function to print a newline.
void debug() {
  printf("\n");
}

// Debug function to print debug information with a line number.
void debug(int line, char* head, ...) {
  printf("%d: ", line);
  va_list args;
  va_start(args, head);
  vprintf(head, args);
  va_end(args);
  printf(" ");
  debug();
}

// Print function to print a newline.
void print() {
  printf("\n");
}

// Print function to print multiple items.
void print(char* head, ...) {
  va_list args;
  va_start(args, head);
  vprintf(head, args);
  va_end(args);
  print();
}

// Utility function to read a single item.
void get() {}

// Utility function to read multiple items.
void get(int* head, ...) {
  scanf("%d", head);
  va_list args;
  va_start(args, head);
  get(args);
  va_end(args);
}

// Utility function to read a vector of items.
void getv(int* vec, int n) {
  for (int i = 0; i < n; ++i)
    scanf("%d", &vec[i]);
}

// Main function to execute the program.
int main() {
  char* S;
  scanf("%s", S);
  if (strcmp(S, "Sunny") == 0) {
    print("Cloudy");
  } else if (strcmp(S, "Cloudy") == 0) {
    print("Rainy");
  } else {
    print("Sunny");
  }
  return 0;
}

