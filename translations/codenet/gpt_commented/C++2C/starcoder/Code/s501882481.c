#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a string to string (identity function)
char* to_string(char* s) {
  return s;
}

// Template function to convert a pair to string representation
template <class S, class T>
char* to_string(S s, T t) {
  char* ret = (char*)malloc(100);
  sprintf(ret, "{%s,%s}", to_string(s), to_string(t));
  return ret;
}

// Template function to convert a vector to string representation
template <class T>
char* to_string(T* v) {
  char* ret = (char*)malloc(100);
  sprintf(ret, "{");
  for (int i = 0; i < sizeof(v) - 1; ++i) {
    sprintf(ret, "%s%s,", ret, to_string(v[i]));
  }
  if (sizeof(v) > 0) {
    sprintf(ret, "%s%s", ret, to_string(v[sizeof(v) - 1]));
  }
  sprintf(ret, "%s}", ret);
  return ret;
}

// Function to print a new line for debugging purposes
void debug() {
  printf("\n");
}

// Template function to print multiple values for debugging
template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  printf("%s ", to_string(head));
  debug(tail...);
}

// Function to print a new line
void print() {
  printf("\n");
}

// Template function to print multiple values to standard output
template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  printf("%s", to_string(head));
  print(tail...);
}

// Function to handle no input (base case for variadic template)
void get() {}

// Template function to read multiple values from standard input
template <class Head, class... Tail>
void get(Head* head, Tail*... tail) {
  scanf("%s", head);
  get(tail...);
}

// Template function to read values into a vector from standard input
template <class T>
void getv(T* vec) {
  for (int i = 0; i < sizeof(vec); ++i)
    scanf("%s", vec[i]);
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

