#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int q;
    scanf("%d", &q);
    int ans[2] = {0, 0};
    int p1[q];
    int p2[q];
    int sum_b = 0;
    int sum_p1 = 0;
    int sum_p2 = 0;
    for (int i = 0; i < q; i++)
    {
        int ql[3];
        scanf("%d %d %d", &ql[0], &ql[1], &ql[2]);
        if (ql[0] == 2)
        {
            if (i == 0)
            {
                printf("0\n");
            }
            else
            {
                if (p1[i - 1] == p2[i - 1])
                {
                    printf("%d\n", p1[i - 1]);
                }
                else
                {
                    printf("%d\n", p1[i - 1] - p2[i - 1]);
                }
            }
        }
        else
        {
            sum_b += ql[2];
            if (i == 0)
            {
                p1[i] = ql[1];
                sum_p1 += ql[1];
            }
            else
            {
                if (p1[i - 1] <= ql[1])
                {
                    p1[i] = ql[1];
                    sum_p1 += ql[1];
                }
                else
                {
                    p2[i] = -ql[1];
                    sum_p2 += ql[1];
                }
            }
            if (i > 0)
            {
                if (p1[i - 1] < p2[i - 1])
                {
                    p1[i] = p2[i - 1];
                    sum_p1 += p2[i - 1];
                    sum_p2 -= p2[i - 1];
                }
                else if (p1[i - 1] > p2[i - 1])
                {
                    p2[i] = -p1[i - 1];
                    sum_p2 += p1[i - 1];
                    sum_p1 -= p1[i - 1];
                }
            }
        }
    }
    return 0;
}
