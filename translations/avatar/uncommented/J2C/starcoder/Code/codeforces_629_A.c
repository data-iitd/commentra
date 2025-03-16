#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, i, j, k, counter, fine;
    char **arr;
    scanf("%d", &num);
    arr = (char**)malloc(num*sizeof(char*));
    for(i=0; i<num; i++)
    {
        arr[i] = (char*)malloc(num*sizeof(char));
        scanf("%s", arr[i]);
    }
    fine = 0;
    for(i=0; i<num; i++)
    {
        for(k=0; k<num; k++)
        {
            if(arr[k][i] == 'C')
                counter++;
        }
        fine += (counter*(counter-1))/2;
        counter = 0;
    }
    for(i=0; i<num; i++)
    {
        for(k=0; k<num; k++)
        {
            if(arr[i][k] == 'C')
                counter++;
        }
        fine += (counter*(counter-1))/2;
        counter = 0;
    }
    printf("%d", fine);
    return 0;
}

