
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int n, a, b; 
    scanf("%d %d %d", &n, &a, &b); 
    
    // Initialize two arrays to store the elements of the two lists
    int list1[a], list2[b]; 
    
    // Read 'a' integers into list1
    for (int i = 0; i < a; i++) { 
        scanf("%d", &list1[i]); 
    } 
    
    // Read 'b' integers into list2
    for (int i = 0; i < b; i++) { 
        scanf("%d", &list2[i]); 
    } 
    
    // Iterate from 0 to n-1 to check the presence of each index in list1
    for (int i = 0; i < n; i++) { 
        // If the current index + 1 is in list1, print 1
        int flag = 0; 
        for (int j = 0; j < a; j++) { 
            if (list1[j] == i + 1) { 
                flag = 1; 
                break; 
            } 
        } 
        if (flag == 1) { 
            printf("1 "); 
        } else { 
            // Otherwise, print 2
            printf("2 "); 
        } 
    } 
    return 0; 
}
