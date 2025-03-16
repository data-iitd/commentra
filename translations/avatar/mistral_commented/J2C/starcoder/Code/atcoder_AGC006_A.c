#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Variable declaration and initialization
    int n, i, j, len, cnt = 0;
    char str[200], s1[200], b[400];

    scanf("%d", &n);
    scanf("%s", str);
    scanf("%s", s1);

    // Concatenating the two strings and creating character arrays for each
    for (i = 0; i < n; i++)
        b[cnt++] = str[i];
    for (i = 0; i < n; i++)
        b[cnt++] = s1[i];

    int f[400];
    f[0] = f[1] = 0;

    // Main logic of the function
    for (i = 2; i <= cnt; i++)
    {
        j = 0;
        while (j > 0 && b[j + 1]!= b[i])
            j = f[j];
        if (b[j + 1] == b[i])
            j++;
        f[i] = j;
    }

    len = f[cnt];
    if (len > n)
        len = n;
    if (len > strlen(str))
        len = strlen(str);

    printf("%d\n", 2 * n - len);

    return 0;
}

