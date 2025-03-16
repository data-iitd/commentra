def main():
    c = input()  # Read input string into c
    ans = ""  # Declare an empty string ans

    # Process the input string
    for char in c:
        if char != 'B':
            ans += char  # Append character to ans if not 'B'
        else:
            ans = ans[:-1]  # Remove last character from ans if 'B'

    print(ans)  # Output the result string ans


main()
