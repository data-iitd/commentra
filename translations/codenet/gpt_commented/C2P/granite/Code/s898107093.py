
import sys

def main():
    # Declare lists for storing team names and initialize scores
    t = []
    h = []
    taro = 0
    hanako = 0
    
    # Read the number of rounds (n) from input
    n = int(input())
    
    # Loop through each round to read team names and calculate scores
    for i in range(n):
        # Read team names for both players
        t.append(input())
        h.append(input())
        
        # Compare team names and update scores based on the comparison
        if t[i] < h[i]:
            # If Hanako's team name is lexicographically smaller, she gets 3 points
            hanako += 3
        elif t[i] > h[i]:
            # If Taro's team name is lexicographically larger, he gets 3 points
            taro += 3
        else:
            # If both team names are the same, both players get 1 point
            taro += 1
            hanako += 1
    
    # Output the final scores of Taro and Hanako
    print(taro, hanako)

if __name__ == "__main__":
    main()

