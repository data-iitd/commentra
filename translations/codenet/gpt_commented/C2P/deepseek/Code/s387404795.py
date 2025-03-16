def main():
    # Read two strings from standard input
    str, p = input().split()
    
    # Copy the original string into a temporary variable and concatenate it with itself
    tmp = str
    str = str + tmp
    
    # Calculate the lengths of the concatenated string and the pattern string
    slen = len(str)
    plen = len(p)
    
    # Initialize a flag to indicate if the pattern is found
    flag = False
    
    # Loop through the concatenated string to search for the pattern
    for i in range(slen - plen + 1):
        # Compare the substring of str with the pattern p
        if str[i:i+plen] == p:
            flag = True  # Set flag if a match is found
            break  # Exit the loop early if a match is found
    
    # Output "Yes" if the pattern was found, otherwise output "No"
    print("Yes" if flag else "No")


