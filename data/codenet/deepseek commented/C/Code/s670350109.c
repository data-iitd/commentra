#include<stdio.h>
#include<string.h>
char str1[100],str2[100],temp[100];
int main()
{
    int i,j=0,t;
    // Read the first string from the user input
    scanf("%s[^\n]",str1);
    // Read the second string from the user input
    scanf("%s[^\n]",str2);
    // Calculate the length of the first string
    i=strlen(str1);
    // Initialize the index for reversing the first string
    t=i-1;
    // Check if the lengths of the two strings are not equal
    if(strlen(str1)!=strlen(str2))
    {
        // Print "NO" if the lengths are not equal
        printf("NO\n");
    }
    else
    {
        // Reverse the first string and store it in temp
        while(str1[j]!='\0')
        {
            temp[j]=str1[t];
            j++;
            t--;
        }
        // Reset the index for comparing the strings
        t=0;
        i=0;
        // Compare each character of the reversed string and the second string
        while(temp[i]!='\0')
        {
            if(temp[i]==str2[i])
            {
                t++;
            }
            i++;
        }
        // Check if the number of matching characters is equal to the length of the second string
        if(strlen(str2)==t)
        {
            // Print "YES" if all characters match
            printf("YES\n");
        }
        else
        {
            // Print "NO" if not all characters match
            printf("NO\n");
        }
    }
    return 0;
}
