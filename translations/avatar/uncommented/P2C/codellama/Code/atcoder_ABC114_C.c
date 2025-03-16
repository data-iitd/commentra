
#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    int aaa(int n)
    {
        if (n > N)
            return 0;
        int ans = 1;
        if (strstr(str(n), "7") && strstr(str(n), "5") && strstr(str(n), "3"))
            ans = 1;
        else
            ans = 0;
        for (int i = 0; i < 3; i++)
        {
            ans += aaa(n + i);
        }
        return ans;
    }

    printf("%d", aaa(0));

    return 0;
}

