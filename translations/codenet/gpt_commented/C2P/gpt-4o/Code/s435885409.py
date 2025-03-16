def calc_score():
    out = 0  # Initialize the number of outs
    score = 0  # Initialize the score
    base = 0  # Initialize the number of players on base
    
    # Loop until there are 3 outs
    while out < 3:
        user_input = input()  # Read user input
        
        # Check if the input is "OUT"
        if user_input == "OUT":
            out += 1  # Increment the out count
        # Check if the input is "HIT"
        elif user_input == "HIT":
            # If all bases are occupied, score a point
            if base == 3:
                score += 1  # Increment the score
            else:
                base += 1  # Move a player to the next base
        # Check if the input is "HOMERUN"
        elif user_input == "HOMERUN":
            score += (base + 1)  # Score based on players on base plus the hitter
            base = 0  # Reset bases after a homerun
    
    # Return the calculated score
    return score

def main():
    n = int(input())  # Read the number of innings
    
    # Loop through the number of innings
    for _ in range(n):
        print(calc_score())  # Calculate and print the score for each inning

# Execute the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
