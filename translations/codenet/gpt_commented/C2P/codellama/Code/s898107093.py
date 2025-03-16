#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    # Declare pointers for storing team names and initialize scores
    t = []
    h = []
    n = 0
    taro = 0
    hanako = 0
    i = 0

    # Read the number of rounds (n) from input
    n = int(input())

    # Allocate memory for team names for both players
    t = [0] * n
    h = [0] * n
    
    # Loop through each round to read team names and calculate scores
    for i in range(n):
        # Allocate memory for each team name (up to 100 characters)
        t[i] = input()
        h[i] = input()
        
        # Compare team names and update scores based on the comparison
        if t[i] < h[i]:
            # If Hanako's team name is lexicographically smaller, she gets 3 points
            hanako += 3
        if t[i] > h[i]:
            # If Taro's team name is lexicographically larger, he gets 3 points
            taro += 3
        if t[i] == h[i]:
            # If both team names are the same, both players get 1 point
            taro += 1
            hanako += 1
        
        # Free the allocated memory for team names after processing
        #free(t[i])
        #free(h[i])
    
    # Output the final scores of Taro and Hanako
    print(taro, hanako)
    
    # Free the memory allocated for the pointers to team names
    #free(t)
    #free(h)
    
    return 0
}

