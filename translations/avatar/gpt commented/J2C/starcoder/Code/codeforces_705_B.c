#include <stdio.h>
#include <stdlib.h>

// FastReader class to handle fast input
typedef struct FastReader
{
    char buffer[1000001];
    int pointer, length;
    char c;
    int has_number;
    int number;
    int has_string;
    char string[1000001];
    int string_length;
    int has_char;
    char character;
} FastReader;

// Function to read the next token from input
void read_next(FastReader *reader)
{
    reader->has_number = 0;
    reader->has_string = 0;
    reader->has_char = 0;
    reader->number = 0;
    reader->string_length = 0;
    reader->character = 0;
    while (1)
    {
        reader->pointer++;
        if (reader->pointer >= reader->length)
        {
            reader->pointer--;
            return;
        }
        reader->c = reader->buffer[reader->pointer];
        if (reader->c >= '0' && reader->c <= '9')
        {
            reader->has_number = 1;
            reader->number = reader->number * 10 + (reader->c - '0');
        }
        else if (reader->c >= 'A' && reader->c <= 'Z')
        {
            reader->has_string = 1;
            reader->string[reader->string_length++] = reader->c;
        }
        else if (reader->c >= 'a' && reader->c <= 'z')
        {
            reader->has_string = 1;
            reader->string[reader->string_length++] = reader->c;
        }
        else if (reader->c =='' || reader->c == '\n' || reader->c == '\t' || reader->c == '\r')
        {
            if (reader->has_number)
            {
                reader->pointer--;
                return;
            }
        }
        else
        {
            reader->has_char = 1;
            reader->character = reader->c;
            reader->pointer--;
            return;
        }
    }
}

// Function to read the next integer from input
int read_int(FastReader *reader)
{
    read_next(reader);
    if (reader->has_number)
    {
        return reader->number;
    }
    else
    {
        return 0;
    }
}

// Function to read the next long from input
long read_long(FastReader *reader)
{
    read_next(reader);
    if (reader->has_number)
    {
        return reader->number;
    }
    else
    {
        return 0;
    }
}

// Function to read the next double from input
double read_double(FastReader *reader)
{
    read_next(reader);
    if (reader->has_number)
    {
        return reader->number;
    }
    else
    {
        return 0;
    }
}

// Function to read the next line from input
char *read_line(FastReader *reader)
{
    read_next(reader);
    if (reader->has_string)
    {
        return reader->string;
    }
    else
    {
        return 0;
    }
}

// Function to read the next character from input
char read_char(FastReader *reader)
{
    read_next(reader);
    if (reader->has_char)
    {
        return reader->character;
    }
    else
    {
        return 0;
    }
}

// Function to initialize FastReader
FastReader *init_reader(char *file_name)
{
    FastReader *reader = (FastReader *)malloc(sizeof(FastReader));
    FILE *file = fopen(file_name, "r");
    reader->pointer = 0;
    reader->length = 0;
    reader->c = 0;
    reader->has_number = 0;
    reader->number = 0;
    reader->has_string = 0;
    reader->string_length = 0;
    reader->has_char = 0;
    reader->character = 0;
    fseek(file, 0, SEEK_END);
    reader->length = ftell(file);
    fseek(file, 0, SEEK_SET);
    fread(reader->buffer, 1, reader->length, file);
    fclose(file);
    return reader;
}

// Function to free FastReader
void free_reader(FastReader *reader)
{
    free(reader);
}

// Function to solve the problem
void solve()
{
    // Read the number of elements in the array
    int t = read_int(reader);
    int arr[t];
    
    // Populate the array with input values
    for (int i = 0; i < t; i++)
    {
        arr[i] = read_int(reader);
    }
    
    int prev_winner = 0; // Variable to track the previous winner
    
    // Iterate through the array to determine the winner for each element
    for (int i = 0; i < t; i++)
    {
        // Check if the current element is 1
        if (arr[i] == 1)
        {
            // If the previous winner is 0, set the previous winner to 2
            if (prev_winner == 0)
            {
                prev_winner = 2;
            }
        }
        
        // Determine the winner based on the previous winner and the current element
        if (prev_winner == 2 || prev_winner == 0)
        {
            // If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0)
            {
                printf("2\n"); // Print winner 2
                prev_winner = 2; // Update previous winner
            }
            else
            {
                printf("1\n"); // Print winner 1
                prev_winner = 1; // Update previous winner
            }
        }
        else
        {
            // If the previous winner is 1, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0)
            {
                printf("1\n"); // Print winner 1
                prev_winner = 1; // Update previous winner
            }
            else
            {
                printf("2\n"); // Print winner 2
                prev_winner = 2; // Update previous winner
            }
        }
    }
}

// Main function
int main()
{
    // Initialize FastReader
    reader = init_reader("input.txt");
    
    // Solve the problem
    solve();
    
    // Free FastReader
    free_reader(reader);
    
    return 0;
}

