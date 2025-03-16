
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input = (char *)malloc(1000 * sizeof(char));
    scanf("%s", input);
    char *input_split = strtok(input, " ");
    int m = atoi(input_split);
    input_split = strtok(NULL, " ");
    int s = atoi(input_split);
    input_split = strtok(NULL, " ");
    int f = atoi(input_split);
    int maxT = -1;
    int *map = (int *)malloc(m * sizeof(int));
    int *map_split = (int *)malloc(2 * sizeof(int));
    int i = 0;
    while (m > 0)
    {
        scanf("%s", input);
        input_split = strtok(input, " ");
        map[i] = atoi(input_split);
        input_split = strtok(NULL, " ");
        map_split[0] = atoi(input_split);
        input_split = strtok(NULL, " ");
        map_split[1] = atoi(input_split);
        maxT = maxT > map[i] ? maxT : map[i];
        m--;
        i++;
    }
    char *actions = (char *)malloc(1000 * sizeof(char));
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;
    int a = -1;
    int b = -1;
    for (int t = 1; t <= maxT; t++)
    {
        if (map[t - 1] != 0)
        {
            a = map_split[t - 1][0];
            b = map_split[t - 1][1];
        }
        if (map[t - 1] != 0 && (cur >= a && cur <= b || cur + d >= a && cur + d <= b))
        {
            actions[t - 1] = 'X';
        }
        else
        {
            actions[t - 1] = M;
            cur += d;
        }
        if (cur == f)
            break;
    }
    while (cur != f)
    {
        actions[t - 1] = M;
        cur += d;
    }
    printf("%s", actions);
    return 0;
}

