#include <stdio.h>
#include <string.h>

// Macro definitions for convenience in loops and other operations
#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define MAX (1 << 29)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

// Type definitions for ease of use
typedef struct {
  int first;
  int second;
} Pi;
typedef long long ll;
const int INF = 1 << 28;

// Function to convert a string to string (identity function)
char *to_string(char *s) {
  return s;
}

// Template function to convert a pair to string representation
char *to_string(Pi p) {
  char *ret = malloc(sizeof(char) * 100);
  sprintf(ret, "{%d,%d}", p.first, p.second);
  return ret;
}

// Template function to convert a vector to string representation
char *to_string(int *v, int n) {
  char *ret = malloc(sizeof(char) * 100);
  sprintf(ret, "{");
  for (int i = 0; i < n - 1; ++i) {
    sprintf(ret, "%s%d,", ret, v[i]);
  }
  if (n > 0) {
    sprintf(ret, "%s%d", ret, v[n - 1]);
  }
  sprintf(ret, "%s}", ret);
  return ret;
}

// Function to print a new line for debugging purposes
void debug() {
  printf("\n");
}

// Template function to print multiple values for debugging
void debug(int line, char *head, ...) {
  printf("%d: %s ", line, head);
  va_list args;
  va_start(args, head);
  char *arg = va_arg(args, char *);
  while (arg != NULL) {
    printf("%s ", arg);
    arg = va_arg(args, char *);
  }
  va_end(args);
}

// Function to print a new line
void print() {
  printf("\n");
}

// Template function to print multiple values to standard output
void print(char *head, ...) {
  printf("%s", head);
  va_list args;
  va_start(args, head);
  char *arg = va_arg(args, char *);
  while (arg != NULL) {
    printf("%s", arg);
    arg = va_arg(args, char *);
  }
  va_end(args);
}

// Function to handle no input (base case for variadic template)
void get() {}

// Template function to read multiple values from standard input
void get(int *head, ...) {
  scanf("%d", head);
  va_list args;
  va_start(args, head);
  int *arg = va_arg(args, int *);
  while (arg != NULL) {
    scanf("%d", arg);
    arg = va_arg(args, int *);
  }
  va_end(args);
}

// Template function to read values into a vector from standard input
void getv(int *vec, int n) {
  for (int i = 0; i < n; ++i)
    scanf("%d", &vec[i]);
}

// Main function where the program execution begins
int main() {
  char S[100]; // Variable to store the input weather condition
  scanf("%s", S); // Read the weather condition from standard input

  // Determine the next weather condition based on the current one
  if (strcmp(S, "Sunny") == 0) {
    print("Cloudy"); // If it's sunny, print "Cloudy"
  } else if (strcmp(S, "Cloudy") == 0) {
    print("Rainy"); // If it's cloudy, print "Rainy"
  } else {
    print("Sunny"); // If it's neither, it must be rainy, print "Sunny"
  }

  return 0; // Return 0 to indicate successful execution
}
