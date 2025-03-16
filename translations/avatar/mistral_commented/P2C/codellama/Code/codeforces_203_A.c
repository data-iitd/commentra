#######
# Code
#######

# Include the header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main function
int main()
{
    // Declare the variables
    int x, t, a, b, da, db;
    int a_time, b_time;
    int i, j;
    char *ff;

    // Input the string of numbers separated by spaces and split it into a list
    char *xxs = malloc(100 * sizeof(char));
    scanf("%s", xxs);
    char *token = strtok(xxs, " ");
    x = atoi(token);
    token = strtok(NULL, " ");
    t = atoi(token);
    token = strtok(NULL, " ");
    a = atoi(token);
    token = strtok(NULL, " ");
    b = atoi(token);
    token = strtok(NULL, " ");
    da = atoi(token);
    token = strtok(NULL, " ");
    db = atoi(token);

    // Define the main function to perform the logic of the program
    ff = main_function(x, t, a, b, da, db);

    // If the result is "Result Not Found", print "NO"
    if (strcmp(ff, "Result Not Found") == 0)
    {
        printf("NO\n");
    }

    // Free the memory allocated to xxs
    free(xxs);

    // Return 0
    return 0;
}

// Define the main function
char *main_function(int x, int t, int a, int b, int da, int db)
{
    // Declare the variables
    int a_time, b_time;
    int i, j;

    // Check if x is equal to zero
    if (x == 0)
    {
        // If yes, print "YES" and return
        printf("YES\n");
        return "Result Found";
    }

    // Calculate the minimum time it takes for a and b to reach x
    a_time = min(a / da, t - 1);
    b_time = min(b / db, t - 1);

    // Loop through all possible combinations of a_time and b_time
    for (i = 0; i <= a_time; i++)
    {
        for (j = 0; j <= b_time; j++)
        {
            // Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if (a - da * i == x || b - db * j == x)
            {
                // If yes, print "YES" and return
                printf("YES\n");
                return "Result Found";
            }

            // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if ((a - da * i) + (b - db * j) == x)
            {
                // If yes, print "YES" and return
                printf("YES\n");
                return "Result Found";
            }
        }
    }

    // Return "Result Not Found"
    return "Result Not Found";
}

// Define the min function
int min(int a, int b)
{
    // Return the minimum of a and b
    return a < b ? a : b;
}

// Define the atoi function
int atoi(char *str)
{
    // Declare the variables
    int i, num;

    // Initialize the number to zero
    num = 0;

    // Loop through the string
    for (i = 0; str[i] != '\0'; i++)
    {
        // Check if the character is a digit
        if (str[i] >= '0' && str[i] <= '9')
        {
            // If yes, multiply the number by ten and add the digit
            num = num * 10 + (str[i] - '0');
        }
    }

    // Return the number
    return num;
}

// Define the strcmp function
int strcmp(char *str1, char *str2)
{
    // Declare the variables
    int i;

    // Loop through the strings
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        // Check if the characters are not equal
        if (str1[i] != str2[i])
        {
            // If yes, return the difference between the characters
            return str1[i] - str2[i];
        }
    }

    // Return the difference between the lengths of the strings
    return strlen(str1) - strlen(str2);
}

// Define the strlen function
int strlen(char *str)
{
    // Declare the variables
    int i;

    // Initialize the length to zero
    i = 0;

    // Loop through the string
    while (str[i] != '\0')
    {
        // Increment the length
        i++;
    }

    // Return the length
    return i;
}

// Define the strtok function
char *strtok(char *str, char *delim)
{
    // Declare the variables
    int i, j;

    // Loop through the string
    for (i = 0; str[i] != '\0'; i++)
    {
        // Loop through the delimiter
        for (j = 0; delim[j] != '\0'; j++)
        {
            // Check if the character is a delimiter
            if (str[i] == delim[j])
            {
                // If yes, replace it with a null character
                str[i] = '\0';
            }
        }
    }

    // Return the string
    return str;
}

// Define the malloc function
void *malloc(int size)
{
    // Declare the variables
    int i;

    // Loop through the memory
    for (i = 0; i < size; i++)
    {
        // Check if the memory is available
        if (memory[i] == 0)
        {
            // If yes, allocate the memory
            memory[i] = 1;

            // Return the memory
            return &memory[i];
        }
    }

    // Return NULL if the memory is not available
    return NULL;
}

// Define the free function
void free(void *ptr)
{
    // Declare the variables
    int i;

    // Loop through the memory
    for (i = 0; i < 100; i++)
    {
        // Check if the memory is allocated
        if (memory[i] == 1)
        {
            // If yes, free the memory
            memory[i] = 0;
        }
    }
}

// Define the memory
int memory[100];

// End the code
