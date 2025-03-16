def main():
    # Declare a string 'c' to store the input string and 'ans' to store the result
    c = input()
    ans = ""
    
    # Iterate through each character of the input string
    for char in c:
        # If the current character is not 'B', append it to the 'ans' string
        if char != 'B':
            ans += char
        # If the current character is 'B', remove the last character from 'ans' (if it exists)
        else:
            if len(ans) > 0:
                ans = ans[:-1]
    
    # Print the resulting string after processing the input
    print(ans)

main()
