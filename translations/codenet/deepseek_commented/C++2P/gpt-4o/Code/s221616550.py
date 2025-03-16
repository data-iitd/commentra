# Function to check if a string is a palindrome
def is_palindrome(s):
    # Loop through the first half of the string
    for i in range(len(s) // 2):
        # Compare characters from the start and end of the string
        if s[i] != s[len(s) - 1 - i]:
            # If any characters do not match, return false
            return False
    # If all characters match, return true
    return True

def main():
    # Read the input string from the user
    s = input()
    # Check if the entire string and its first half are palindromes
    if is_palindrome(s) and is_palindrome(s[:len(s) // 2]):
        # Print "Yes" if both conditions are true
        print("Yes")
    else:
        # Print "No" if either condition is false
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
