def main():
    # Read the number of strings to process
    n = int(input())
    
    # Initialize a dictionary to store sorted strings and their counts
    sdic = {}
    
    # Process each input string
    for _ in range(n):
        # Read the string, sort its characters, and join them back into a string
        s = [_s for _s in sorted(input().strip())]
        s = ''.join(s)
        
        # Update the count of the sorted string in the dictionary
        if s in sdic:
            sdic[s] += 1  # Increment count if the string is already in the dictionary
        else:
            sdic[s] = 1   # Initialize count if the string is not in the dictionary
    
    # Initialize a variable to hold the total count of anagram pairs
    ans = 0
    
    # Calculate the number of anagram pairs for each unique sorted string
    for k, v in sdic.items():
        ans += v * (v - 1) // 2  # Combination formula to count pairs
    
    # Print the total number of anagram pairs found
    print(ans)

# Entry point of the program
if __name__ == '__main__':
    main()
