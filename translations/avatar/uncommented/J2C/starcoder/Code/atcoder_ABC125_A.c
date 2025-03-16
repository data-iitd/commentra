#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sec, per_num, max_sec, ans_num;
    scanf("%d %d %d", &sec, &per_num, &max_sec);
    max_sec += 0.5;
    for (int i = sec; i < max_sec; i += sec)
    {
        ans_num += per_num;
    }
    printf("%d", ans_num);
    return 0;
}
