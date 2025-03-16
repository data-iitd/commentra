#include <iostream>
#include <vector>

int main()
{
    // Declare variables
    std::vector<int> a(1000);
    int n, d = 0;

    // Read the number of elements in the array
    std::cin >> n;

    // Read the elements of the array
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    // Bubble sort algorithm to sort the array in ascending order
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (a[j] < a[j - 1])
            {
                // Swap the elements if they are in the wrong order
                std::swap(a[j], a[j - 1]);
                // Increment the swap counter
                d++;
            }
        }
    }

    // Print the sorted array
    std::cout << a[0];
    for (int i = 1; i < n; i++)
    {
        std::cout << " " << a[i];
    }
    std::cout << std::endl;

    // Print the number of swaps made during the sorting process
    std::cout << d << std::endl;

    return 0;
}

// <END-OF-CODE>
