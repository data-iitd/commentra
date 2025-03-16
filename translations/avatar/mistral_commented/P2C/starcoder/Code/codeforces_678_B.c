#include <stdio.h>

// Function to check if a year is a leap year
int leapyear(int n)
{
    // Check if the year is a leap year by checking if it satisfies the conditions
    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0))
    {
        // If the conditions are met, return "y" to indicate that the year is a leap year
        return 1;
    }
    else
    {
        // If the conditions are not met, return "n" to indicate that the year is not a leap year
        return 0;
    }
}

// Function to update the day of the week
void update(char *d, int n)
{
    // Check if the given year is a leap year
    if (leapyear(n))
    {
        // If the year is a leap year, update the day of the week accordingly
        if (d[0] =='m')
        {
            d[0] = 'w';
            n++;
        }
        else if (d[0] == 't')
        {
            d[0] = 'th';
            n++;
        }
        else if (d[0] == 'w')
        {
            d[0] = 'f';
            n++;
        }
        else if (d[0] == 'th')
        {
            d[0] ='sa';
            n++;
        }
        else if (d[0] == 'f')
        {
            d[0] ='s';
            n++;
        }
        else if (d[0] =='sa')
        {
            d[0] ='m';
            n++;
        }
        else if (d[0] =='s')
        {
            d[0] = 't';
            n++;
        }
    }
    else
    {
        // If the year is not a leap year, update the day of the week accordingly
        if (d[0] =='m')
        {
            d[0] = 't';
            n++;
        }
        else if (d[0] == 't')
        {
            d[0] = 'w';
            n++;
        }
        else if (d[0] == 'w')
        {
            d[0] = 'th';
            n++;
        }
        else if (d[0] == 'th')
        {
            d[0] = 'f';
            n++;
        }
        else if (d[0] == 'f')
        {
            d[0] ='sa';
            n++;
        }
        else if (d[0] =='sa')
        {
            d[0] ='s';
            n++;
        }
        else if (d[0] =='s')
        {
            d[0] ='m';
            n++;
        }
    }
}

// Driver code
int main()
{
    // Take an integer input from the user
    int n = 0;
    scanf("%d", &n);

    // Initialize a variable 'd' to keep track of the day of the week for the given year
    char d[2] = "f";

    // Check if the given year is a leap year
    if (leapyear(n))
    {
        // If the year is a leap year, set the answer to "ly"
        char ans[2] = "ly";
    }
    else
    {
        // If the year is not a leap year, set the answer to "nly"
        char ans[2] = "nly";
    }

    // Keep updating the day of the week and the year until we find the correct answer
    while (1)
    {
        // Check if the given year is a leap year
        if (leapyear(n))
        {
            // If the year is a leap year, update the day of the week accordingly
            update(d, n);
        }
        else
        {
            // If the year is not a leap year, update the day of the week accordingly
            update(d, n);
        }

        // Check if we have found the correct answer
        if (d[0] == 'f' && ans[0] == 'ly' && leapyear(n))
        {
            // If we have found the correct answer, break out of the loop
            break;
        }
        else if (d[0] == 'f' && ans[0] == 'nly' &&!leapyear(n))
        {
            // If we have found the correct answer, break out of the loop
            break;
        }
    }

    // Print the result
    printf("%d", n);

    return 0;
}

