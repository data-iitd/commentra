
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Input struct and its methods for reading input
typedef struct {
  char *line;
  int line_size;
  int line_capacity;
} Input;

void input_init(Input *input) {
  input->line = NULL;
  input->line_size = 0;
  input->line_capacity = 0;
}

void input_free(Input *input) {
  free(input->line);
}

void input_read_line(Input *input) {
  int capacity = input->line_capacity;
  if (capacity <= input->line_size + 1) {
    capacity = (capacity + 1) * 2;
    input->line = realloc(input->line, capacity);
    if (input->line == NULL) {
      fprintf(stderr, "Error: Failed to reallocate memory\n");
      exit(1);
    }
    input->line_capacity = capacity;
  }
  if (fgets(input->line + input->line_size, input->line_capacity - input->line_size, stdin) == NULL) {
    fprintf(stderr, "Error: Failed to read from stdin\n");
    exit(1);
  }
  input->line_size += strlen(input->line + input->line_size);
}

char *input_next_line(Input *input) {
  if (input->line_size == 0) {
    input_read_line(input);
  }
  char *line = input->line;
  input->line += strcspn(input->line, "\n") + 1;
  input->line_size -= strcspn(line, "\n") + 1;
  return line;
}

int input_next_int(Input *input) {
  char *line = input_next_line(input);
  char *endptr;
  int value = strtol(line, &endptr, 10);
  if (endptr == line) {
    fprintf(stderr, "Error: Failed to read an integer from stdin\n");
    exit(1);
  }
  return value;
}

int *input_next_int_array(Input *input, int size) {
  int *array = malloc(size * sizeof(int));
  if (array == NULL) {
    fprintf(stderr, "Error: Failed to allocate memory\n");
    exit(1);
  }
  for (int i = 0; i < size; i++) {
    array[i] = input_next_int(input);
  }
  return array;
}

// Define the Input struct and its methods for reading input ends here

int main() {
  // Initialize the input reader
  Input input;
  input_init(&input);

  // Read the first integer from the input
  int n = input_next_int(&input);

  // Read the second integer array from the input
  int *s = input_next_int_array(&input, n);

  // Initialize a boolean slice of size n
  int *u = calloc(n, sizeof(int));

  // Initialize two integer variables m and f
  long long m = 0, f = 0;

  // Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
  for (int c = 1; c < n - 1; c++) {
    // Initialize a variable f to 0
    f = 0;

    // Iterate through all the subarrays of size c+1, where k ranges from 0 to n-1-c*c
    for (int k = 0; k < n - 1 - k * c; k++) {
      // Set the boolean value of the current index to true
      u[k * c] = 1;

      // Check if the boolean value of the last index of the current subarray is already set to true
      // If it is, break the inner loop as we don't need to check further
      if (u[n - 1 - k * c]) {
        break;
      }

      // Calculate the sum of the current and previous subarrays
      f += s[n - 1 - k * c] + s[k * c];

      // Update the value of m if the current sum is greater than the previous maximum sum
      if (m < f) {
        m = f;
      }

      // Set all the boolean values of the current subarray to false
    }

    // Iterate through all the indices of the current subarray and set their boolean values to false
    for (int k = 0; k * c < n - 1; k++) {
      u[k * c] = 0;
    }
  }

  // Print the maximum sum
  printf("%lld\n", m);

  // Free the memory allocated for the input reader
  input_free(&input);

  // Free the memory allocated for the boolean slice
  free(u);

  // Free the memory allocated for the integer array
  free(s);

  return 0;
}

