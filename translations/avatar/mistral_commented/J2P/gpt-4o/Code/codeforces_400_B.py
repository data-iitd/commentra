# Importing necessary libraries
from typing import List

def main():
    # Reading the first two integers from the input
    n, m = map(int, input().split())

    # Creating a list to store input strings
    arrs = [input() for _ in range(n)]

    # Initializing a list to store the length of substrings between "G" and "S"
    length = []
    returnDex = -1  # Index for storing the index of the string with "G" before "S"

    # Iterating through each string in the array and finding the length of substrings between "G" and "S"
    for i, tmp in enumerate(arrs):
        dexG = tmp.find("G")  # Finding the index of "G" in the current string
        dexS = tmp.find("S")  # Finding the index of "S" in the current string

        # Checking if "G" comes before "S" in the current string
        if dexG > dexS:
            returnDex = i  # Storing the index of the string with "G" before "S"
            break  # Exiting the loop as we have found the required string

        # Storing the length of the substring between "G" and "S"
        if dexG != -1 and dexS != -1:  # Ensure both "G" and "S" are found
            length.append(dexS - dexG)

    # Creating a set to store the unique lengths of substrings
    unique_lengths = set(length)

    # Checking if there is a string with "G" before "S"
    if returnDex == -1:
        # Printing the result if there is no such string
        print(returnDex)
    else:
        # Printing the size of the set if there is a string with "G" before "S"
        print(len(unique_lengths))

# Calling the main function to execute the code
if __name__ == "__main__":
    main()

# <END-OF-CODE>
