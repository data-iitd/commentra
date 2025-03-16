#include <string.h>
#include <stdio.h>

# Function to calculate the score based on user input
def calc_score():
    out = 0 # Initialize the number of outs
    str = "" # Buffer to store user input
    score = 0 # Initialize the score
    base = 0 # Initialize the number of players on base

    # Loop until there are 3 outs
    while out < 3:
        str = input() # Read user input into str

        # Check if the input is "OUT"
        if str == "OUT":
            out += 1 # Increment the out count
        # Check if the input is "HIT"
        elif str == "HIT":
            # If all bases are occupied, score a point
            if base == 3:
                score += 1 # Increment the score
            else:
                base += 1 # Move a player to the next base
        # Check if the input is "HOMERUN"
        elif str == "HOMERUN":
            score += (base + 1) # Score based on players on base plus the hitter
            base = 0 # Reset bases after a homerun

    # Return the calculated score
    return score

# Main function to execute the program
def main():
    n = 0 # Variable to hold the number of innings
    inning = 0 # Initialize the inning count

    # Read the number of innings from user input
    n = int(input())

    # Loop through the number of innings
    while inning < n:
        print(calc_score()) # Calculate and print the score for each inning
        inning += 1 # Increment the inning count

    # Return 0 to indicate successful execution
    return 0

