#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main() { 
    // Create a Scanner object to read input from the user
    int N, D; 
    scanf("%d %d", &N, &D); 
    
    // Initialize a 2D array to store the vectors
    int vectors[N][D]; 
    
    // Read each vector's components from the input
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < D; j++) { 
            scanf("%d", &vectors[i][j]); 
        } 
    } 
    
    // Initialize a counter for the number of pairs with integer distances
    int answer = 0; 
    
    // Calculate the pairwise distances between all vectors
    for (int i = 0; i < N - 1; i++) { 
        for (int j = i + 1; j < N; j++) { 
            int dist = 0; 
            
            // Calculate the squared distance between vector i and vector j
            for (int d = 0; d < D; d++) { 
                int x = (vectors[i][d] - vectors[j][d]); 
                dist += (x * x); 
            } 
            
            // Calculate the Euclidean distance
            double sq = sqrt(dist); 
            
            // Check if the distance is an integer (within a small epsilon)
            answer += (fabs(sq - floor(sq)) < 0.001 ? 1 : 0); 
        } 
    } 
    
    // Output the total count of pairs with integer distances
    printf("%d\n", answer); 
    
    return 0; 
} 
