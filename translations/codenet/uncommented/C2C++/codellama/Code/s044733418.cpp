#include<iostream>
#include<algorithm>

int compare(int *a, int *b)
{
    return (*b - *a);
}

int main(void)
{
    int array[10], i;
    for(i = 0; i != 10; i++)
        std::cin >> array[i];
    std::sort(array, array+10, compare);
    for(i = 0; i != 3; i++)
        std::cout << array[i] << std::endl;
    return 0;
}

