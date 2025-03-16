def main():
    # Read the number of rounds (n) from input
    n = int(input())

    # Initialize scores for Taro and Hanako
    taro = 0
    hanako = 0

    # Loop through each round to read team names and calculate scores
    for _ in range(n):
        # Read team names for both players
        t = input()
        h = input()
        
        # Compare team names and update scores based on the comparison
        if t < h:
            # If Hanako's team name is lexicographically smaller, she gets 3 points
            hanako += 3
        elif t > h:
            # If Taro's team name is lexicographically larger, he gets 3 points
            taro += 3
        else:
            # If both team names are the same, both players get 1 point
            taro += 1
            hanako += 1
    
    # Output the final scores of Taro and Hanako
    print(f"{taro} {hanako}")

# Call the main function
main()
