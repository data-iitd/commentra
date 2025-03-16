def calc_score():
    out = 0  # Initialize the number of outs to 0
    score = 0  # Initialize the score to 0
    base = 0  # Initialize the number of bases to 0

    # Loop through the three events in each inning
    while out < 3:
        event = input("Enter the event for this at bat (HIT, HOMERUN or OUT): ")  # Ask for the event

        # Check if the event is OUT
        if event == "OUT":
            out += 1  # Increment the number of outs
        # Check if the event is HIT
        elif event == "HIT":
            # If there are already three bases, increment the score
            if base == 3:
                score += 1
            # If not, increment the number of bases
            else:
                base += 1
        # Check if the event is HOMERUN
        elif event == "HOMERUN":
            score += (base + 1)  # Add the number of bases and 1 to the score
            base = 0  # Reset the number of bases to 0

    # Return the score for this inning
    return score

def main():
    n = int(input("Enter the number of innings: "))  # Read the number of innings from the standard input
    inning = 0  # Initialize the current inning number to 0

    # Loop through each inning and call calc_score() to calculate the score
    while inning < n:
        score = calc_score()  # Call calc_score() to calculate the score for this inning
        print(score)  # Print the score for this inning
        inning += 1  # Increment the current inning number

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
