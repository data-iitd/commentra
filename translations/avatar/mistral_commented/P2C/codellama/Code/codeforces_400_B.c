#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Read input
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an empty set
    int c[100000];
    int c_size = 0;

    // Populate set c with differences between indices of 'S' and 'G' in each string
    char s[100000];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        int index_S = strchr(s, 'S') - s;
        int index_G = strchr(s, 'G') - s;
        int difference = index_S - index_G;
        c[c_size++] = difference;
    }

    // Check if there is any negative number in set c and print accordingly
    int negative = 0;
    for (int i = 0; i < c_size; i++)
    {
        if (c[i] < 0)
        {
            negative = 1;
            break;
        }
    }
    printf("%d\n", negative ? -1 : c_size);

    return 0;
}

