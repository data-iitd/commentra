
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  FILE *fp;
  char *buffer;
  int buffer_len;
  int buffer_ptr;
} Input;

Input input_init(FILE *fp) {
  Input i;
  i.fp = fp;
  i.buffer_len = 1000000;
  i.buffer = (char *)malloc(i.buffer_len);
  i.buffer_ptr = 0;
  return i;
}

void input_free(Input *i) {
  free(i->buffer);
}

char *input_next_line(Input *i) {
  int ch;
  int len = 0;
  while ((ch = fgetc(i->fp))!= '\n') {
    if (ch == EOF) { return NULL; }
    if (len == i->buffer_len) {
      i->buffer_len *= 2;
      i->buffer = (char *)realloc(i->buffer, i->buffer_len);
    }
    i->buffer[len++] = ch;
  }
  i->buffer[len] = '\0';
  return i->buffer;
}

int input_next_int(Input *i) {
  char *line = input_next_line(i);
  if (line == NULL) { return -1; }
  return atoi(line);
}

int *input_next_int_array(Input *i) {
  char *line = input_next_line(i);
  if (line == NULL) { return NULL; }
  char *token = strtok(line, " ");
  int *a = (int *)malloc(sizeof(int) * 1000000);
  int j = 0;
  while (token!= NULL) {
    a[j++] = atoi(token);
    token = strtok(NULL, " ");
  }
  return a;
}

int main() {
  FILE *fp = fopen("input.txt", "r");
  Input i = input_init(fp);
  int n = input_next_int(&i);
  int *s = input_next_int_array(&i);
  int *u = (int *)malloc(sizeof(int) * n);
  int c, k, m;
  long long f;
  for (c = 1; c < n - 1; c++) {
    f = 0;
    for (k = 0; c < n - 1 - k * c; k++) {
      u[k * c] = 1;
      if (u[n - 1 - k * c]) { break; }
      f += s[n - 1 - k * c] + s[k * c];
      if (m < f) { m = f; }
    }
    for (k = 0; k * c < n - 1; k++) { u[k * c] = 0; }
  }
  printf("%d\n", m);
  input_free(&i);
  free(s);
  free(u);
  fclose(fp);
  return 0;
}

