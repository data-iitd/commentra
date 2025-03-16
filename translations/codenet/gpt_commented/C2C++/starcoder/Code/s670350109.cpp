#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int i, j = 0, t;
    char str1[100], str2[100], temp[100];

    cin >> str1;
    cin >> str2;

    i = strlen(str1);
    t = i - 1;

    if(strlen(str1)!= strlen(str2))
    {
        printf("NO\n");
    }
    else
    {
        while(str1[j]!= '\0')
        {
            temp[j] = str1[t];
            j++;
            t--;
        }
        temp[j] = '\0';

        t = 0;
        i = 0;

        while(temp[i]!= '\0')
        {
            if(temp[i] == str2[i])
            {
                t++;
            }
            i++;
        }

        if(strlen(str2) == t)
        {
            printf("YES\n");
        }
        else if(strlen(str2)!= t)
        {
            printf("NO\n");
        }
    }
    return 0;
}

