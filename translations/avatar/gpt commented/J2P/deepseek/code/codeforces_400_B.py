import sys

def main():
    # Read the number of strings (n) and the number of queries (m)
    n, m = map(int, sys.stdin.readline().split())
    
    # Initialize an array to store the strings
    arrs = []
    
    # Read n strings from the input
    for _ in range(n):
        arrs.append(input().strip())
    
    # Initialize an array to store the lengths of segments between 'G' and 'S'
    length = []
    
    # Iterate through each string to find the indices of 'G' and 'S'
    for tmp in arrs:
        dexG = tmp.find("G")  # Find the index of 'G'
        dexS = tmp.find("S")  # Find the index of 'S'
        
        # If 'G' appears after 'S', set returnDex to -1
        if dexG > dexS:
            print(-1)
            return
        
        # Calculate the length between 'G' and 'S' and store it in the length array
        length.append(dexS - dexG)
    
    # Use a set to store unique lengths
    unique_lengths = set(length)
    
    # Print the number of unique lengths
    print(len(unique_lengths))

if __name__ == "__main__":
    main()
