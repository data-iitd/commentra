# Importing necessary libraries
from typing import List

def main():
    n = int(input())  # Read the first integer input (number of strings)
    m = int(input())  # Read the second integer input (possibly not used in this code)

    arrs: List[str] = [input() for _ in range(n)]  # Read each string and store it in the list

    length: List[int] = [0] * n  # Initialize list to store differences
    index = 0  # Initialize index for the length list
    returnDex = 0  # Initialize returnDex to store the result

    for tmp in arrs:  # Loop through each string in the list
        dexG = tmp.find("G")  # Find the index of 'G' in the string
        dexS = tmp.find("S")  # Find the index of 'S' in the string
        if dexG > dexS:  # Check if 'G' comes after 'S'
            returnDex = -1  # Set returnDex to -1 if 'G' is after 'S'
        length[index] = dexS - dexG  # Calculate and store the difference in length list
        index += 1

    unique_lengths = set(length)  # Use a set to store unique differences

    if returnDex == -1:  # Check if returnDex is -1
        print(returnDex)  # Print -1 if 'G' comes after 'S'
    else:
        print(len(unique_lengths))  # Print the size of the set if 'G' does not come after 'S'

if __name__ == "__main__":
    main()

# <END-OF-CODE>
