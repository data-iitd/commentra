#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *buffer;
  int buffer_size;
  int buffer_pos;
} Input;

Input *Input_new(int buffer_size) {
  Input *input = (Input *)malloc(sizeof(Input));
  input->buffer = (char *)malloc(buffer_size);
  input->buffer_size = buffer_size;
  input->buffer_pos = 0;
  return input;
}

void Input_delete(Input *input) {
  free(input->buffer);
  free(input);
}

int Input_read_line(Input *input) {
  int buffer_pos = 0;
  int buffer_size = input->buffer_size;
  char *buffer = input->buffer;
  while (1) {
    int c = getchar();
    if (c == EOF) {
      buffer[buffer_pos] = '\0';
      input->buffer_pos = buffer_pos;
      return buffer_pos;
    }
    buffer[buffer_pos] = c;
    buffer_pos++;
    if (buffer_pos == buffer_size) {
      buffer_size *= 2;
      buffer = (char *)realloc(buffer,buffer_size);
      input->buffer = buffer;
      input->buffer_size = buffer_size;
    }
    if (c == '\n') {
      buffer[buffer_pos] = '\0';
      input->buffer_pos = buffer_pos;
      return buffer_pos;
    }
  }
}

int Input_next_int(Input *input) {
  int buffer_pos = input->buffer_pos;
  char *buffer = input->buffer;
  while (buffer[buffer_pos] != '\0' && buffer[buffer_pos] != '\n') {
    buffer_pos++;
  }
  buffer[buffer_pos] = '\0';
  input->buffer_pos = buffer_pos;
  return atoi(buffer);
}

int *Input_next_int_array(Input *input) {
  char *buffer = input->buffer;
  int buffer_pos = input->buffer_pos;
  while (buffer[buffer_pos] != '\0' && buffer[buffer_pos] != '\n') {
    buffer_pos++;
  }
  buffer[buffer_pos] = '\0';
  input->buffer_pos = buffer_pos;
  char *token = strtok(buffer," ");
  int *array = (int *)malloc(sizeof(int) * 1000000);
  int i = 0;
  while (token != NULL) {
    array[i] = atoi(token);
    i++;
    token = strtok(NULL," ");
  }
  return array;
}

int main() {
  Input *input = Input_new(1000000);
  int n = Input_next_int(input);
  int *s = Input_next_int_array(input);
  int *u = (int *)malloc(sizeof(int) * 1000000);
  int m = 0, f = 0;
  for (int c = 1; c < n - 1; c++) {
    f = 0;
    for (int k = 0; c < n - 1 - k * c; k++) {
      u[k * c] = 1;
      if (u[n - 1 - k * c]) { break; }
      f += s[n - 1 - k * c] + s[k * c];
      if (m < f) { m = f; }
    }
    for (int k = 0; k * c < n - 1; k++) { u[k * c] = 0; }
  }
  printf("%d\n",m);
  free(u);
  free(s);
  Input_delete(input);
  return 0;
}

