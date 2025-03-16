
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, i, j, k, counter, fine;
    char grid[100][100];
    scanf("%d", &num);
    for(i=0; i<num; i++)
        scanf("%s", grid[i]);
    for(i=0; i<num; i++)
    {
        counter = 0;
        for(j=0; j<num; j++)
        {
            if(grid[j][i] == 'C')
                counter++;
        }
        fine += (counter * (counter - 1)) / 2;
    }
    for(i=0; i<num; i++)
    {
        counter = 0;
        for(j=0; j<num; j++)
        {
            if(grid[i][j] == 'C')
                counter++;
        }
        fine += (counter * (counter - 1)) / 2;
    }
    printf("%d\n", fine);
    return 0;
}

