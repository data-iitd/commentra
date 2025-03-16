
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 368;
    int m[N];
    int f[N];
    int i, j, a, b, c;
    int num_of_operations;
    char gender;
    int start_time, end_time;

    // Initialize the lists to store changes for males and females
    for (i = 0; i < N; i++)
    {
        m[i] = 0;
        f[i] = 0;
    }

    // Read the number of operations
    scanf("%d", &num_of_operations);

    // Read each line, strip newline, and split into gender, start time, and end time
    for (i = 0; i < num_of_operations; i++)
    {
        scanf("%c %d %d", &gender, &start_time, &end_time);
        end_time++;

        // Update the changes in the lists based on gender
        if (gender == 'M')
        {
            m[start_time] += 2;
            m[end_time] -= 2;
        }
        else
        {
            f[start_time] += 2;
            f[end_time] -= 2;
        }
    }

    // Initialize variables to store the maximum number of people and the current number of people
    a = 0;
    b = 0;
    c = 0;

    // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
    for (i = 0; i < N; i++)
    {
        a += m[i];
        b += f[i];
        if (min(a, b) > c)
        {
            c = min(a, b);
        }
    }

    // Print the maximum number of people at any time slot
    printf("%d", c);

    return 0;
}

