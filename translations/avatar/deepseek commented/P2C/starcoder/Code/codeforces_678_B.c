#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, d, ans;
    char day[10];

    scanf("%d", &n);
    d = 'f';
    ans = 'n';

    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0))
    {
        ans = 'y';
    }

    while (1)
    {
        if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0))
        {
            if (d =='m')
            {
                d = 'w';
                n++;
            }
            else if (d == 't')
            {
                d = 'th';
                n++;
            }
            else if (d == 'w')
            {
                d = 'f';
                n++;
            }
            else if (d == 'th')
            {
                d ='sa';
                n++;
            }
            else if (d == 'f')
            {
                d ='s';
                n++;
            }
            else if (d =='sa')
            {
                d ='m';
                n++;
            }
            else if (d =='s')
            {
                d = 't';
                n++;
            }
        }
        else
        {
            if (d =='m')
            {
                d = 't';
                n++;
            }
            else if (d == 't')
            {
                d = 'w';
                n++;
            }
            else if (d == 'w')
            {
                d = 'th';
                n++;
            }
            else if (d == 'th')
            {
                d = 'f';
                n++;
            }
            else if (d == 'f')
            {
                d ='sa';
                n++;
            }
            else if (d =='sa')
            {
                d ='s';
                n++;
            }
            else if (d =='s')
            {
                d ='m';
                n++;
            }
        }

        if (d == 'f' && ans == 'y' && leapyear(n) == 'y')
        {
            break;
        }
        else if (d == 'f' && ans == 'n' && leapyear(n) == 'n')
        {
            break;
        }
    }

    printf("%d", n);

    return 0;
}

int leapyear(int n)
{
    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0))
    {
        return 'y';
    }
    else
    {
        return 'n';
    }
}

