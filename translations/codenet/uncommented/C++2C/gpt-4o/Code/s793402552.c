#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    // Convert b to string to find its length
<<<<<<< HEAD
    char bstr[12]; // Enough to hold up to 10 digits and a null terminator
=======
    char bstr[12]; // Enough to hold an integer up to 10 digits
>>>>>>> 98c87cb78a (data updated)
    sprintf(bstr, "%d", b);
    int b_length = strlen(bstr);
    
    // Calculate the number
    long long num = a * pow(10, b_length) + b;

    int i;
    for (i = 1; i <= 100100; i++)
    {
        if (i * i == num) break;
    }

    if (i > 100100) 
        printf("No\n");
    else 
        printf("Yes\n");

    return 0;
}

// <END-OF-CODE>
