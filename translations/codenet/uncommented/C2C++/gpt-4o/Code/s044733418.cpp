#include <iostream>
#include <algorithm>

int compare(const int *a, const int *b)
{
    return (*b - *a);
}

int main()
{
    int array[10];
    for(int i = 0; i < 10; i++)
        std::cin >> array[i];
    
    std::qsort(array, 10, sizeof(int), reinterpret_cast<int(*)(const void*, const void*)>(compare));
    
    for(int i = 0; i < 3; i++)
        std::cout << array[i] << std::endl;
    
    return 0;
}

// <END-OF-CODE>
