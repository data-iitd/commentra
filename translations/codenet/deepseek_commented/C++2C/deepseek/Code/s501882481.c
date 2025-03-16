#include <stdio.h>  // For C-style input/output operations.
#include <string.h> // For string operations.

#define FOR(i, N) for (int i = 0; i < N; i++)  // Loop from 0 to N-1.
#define FORIN(i, a, b) for (int i = a; i < b; i++)  // Loop from a to b-1.
#define ALL(x) x, x + (sizeof(x) / sizeof(*x))  // Get all elements of a container.
#define MOD 1000000007  // Define a constant modulo value.
#define MAX (1 << 29)  // Define a maximum value.

typedef struct {
  int first;
  int second;
} Pi;

typedef long long ll;  // Define a type alias for a long long integer.

const int INF = 1 << 28;  // Define a constant for infinity.

// Utility function to convert a string to a string representation.
char* to_string(char* s) {
  return s;
}

// Utility function to convert a pair to a string representation.
char* to_string_pair(Pi p) {
  static char buffer[50];
  sprintf(buffer, "{%d,%d}", p.first, p.second);
  return buffer;
}

// Utility function to convert a vector to a string representation.
char* to_string_vector(int* v, int size) {
  static char buffer[1000];
  buffer[0] = '{';
  for (int i = 0; i < size - 1; ++i) {
    strcat(buffer, to_string_pair((Pi){v[i], 0}));
    strcat(buffer, ",");
  }
  if (size > 0) {
    strcat(buffer, to_string_pair((Pi){v[size - 1], 0}));
  }
  strcat(buffer, "}");
  return buffer;
}

// Debug function to print a newline.
void debug() {
  printf("\n");
}

// Debug function to print debug information with a line number.
void debug_with_line(int line, char* format, ...) {
  static char buffer[1000];
  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  printf("%d: %s", line, buffer);
}

// Print function to print a newline.
void print() {
  printf("\n");
}

// Print function to print multiple items.
void print_with_items(char* format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
  print();
}

// Utility function to read a single item.
void get() {}

// Utility function to read multiple items.
void get(char* head, ...) {
  scanf("%s", head);
  get(head + strlen(head) + 1, head);
}

// Utility function to read a vector of items.
void getv(int* vec, int size) {
  for (int i = 0; i < size; ++i)
    scanf("%d", &vec[i]);
}

// Main function to execute the program.
int main() {
  char S[10];
  scanf("%s", S);
  if (strcmp(S, "Sunny") == 0) {
    print_with_items("Cloudy");
  } else if (strcmp(S, "Cloudy") == 0) {
    print_with_items("Rainy");
  } else {
    print_with_items("Sunny");
  }
  return 0;
}
