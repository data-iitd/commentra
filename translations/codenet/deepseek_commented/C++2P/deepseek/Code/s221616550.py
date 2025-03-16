def is_palindrome(s):
    # Loop through the first half of the string
    for i in range(len(s) // 2):
        # Compare characters from the start and end of the string
        if s[i] == s[len(s) - 1 - i]:
            continue
        # If any characters do not match, return False
        else:
            return False
    # If all characters match, return True
    return True


def main():
    # Declare a string variable to store user input
    s = input()
    # Check if the entire string and its first half are palindromes
    if is_palindrome(s) and is_palindrome(s[:len(s) // 2]):
        # Print "Yes" if both conditions are true
        print("Yes")
    else:
        # Print "No" if either condition is false
        print("No")


main()
