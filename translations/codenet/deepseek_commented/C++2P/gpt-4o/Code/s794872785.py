def solve():
    # Initialize variables to track the longest string and its count
    maxsize = 0
    maxcnt = 0
    ans_num = -1  # Index of the longest string
    ans_num2 = -1  # Index of the most frequent string
    str_v = []  # List to store input strings

    # Read input strings
    while True:
        try:
            in_str = input()  # Read input string
            str_v.append(in_str)  # Store the input string in the list
            if maxsize < len(in_str):  # Check if the current string is the longest so far
                maxsize = len(in_str)  # Update the length of the longest string
                ans_num = len(str_v) - 1  # Store the index of the longest string
        except EOFError:
            break  # Exit the loop on EOF

    # Count occurrences of each string and find the most frequent string
    for i in range(len(str_v)):
        cnt = str_v.count(str_v[i])  # Count occurrences of the current string
        if maxcnt < cnt:  # Check if the current string is the most frequent so far
            maxcnt = cnt  # Update the count of the most frequent string
            ans_num2 = i  # Store the index of the most frequent string

    # Output the most frequent and the longest string
    print(str_v[ans_num2], str_v[ans_num])

# Main function to call the solve function
if __name__ == "__main__":
    solve()

# <END-OF-CODE>
