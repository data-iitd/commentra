
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    // Variables to store N and L
    int N,L;

    // Read the number of strings N and the length L from the standard input
    scanf("%d %d",&N,&L);

    // Declare a 2D array of characters to store the strings
    char s[N][L];

    // Read N strings from the standard input and store them in the 2D array s
    for(int i=0;i<N;i++){
        scanf("%s",s[i]);
    }

    // Sort the 2D array s in lexicographical order
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(strcmp(s[i],s[j])>0){
                char temp[L];
                strcpy(temp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],temp);
            }
        }
    }

    // Concatenate and print the sorted strings without spaces
    for(int i=0;i<N;i++){
        printf("%s",s[i]);
    }
    printf("\n");
}

