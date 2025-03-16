import sys

# Function to read a single string from input
def scan_string():
    return sys.stdin.readline().strip()

# Function to read a single integer from input
def scan_int():
    return int(scan_string())

# Function to read a single float from input
def scan_float():
    return float(scan_string())

# Main function where the program execution begins
def main():
    # Read the first string (s)
    s = scan_string()
    # Read the second string (t)
    t = scan_string()

    # Initialize a list to hold possible answers
    ans = []
    
    # Iterate through the first string to find occurrences of the second string
    for i in range(len(s) - len(t) + 1):
        f = True  # Flag to check if the current position is valid
        ss = list(s)  # Create a copy of the original string

        # Check if the substring of s can match t
        for j in range(len(t)):
            # If characters do not match and are not '?', set flag to false
            if s[i + j] != t[j] and s[i + j] != '?':
                f = False
                break
            else:
                # Replace '?' with the corresponding character from t
                ss[i + j] = t[j]

        # If the substring matched, replace remaining '?' with 'a' and store the result
        if f:
            ans.append(''.join(ss).replace('?', 'a'))

    # Sort the possible answers
    ans.sort()

    # Output the result: either the first valid answer or "UNRESTORABLE"
    if len(ans) == 0:
        print("UNRESTORABLE")
    else:
        print(ans[0])

if __name__ == "__main__":
    main()
