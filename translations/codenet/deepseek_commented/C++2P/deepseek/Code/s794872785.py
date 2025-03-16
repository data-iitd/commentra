def solve():
    # Initialize variables to track the longest string and its count
    maxsize = 0
    maxcnt = 0
    ans_num = 0  # Index of the longest string
    ans_num2 = 0  # Index of the most frequent string
    str_v = []  # List to store input strings
    
    # Read input strings until EOF
    while True:
        try:
            inp = input()
        except EOFError:
            break
        str_v.append(inp)  # Store the input string in the list
        if maxsize < len(inp):  # Check if the current string is the longest so far
            maxsize = len(inp)  # Update the length of the longest string
            ans_num = len(str_v) - 1  # Store the index of the longest string
    
    # Count occurrences of each string and find the most frequent string
    for i in range(len(str_v)):
        cnt = 0
        for j in range(len(str_v)):
            if str_v[i] == str_v[j]:
                cnt += 1  # Count occurrences of the current string
        if maxcnt < cnt:  # Check if the current string is the most frequent so far
            maxcnt = cnt  # Update the count of the most frequent string
            ans_num2 = i  # Store the index of the most frequent string
    
    # Output the most frequent and the longest string
    print(str_v[ans_num2], str_v[ans_num])

# Call the solve function
solve()

