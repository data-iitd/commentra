
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  FILE *stream;
  char buffer[1000000];
  int position;
} Input;

Input input;

void initInput(FILE *stream) {
  input.stream = stream;
  input.position = 0;
}

char *nextLine() {
  int length = 0;
  char *buffer = input.buffer;
  while (1) {
    int character = fgetc(input.stream);
    if (character == '\n') {
      buffer[length] = '\0';
      input.position = 0;
      return buffer;
    } else {
      buffer[length] = character;
      length++;
      if (length == 1000000) {
        buffer[length - 1] = '\0';
        input.position = 0;
        return buffer;
      }
    }
  }
}

int nextInt() {
  char *token = NULL;
  char *buffer = nextLine();
  int number = strtol(buffer, &token, 10);
  input.position += token - buffer + 1;
  return number;
}

int *nextIntArray() {
  char *token = NULL;
  char *buffer = nextLine();
  int length = 0;
  int *array = NULL;
  while (1) {
    int number = strtol(buffer, &token, 10);
    if (token == buffer) {
      break;
    }
    array = (int *)realloc(array, sizeof(int) * (length + 1));
    array[length] = number;
    length++;
    buffer = token + 1;
  }
  input.position += token - buffer + 1;
  return array;
}

int main() {
  FILE *inputStream = fopen("input.txt", "r");
  FILE *outputStream = fopen("output.txt", "w");
  initInput(inputStream);
  int n = nextInt();
  int *s = nextIntArray();
  int length = n;
  int *used = (int *)malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++) {
    used[i] = 0;
  }
  long long maxSum = 0;
  long long currentSum = 0;
  for (int c = 1; c < length - 1; c++) {
    currentSum = 0;
    for (int k = 0; c < length - 1 - k * c; k++) {
      used[k * c] = 1;
      if (used[length - 1 - k * c]) {
        break;
      }
      currentSum += s[length - 1 - k * c] + s[k * c];
      if (maxSum < currentSum) {
        maxSum = currentSum;
      }
    }
    for (int k = 0; k * c < length - 1; k++) {
      used[k * c] = 0;
    }
  }
  fprintf(outputStream, "%lld\n", maxSum);
  fclose(inputStream);
  fclose(outputStream);
  return 0;
}

