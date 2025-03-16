#include <stdio.h>
#include <string.h>

char* check(int x, int y)
{
    static char result[3]; // To store "Yes" or "No"
    if(y % 2 == 0)
    {
        int t = (int)(0.5*y) - x;
        if(t >= 0 && (x-t) >= 0)
        {
            strcpy(result, "Yes");
            return result;
        }
    }
    strcpy(result, "No");
    return result;
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%s\n", check(x, y));
    return 0;
}
