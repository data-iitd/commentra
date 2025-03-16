def solve():
    # Initialize variables to track the maximum size of strings and their counts
    maxsize = 0  # To store the length of the longest string
    maxcnt = 0   # To store the count of the most frequent string
    ans_num = -1  # Index of the longest string
    ans_num2 = -1  # Index of the most frequent string
    str_v = []    # List to store input strings
    
    # Read strings from standard input until EOF
    try:
        while True:
            in_str = input()  # Read input string
            str_v.append(in_str)  # Add the string to the list
            
            # Check if the current string is longer than the previously recorded maximum
            if maxsize < len(in_str):
                maxsize = len(in_str)  # Update the maximum size
                ans_num = len(str_v) - 1  # Update index of the longest string
    except EOFError:
        pass  # End of input
    
    # Loop through the list to find the most frequent string
    for i in range(len(str_v)):
        cnt = 0  # Counter for occurrences of the current string
        # Count how many times the current string appears in the list
        for j in range(len(str_v)):
            if str_v[i] == str_v[j]:
                cnt += 1  # Increment count if a match is found
        
        # Check if the current count is greater than the previously recorded maximum count
        if maxcnt < cnt:
            maxcnt = cnt  # Update the maximum count
            ans_num2 = i  # Update index of the most frequent string
    
    # Output the most frequent string and the longest string
    print(str_v[ans_num2], str_v[ans_num])

# Call the solve function to process input and output results
solve()  # This will be executed when the script runs

# <END-OF-CODE>
