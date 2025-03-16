
#include <stdio.h>
#include <stdlib.h>

// Function to read a single integer from standard input
int I(){
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from standard input
int* LI(){
    int N = I();
    int* S = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        S[i] = I();
    }
    return S;
}

char* main(){
    // Read the number of elements
    int N = I();
    
    // Read the list of integers, sort it in descending order
    int* S = LI();
    qsort(S, N, sizeof(int), cmpfunc);
    
    // Initialize a flag list to track which elements have been used
    int* flag = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        flag[i] = 1;
    }
    
    // Initialize the current list with the largest element
    int* cur = (int*)malloc(N * sizeof(int));
    cur[0] = S[0];
    
    // Mark the first element as used
    flag[0] = 0;
    
    // Iterate N times to build the current list
    for(int i = 0; i < N; i++){
        int j = 0;  // Index for the current list
        int jM = N;  // Length of the current list
        
        // Try to find the next largest unused element
        for(int k = 0; k < N; k++){
            // Check if the current element is unused and smaller than the last added element
            if(flag[k] && S[k] < cur[j]){
                cur[j] = S[k];  // Add the element to the current list
                j++;  // Move to the next index in the current list
                flag[k] = 0;  // Mark this element as used
                
                // If we have added enough elements, break out of the loop
                if(j == jM){
                    break;
                }
            }
        }
        
        // Sort the current list in descending order for the next iteration
        qsort(cur, jM, sizeof(int), cmpfunc);
    }
    
    // Free the allocated memory
    free(S);
    free(flag);
    free(cur);
    
    // If we successfully built the list, return "Yes"
    return "Yes";
}

// Entry point of the program
int main(){
    // Print the result of the main function
    printf("%s\n", main());
    
    return 0;
}

