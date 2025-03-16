#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// FastReader class to read input efficiently
typedef struct FastReader
{
    char buffer[1000001];
    int bufferPointer, bytesRead;
    FILE *fp;
} FastReader;

// Utility function to initialize FastReader
void init(FastReader *reader, FILE *fp)
{
    reader->fp = fp;
    reader->bytesRead = 0;
    reader->bufferPointer = 0;
    fgets(reader->buffer, 1000000, fp);
}

// Utility function to check if the buffer is empty or not
bool isEmpty(FastReader *reader)
{
    return reader->bufferPointer >= reader->bytesRead;
}

// Utility function to read the next character from the stream
char readChar(FastReader *reader)
{
    if (isEmpty(reader))
    {
        return -1;
    }
    char c = reader->buffer[reader->bufferPointer++];
    if (c == '\n')
    {
        reader->bytesRead += 1;
        reader->bufferPointer = 0;
        fgets(reader->buffer, 1000000, reader->fp);
    }
    return c;
}

// Utility function to read the next word from the stream
char *readWord(FastReader *reader)
{
    if (isEmpty(reader))
    {
        return NULL;
    }
    char *word = malloc(1000001 * sizeof(char));
    int i = 0;
    char c = readChar(reader);
    while (c!= -1 && c!='' && c!= '\n')
    {
        word[i++] = c;
        c = readChar(reader);
    }
    word[i] = '\0';
    return word;
}

// Utility function to read the next line from the stream
char *readLine(FastReader *reader)
{
    if (isEmpty(reader))
    {
        return NULL;
    }
    char *line = malloc(1000001 * sizeof(char));
    int i = 0;
    char c = readChar(reader);
    while (c!= -1 && c!= '\n')
    {
        line[i++] = c;
        c = readChar(reader);
    }
    line[i] = '\0';
    return line;
}

// Utility function to read the next integer from the stream
int readInt(FastReader *reader)
{
    if (isEmpty(reader))
    {
        return -1;
    }
    int integer = 0;
    int isNegative = 1;
    char c = readChar(reader);
    if (c == '-')
    {
        isNegative = -1;
        c = readChar(reader);
    }
    while (c!= -1 && c!='' && c!= '\n')
    {
        integer = integer * 10 + (c - '0');
        c = readChar(reader);
    }
    return integer * isNegative;
}

// Utility function to read the next long from the stream
long readLong(FastReader *reader)
{
    if (isEmpty(reader))
    {
        return -1;
    }
    long integer = 0;
    int isNegative = 1;
    char c = readChar(reader);
    if (c == '-')
    {
        isNegative = -1;
        c = readChar(reader);
    }
    while (c!= -1 && c!='' && c!= '\n')
    {
        integer = integer * 10 + (c - '0');
        c = readChar(reader);
    }
    return integer * isNegative;
}

// Utility function to read the next double from the stream
double readDouble(FastReader *reader)
{
    if (isEmpty(reader))
    {
        return -1;
    }
    double integer = 0;
    int isNegative = 1;
    char c = readChar(reader);
    if (c == '-')
    {
        isNegative = -1;
        c = readChar(reader);
    }
    while (c!= -1 && c!='' && c!= '\n')
    {
        integer = integer * 10 + (c - '0');
        c = readChar(reader);
    }
    return integer * isNegative;
}

int main()
{
    FastReader reader;
    init(&reader, stdin);
    int n = readInt(&reader);
    int m = readInt(&reader);
    int answer = (n - 2) * 2;
    for (int i = 0; i < m; i++)
    {
        int r = readInt(&reader);
        if (r > 1 && r < n)
        {
            answer -= 1;
        }
        int c = readInt(&reader);
        if (c > 1 && c < n)
        {
            answer -= 1;
        }
    }
    if (n % 2!= 0)
    {
        int mid = (n + 1) / 2;
        if (answer > 0)
        {
            answer -= 1;
        }
    }
    printf("%d\n", answer);
    return 0;
}

