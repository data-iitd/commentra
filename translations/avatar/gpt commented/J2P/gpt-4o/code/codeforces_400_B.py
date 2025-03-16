# Import necessary modules
from typing import List

def main():
    # Create a Scanner object to read input from the console
    n, m = map(int, input().split())  # Read the number of strings (n) and the number of queries (m)
    
    # Initialize a list to store the strings
    arrs = [input().strip() for _ in range(n)]  # Read n strings from the input
    
    # Initialize a list to store the lengths of segments between 'G' and 'S'
    lengths = []
    return_dex = 0
    
    # Iterate through each string to find the indices of 'G' and 'S'
    for tmp in arrs:
        dex_g = tmp.find("G")  # Find the index of 'G'
        dex_s = tmp.find("S")  # Find the index of 'S'
        
        # If 'G' appears after 'S', set return_dex to -1
        if dex_g > dex_s:
            return_dex = -1
        
        # Calculate the length between 'G' and 'S' and store it in the lengths list
        lengths.append(dex_s - dex_g)
    
    # Use a set to store unique lengths
    unique_lengths = set(lengths)  # Add each length to the set to ensure uniqueness
    
    # Check if return_dex was set to -1 and print the appropriate result
    if return_dex == -1:
        print(return_dex)  # Print -1 if 'G' is after 'S' in any string
    else:
        print(len(unique_lengths))  # Print the number of unique lengths

if __name__ == "__main__":
    main()

# <END-OF-CODE>
