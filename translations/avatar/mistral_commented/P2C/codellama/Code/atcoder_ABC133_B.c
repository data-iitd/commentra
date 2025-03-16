#include <stdio.h>
#include <math.h>

int main()
{
    // Declaring and initializing variables
    int n, d, i, j, count = 0;
    double tmp;

    // Taking the number of points, n, and the number of dimensions, d, as input
    scanf("%d %d", &n, &d);

    // Declaring a 2D array 'points' of size 'n' to store the coordinates of each point
    int points[n][d];

    // Iterating through each point 'i' in 'points'
    for (i = 0; i < n; i++)
    {
        // Iterating through each dimension 'j' of the 'i'th point
        for (j = 0; j < d; j++)
        {
            // Taking the 'j'th coordinate of the 'i'th point as input
            scanf("%d", &points[i][j]);
        }
    }

    // Defining a function 'dist' to calculate the Euclidean distance between two points
    double dist(int x[], int y[])
    {
        // Initializing a variable 'tmp' to store the sum of squared differences between corresponding elements of 'x' and 'y'
        tmp = 0.0;

        // Iterating through each dimension 'i' from 0 to 'd'
        for (i = 0; i < d; i++)
        {
            // Adding the square of the difference between the 'i'th elements of 'x' and 'y' to 'tmp'
            tmp += (x[i] - y[i]) * (x[i] - y[i]);
        }

        // Returning the square root of 'tmp' as the Euclidean distance between 'x' and 'y'
        return sqrt(tmp);
    }

    // Iterating through each point 'i' in 'points'
    for (i = 0; i < n; i++)
    {
        // Iterating through each point 'j' from 'i+1' to the last point in 'points'
        for (j = i + 1; j < n; j++)
        {
            // Checking if the Euclidean distance between 'points[i]' and 'points[j]' is an integer
            if (dist(points[i], points[j]) == (int)dist(points[i], points[j]))
            {
                // Incrementing the 'count' variable if the condition is true
                count++;
            }
        }
    }

    // Printing the final value of 'count'
    printf("%d", count);

    // Ending the code with a comment "