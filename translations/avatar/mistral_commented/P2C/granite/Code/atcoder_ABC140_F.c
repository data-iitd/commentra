
#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
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

// Main function to solve the problem
char* main(){
    // Read the number of test cases
    int N = I();

    // Read the list of integers and sort it in descending order
    int* S = LI();
    qsort(S, N, sizeof(int), cmpfunc);

    // Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
    int* flag = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        flag[i] = 1;
    }

    // Initialize an empty list to store the current subsequence
    int* cur = (int*)malloc(N * sizeof(int));
    int cur_len = 0;

    // Start from the first integer and include it in the subsequence
    cur[cur_len++] = S[0];
    flag[0] = 0;

    // For each integer in the sorted list
    for(int i = 0; i < N; i++){
        // Initialize variables
        int j = 0;
        int jM = cur_len;

        // Try to include the current integer in the subsequence
        for(int k = 0; k < N; k++){
            // If the flag of the current integer is True and it is smaller than the last integer in the subsequence
            if(flag[k] && S[k] < cur[j]){
                // Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
                cur[cur_len++] = S[k];
                j++;
                flag[k] = 0;
                // If the length of the subsequence hasn't changed, break the loop
                if(j == jM){
                    break;
                }
            }
        }

        // If we couldn't include any integer in the subsequence after the current one, return "No"
        if(j == jM){
            return "No";
        }

        // Sort the subsequence in descending order
        qsort(cur, cur_len, sizeof(int), cmpfunc);
    }

    // If we could include all the integers in the subsequence, return "Yes"
    return "Yes";
}

// Function to compare two integers for qsort
int cmpfunc (const void * a, const void * b) {
   return (*(int*)b - *(int*)a);
}

// Run the main function if the script is executed directly
int main(){
    // Read the output and print it
    printf("%s\n", main());
    return 0;
}

