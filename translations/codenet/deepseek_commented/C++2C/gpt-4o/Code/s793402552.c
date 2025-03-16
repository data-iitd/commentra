#include <stdio.h>
#include <math.h>

<<<<<<< HEAD
int main()
{
=======
int main() {
>>>>>>> 98c87cb78a (data updated)
    int a, b;
    scanf("%d %d", &a, &b);

    // Convert b to string to determine its length
    char bstr[12]; // Assuming b will not exceed 10^10
    sprintf(bstr, "%d", b);
    int length = 0;
<<<<<<< HEAD
    while (bstr[length] != '\0') length++; // Calculate length of bstr
=======
    while (bstr[length] != '\0') {
        length++;
    }
>>>>>>> 98c87cb78a (data updated)

    // Calculate num
    long long num = a * pow(10, length) + b;

    int i;
<<<<<<< HEAD
    for (i = 1; i <= 100100; i++)
    {
=======
    for (i = 1; i <= 100100; i++) {
>>>>>>> 98c87cb78a (data updated)
        if (i * i == num) break;
    }

    // Check if a perfect square root was found
<<<<<<< HEAD
    if (i > 100100) printf("No\n");
    else printf("Yes\n");
=======
    if (i > 100100) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
>>>>>>> 98c87cb78a (data updated)

    return 0;
}

// <END-OF-CODE>
