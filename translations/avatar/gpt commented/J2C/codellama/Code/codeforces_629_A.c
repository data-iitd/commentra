#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() 
{ 
    // Create a Scanner object to read input from the console
    int num; 
    printf("Enter the number of strings to be processed: "); 
    scanf("%d", &num); 
    char **arr = (char **)malloc(num * sizeof(char *)); 
    for (int i = 0; i < num; i++) { 
        arr[i] = (char *)malloc(num * sizeof(char)); 
    } 
    printf("Enter the strings: "); 
    for (int i = 0; i < num; i++) { 
        for (int j = 0; j < num; j++) { 
            scanf(" %c", &arr[i][j]); 
        } 
    } 
    int counter = 0; 
    int fine = 0; 
    for (int i = 0; i < num; i++) { 
        for (int k = 0; k < num; k++) { 
            if (arr[k][i] == 'C') { 
                counter++; 
            } 
        } 
        fine += (counter * (counter - 1)) / 2; 
        counter = 0; 
    } 
    for (int i = 0; i < num; i++) { 
        for (int k = 0; k < num; k++) { 
            if (arr[i][k] == 'C') { 
                counter++; 
            } 
        } 
        fine += (counter * (counter - 1)) / 2; 
        counter = 0; 
    } 
    printf("Total fine: %d", fine); 
    return 0; 
} 
