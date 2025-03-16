
def solve():
    # Initialize variables to track the longest string and its count
    maxsize = 0
    maxcnt = 0
    ans_num = 0 # Index of the longest string
    ans_num2 = 0 # Index of the most frequent string
    str_v = [] # Vector to store input strings
    
    # Variable to read input strings
    in = input()
    while in:
        str_v.append(in) # Store the input string in the vector
        if maxsize < len(in): # Check if the current string is the longest so far
            maxsize = len(in) # Update the length of the longest string
            ans_num = len(str_v)-1 # Store the index of the longest string
        in = input()
    
    # Count occurrences of each string and find the most frequent string
    for i in range(len(str_v)):
        cnt = 0
        for j in range(len(str_v)):
            if str_v[i] == str_v[j]: cnt += 1 # Count occurrences of the current string
        if maxcnt < cnt: # Check if the current string is the most frequent so far
            maxcnt = cnt # Update the count of the most frequent string
            ans_num2 = i # Store the index of the most frequent string
    
    # Output the most frequent and the longest string
    print(str_v[ans_num2], str_v[ans_num])

# Main function to call the solve function
if __name__ == "__main__":
    solve()

