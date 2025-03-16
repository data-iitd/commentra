
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 1000000

typedef struct {
    char *buffer;
    int buffer_size;
    int input_size;
} InputBuffer;

InputBuffer *create_input_buffer() {
    InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
    input_buffer->buffer = (char *)malloc(MAX_INPUT_SIZE * sizeof(char));
    input_buffer->buffer_size = MAX_INPUT_SIZE;
    input_buffer->input_size = 0;
    return input_buffer;
}

void read_input(InputBuffer *input_buffer) {
    char *buffer = input_buffer->buffer;
    int buffer_size = input_buffer->buffer_size;
    int input_size = input_buffer->input_size;
    int i = 0;
    while (1) {
        int c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
        buffer[i] = c;
        i++;
        if (i == buffer_size) {
            buffer_size *= 2;
            buffer = (char *)realloc(buffer, buffer_size * sizeof(char));
        }
    }
    input_buffer->buffer = buffer;
    input_buffer->buffer_size = buffer_size;
    input_buffer->input_size = i;
}

int next_int(InputBuffer *input_buffer) {
    char *buffer = input_buffer->buffer;
    int input_size = input_buffer->input_size;
    int i = 0;
    while (buffer[i] != '\n' && i < input_size) {
        i++;
    }
    buffer[i] = '\0';
    int result = atoi(buffer);
    input_buffer->input_size = input_size - i - 1;
    return result;
}

int main() {
    InputBuffer *input_buffer = create_input_buffer();
    read_input(input_buffer);
    int n = next_int(input_buffer);
    int max = 0;
    while (n-- > 0) {
        int f = next_int(input_buffer);
        int t = next_int(input_buffer);
        if (max < f + t) {
            max = f + t;
        }
    }
    printf("%d\n", max);
    return 0;
}

