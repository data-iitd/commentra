#include <string.h>
#include <stdio.h>

# Function to calculate the score for each inning
def calc_score():
    out = 0 # Initialize the number of outs to 0
    str = "" # Create a character array to store the input string
    score = 0 # Initialize the score to 0
    base = 0 # Initialize the number of bases to 0

    # Loop through the three events in each inning
    while out < 3:
        print("Enter the event for this at bat (HIT, HOMERUN or OUT): ", end="") # Ask for the event
        str = input() # Read the event from the standard input

        # Check if the event is OUT
        if str == "OUT":
            out += 1 # Increment the number of outs
        # Check if the event is HIT
        elif str == "HIT":
            # If there are already three bases, increment the score
            if base == 3:
                score += 1
            # If not, increment the number of bases
            else:
                base += 1
        # Check if the event is HOMERUN
        elif str == "HOMERUN":
            score += (base + 1) # Add the number of bases and 1 to the score
            base = 0 # Reset the number of bases to 0

    # Return the score for this inning
    return score

# Main function to read the number of innings and call calc_score() for each inning
def main():
    n = 0 # Initialize the number of innings to be read
    inning = 0 # Initialize the current inning number to 0

    # Read the number of innings from the standard input
    print("Enter the number of innings: ", end="")
    n = int(input())

    # Loop through each inning and call calc_score() to calculate the score
    while inning < n:
        score = calc_score() # Call calc_score() to calculate the score for this inning
        print(score) # Print the score for this inning
        inning += 1 # Increment the current inning number

    # Return 0 to indicate successful execution
    return 0

# Call the main() function
main()

