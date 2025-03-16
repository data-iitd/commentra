import sys

def main():
    n = int(input().strip())  # Read the first integer input (number of strings)
    m = int(input().strip())  # Read the second integer input (possibly not used in this code)

    arrs = []  # Declare and initialize list to store strings
    for _ in range(n):
        arrs.append(input().strip())  # Read each string and store it in the list

    length = []  # Declare and initialize list to store differences
    returnDex = 0  # Initialize returnDex to store the result

    for tmp in arrs:  # Loop through each string in the list
        dexG = tmp.find("G")  # Find the index of 'G' in the string
        dexS = tmp.find("S")  # Find the index of 'S' in the string
        if dexG > dexS:  # Check if 'G' comes after 'S'
            returnDex = -1  # Set returnDex to -1 if 'G' is after 'S'
            break  # Break the loop as we found that 'G' comes after 'S'
        length.append(dexS - dexG)  # Calculate and store the difference in length list

    if returnDex == -1:  # Check if returnDex is -1
        print(returnDex)  # Print -1 if 'G' comes after 'S'
    else:
        unique_lengths = set(length)  # Use set to get unique differences
        print(len(unique_lengths))  # Print the size of the set if 'G' does not come after 'S'

if __name__ == "__main__":
    main()
