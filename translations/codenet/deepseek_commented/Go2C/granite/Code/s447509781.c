

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  FILE *file;
  char buffer[1000000];
  int position;
} Input;

Input input;

void initInput(FILE *file) {
  input.file = file;
  input.position = 0;
}

char *nextLine() {
  int length = 0;
  char *buffer = input.buffer;
  while (1) {
    int character = fgetc(input.file);
    if (character == '\n') {
      buffer[length] = '\0';
      input.position = 0;
      return buffer;
    } else {
      buffer[length] = character;
      length++;
      input.position++;
    }
  }
}

int nextInt() {
  char *line = nextLine();
  int number;
  sscanf(line, "%d", &number);
  return number;
}

int *nextIntArray() {
  char *line = nextLine();
  char *token = strtok(line, " ");
  int length = 0;
  while (token!= NULL) {
    length++;
    token = strtok(NULL, " ");
  }
  int *array = (int *)malloc(length * sizeof(int));
  token = strtok(line, " ");
  for (int i = 0; i < length; i++) {
    sscanf(token, "%d", &array[i]);
    token = strtok(NULL, " ");
  }
  return array;
}

int main() {
  FILE *file = fopen("input.txt", "r");
  initInput(file);
  int n = nextInt();
  int *s = nextIntArray();
  int length = n;
  int *u = (int *)malloc(length * sizeof(int));
  long long m = 0;
  long long f = 0;
  for (int c = 1; c < n - 1; c++) {
    f = 0;
    for (int k = 0; c < n - 1 - k * c; k++) {
      u[k * c] = 1;
      if (u[n - 1 - k * c]) {
        break;
      }
      f += s[n - 1 - k * c] + s[k * c];
      if (m < f) {
        m = f;
      }
    }
    for (int k = 0; k * c < n - 1; k++) {
      u[k * c] = 0;
    }
  }
  printf("%lld\n", m);
  fclose(file);
  return 0;
}

