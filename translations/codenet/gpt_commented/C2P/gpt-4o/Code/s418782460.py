import sys

MAX_STRING = 30
MAX_LINE = 2000000
MAX_HUMAN = 200000

# Global variables
sLongInputLine = ""  # Buffer for long input line
anComingSec = []  # List to store the coming seconds of humans

def main():
    global sLongInputLine, anComingSec

    # Local variables
    sInput = ""  # Buffer for the first line of input
    nHumanNumber = 0  # Number of humans
    nNextHumanIndex = 0  # Index for the next human
    nWaterLength = 0  # Length of water coverage
    nWaterLife = 0  # Total water life duration
    nStart = 0  # Start time for water coverage
    nStop = 0  # Stop time for water coverage

    # Read the first line of input containing number of humans and water length
    sInput = input().strip()  # Read input and remove newline
    tokens = sInput.split()  # Tokenize the input
    nHumanNumber = int(tokens[0])  # Convert first token to number of humans
    nWaterLength = int(tokens[1])  # Convert to water length

    # Read the second line of input containing the coming seconds of humans
    sLongInputLine = input().strip()  # Read input and remove newline
    tokens = sLongInputLine.split()  # Tokenize the input
    anComingSec = [int(token) for token in tokens]  # Store each coming second in the list

    # Initialize the start time for water coverage
    nStart = anComingSec[0]

    # Main loop to calculate the total water life duration
    while nNextHumanIndex < nHumanNumber:
        if nNextHumanIndex == nHumanNumber:
            break  # Exit if all humans have been processed
        else:
            nStop = nStart + nWaterLength  # Calculate stop time based on water length
            if anComingSec[nNextHumanIndex] < nStop:
                # Process humans that arrive before the current stop time
                while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
                    if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength  # Extend stop time if necessary
                        nNextHumanIndex += 1  # Move to the next human
                if nNextHumanIndex == nHumanNumber:
                    nWaterLife += (nStop - nStart)  # Add to water life if all humans are processed
                    break
            nWaterLife += (nStop - nStart)  # Add the duration of water coverage
            nStart = nStop  # Update start time for the next iteration
            if nStart < anComingSec[nNextHumanIndex]:
                nStart = anComingSec[nNextHumanIndex]  # Adjust start time if necessary

    # Output the total water life duration
    print(nWaterLife)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
