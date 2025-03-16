def main():
    str = input().strip()
    p = input().strip()
    
    # Duplicate and concatenate the string
    tmp = str
    str = str + tmp
    
    # Calculate the lengths of the strings
    slen = len(str)
    plen = len(p)
    
    # Initialize flag to 0 (not found)
    flag = 0
    
    # Check if the pattern exists in the concatenated string
    for i in range(slen - plen + 1):
        if str[i:i+plen] == p:
            flag = 1
            break
    
    # Output the result
    print("Yes" if flag else "No")

main()
