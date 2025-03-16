#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *buffer;
  int length;
  int size;
} Input;

void initInput(Input *input, FILE *fp) {
  input->buffer = NULL;
  input->length = 0;
  input->size = 0;
  char c;
  while(fscanf(fp,"%c",&c)!= EOF) {
    if(input->length == input->size) {
      input->size += 1000000;
      input->buffer = realloc(input->buffer,input->size);
    }
    input->buffer[input->length] = c;
    input->length++;
  }
}

void freeInput(Input *input) {
  free(input->buffer);
}

char *getNextLine(Input *input) {
  char *buffer = input->buffer;
  int length = input->length;
  input->length = 0;
  return buffer;
}

int getNextInt(Input *input) {
  char *buffer = getNextLine(input);
  int n = atoi(buffer);
  return n;
}

int64_t *getNextIntArray(Input *input) {
  char *buffer = getNextLine(input);
  char **tokens = NULL;
  int count = 0;
  int64_t *a = NULL;
  tokens = malloc(sizeof(char*)*100);
  for(int i=0;i<100;i++) { tokens[i] = NULL; }
  char *token = strtok(buffer," ");
  while(token!= NULL) {
    tokens[count] = token;
    count++;
    token = strtok(NULL," ");
  }
  a = malloc(sizeof(int64_t)*count);
  for(int i=0;i<count;i++) { a[i] = atoi(tokens[i]); }
  free(tokens);
  return a;
}

int main() {
  Input input;
  initInput(&input,stdin);
  int n = getNextInt(&input);
  int64_t *s = getNextIntArray(&input);
  int64_t *u = malloc(sizeof(int64_t)*n);
  int64_t m = 0;
  int64_t f = 0;
  for(int c=1;c<n-1;c++) {
    f = 0;
    for(int k=0;c<n-1-k*c;k++) {
      u[k*c] = 1;
      if(u[n-1-k*c]) { break; }
      f += s[n-1-k*c]+s[k*c];
      if(m < f) { m = f; }
    }
    for(int k=0;k*c<n-1;k++) { u[k*c] = 0; }
  }
  printf("%ld\n",m);
  free(u);
  free(s);
  freeInput(&input);
}
