#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2,temp;
    int i,j=0,t;
    // Read the first string from the user input
    cin>>str1;
    // Read the second string from the user input
    cin>>str2;
    // Calculate the length of the first string
    i=str1.length();
    // Initialize the index for reversing the first string
    t=i-1;
    // Check if the lengths of the two strings are not equal
    if(str1.length()!=str2.length())
    {
        // Print "NO" if the lengths are not equal
        cout<<"NO\n";
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
        if(str2.length()==t)
        {
            // Print "YES" if all characters match
            cout<<"YES\n";
        }
        else
        {
            // Print "NO" if not all characters match
            cout<<"NO\n";
        }
    }
    return 0;
}
