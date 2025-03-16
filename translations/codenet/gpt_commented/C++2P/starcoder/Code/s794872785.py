# Function to solve the problem of finding the longest and most frequent string
def solve():
    # Initialize variables to track the maximum size of strings and their counts
    maxsize = 0 # To store the length of the longest string
    maxcnt = 0  # To store the count of the most frequent string
    ans_num = 0 # Index of the longest string
    ans_num2 = 0 # Index of the most frequent string
    str_v = [] # Vector to store input strings
    
    in = input() # Variable to hold each input string
    # Read strings from standard input until EOF
    while in:
        str_v.append(in) # Add the string to the vector
        # Check if the current string is longer than the previously recorded maximum
        if maxsize < len(in):
            maxsize = len(in) # Update the maximum size
            ans_num = len(str_v) - 1 # Update index of the longest string
        in = input()
    
    # Loop through the vector to find the most frequent string
    for i in range(len(str_v)):
        cnt = 0 # Counter for occurrences of the current string
        # Count how many times the current string appears in the vector
        for j in range(len(str_v)):
            if str_v[i] == str_v[j]: cnt += 1 # Increment count if a match is found
        # Check if the current count is greater than the previously recorded maximum count
        if maxcnt < cnt:
            maxcnt = cnt # Update the maximum count
            ans_num2 = i # Update index of the most frequent string
    
    # Output the most frequent string and the longest string
    print(str_v[ans_num2], str_v[ans_num])
    
    return True # Indicate successful execution

if __name__ == "__main__":
    # Set output format to fixed-point notation with 10 decimal places
    # This is done to ensure that the output is consistent with the sample output
    # provided in the problem statement
    print("{:.10f}".format(solve()))

