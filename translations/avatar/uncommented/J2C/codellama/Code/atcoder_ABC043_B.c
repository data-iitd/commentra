
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000000

typedef struct {
    char *buffer;
    int buffer_size;
    int buffer_index;
} LightScanner;

void light_scanner_init(LightScanner *scanner, FILE *input_stream) {
    scanner->buffer = (char *)malloc(MAX_INPUT_LENGTH * sizeof(char));
    scanner->buffer_size = fread(scanner->buffer, sizeof(char), MAX_INPUT_LENGTH, input_stream);
    scanner->buffer_index = 0;
}

char light_scanner_next_char(LightScanner *scanner) {
    if (scanner->buffer_index >= scanner->buffer_size) {
        return EOF;
    }
    return scanner->buffer[scanner->buffer_index++];
}

char *light_scanner_next_string(LightScanner *scanner) {
    char *string = (char *)malloc(MAX_INPUT_LENGTH * sizeof(char));
    int i = 0;
    char c;
    while ((c = light_scanner_next_char(scanner)) != EOF && c != '\n') {
        string[i++] = c;
    }
    string[i] = '\0';
    return string;
}

void light_scanner_free(LightScanner *scanner) {
    free(scanner->buffer);
}

typedef struct {
    char *buffer;
    int buffer_size;
    int buffer_index;
} LightWriter;

void light_writer_init(LightWriter *writer, FILE *output_stream) {
    writer->buffer = (char *)malloc(MAX_INPUT_LENGTH * sizeof(char));
    writer->buffer_size = 0;
    writer->buffer_index = 0;
}

void light_writer_write_char(LightWriter *writer, char c) {
    writer->buffer[writer->buffer_index++] = c;
    if (writer->buffer_index >= writer->buffer_size) {
        writer->buffer_size *= 2;
        writer->buffer = (char *)realloc(writer->buffer, writer->buffer_size * sizeof(char));
    }
}

void light_writer_write_string(LightWriter *writer, char *string) {
    int i = 0;
    while (string[i] != '\0') {
        light_writer_write_char(writer, string[i++]);
    }
}

void light_writer_write_newline(LightWriter *writer) {
    light_writer_write_char(writer, '\n');
}

void light_writer_flush(LightWriter *writer, FILE *output_stream) {
    fwrite(writer->buffer, sizeof(char), writer->buffer_index, output_stream);
    writer->buffer_index = 0;
}

void light_writer_free(LightWriter *writer) {
    free(writer->buffer);
}

typedef struct {
    char *buffer;
    int buffer_size;
    int buffer_index;
} LightBuffer;

void light_buffer_init(LightBuffer *buffer, int buffer_size) {
    buffer->buffer = (char *)malloc(buffer_size * sizeof(char));
    buffer->buffer_size = buffer_size;
    buffer->buffer_index = 0;
}

void light_buffer_write_char(LightBuffer *buffer, char c) {
    buffer->buffer[buffer->buffer_index++] = c;
    if (buffer->buffer_index >= buffer->buffer_size) {
        buffer->buffer_size *= 2;
        buffer->buffer = (char *)realloc(buffer->buffer, buffer->buffer_size * sizeof(char));
    }
}

void light_buffer_write_string(LightBuffer *buffer, char *string) {
    int i = 0;
    while (string[i] != '\0') {
        light_buffer_write_char(buffer, string[i++]);
    }
}

void light_buffer_write_newline(LightBuffer *buffer) {
    light_buffer_write_char(buffer, '\n');
}

void light_buffer_flush(LightBuffer *buffer, FILE *output_stream) {
    fwrite(buffer->buffer, sizeof(char), buffer->buffer_index, output_stream);
    buffer->buffer_index = 0;
}

void light_buffer_free(LightBuffer *buffer) {
    free(buffer->buffer);
}

typedef struct {
    LightScanner scanner;
    LightWriter writer;
    LightBuffer buffer;
} BUnhappyHackingABCEdit;

void b_unhappy_hacking_abc_edit_init(BUnhappyHackingABCEdit *solver, FILE *input_stream, FILE *output_stream) {
    light_scanner_init(&solver->scanner, input_stream);
    light_writer_init(&solver->writer, output_stream);
    light_buffer_init(&solver->buffer, MAX_INPUT_LENGTH);
}

void b_unhappy_hacking_abc_edit_solve(BUnhappyHackingABCEdit *solver) {
    char *s = light_scanner_next_string(&solver->scanner);
    int i = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case '0':
                light_buffer_write_char(&solver->buffer, '0');
                break;
            case '1':
                light_buffer_write_char(&solver->buffer, '1');
                break;
            case 'B':
                if (solver->buffer.buffer_index > 0) {
                    solver->buffer.buffer_index--;
                }
                break;
        }
        i++;
    }
    light_buffer_write_newline(&solver->buffer);
    light_buffer_flush(&solver->buffer, stdout);
}

void b_unhappy_hacking_abc_edit_free(BUnhappyHackingABCEdit *solver) {
    light_scanner_free(&solver->scanner);
    light_writer_free(&solver->writer);
    light_buffer_free(&solver->buffer);
}

int main() {
    BUnhappyHackingABCEdit solver;
    b_unhappy_hacking_abc_edit_init(&solver, stdin, stdout);
    b_unhappy_happy_hacking_abc_edit_solve(&solver);
    b_unhappy_happy_hacking_abc_edit_free(&solver);
    return 0;
}

