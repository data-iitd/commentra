#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100000];
    scanf("%s", str);
    int len = strlen(str);
    int oddCount = 0;
    int map[26] = {0};
    for (int i = 0; i < len; i++)
    {
        map[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (map[i] % 2!= 0)
        {
            oddCount++;
        }
    }
    if (oddCount <= 1 || oddCount % 2!= 0)
    {
        printf("First\n");
    }
    else
    {
        printf("Second\n");
    }
    return 0;
}
