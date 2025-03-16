# Function to check if a given string is a palindrome
def is_palindrome(s):
    # Loop through the first half of the string
    for i in range(len(s) // 2):
        # Compare characters from the start and end of the string
        if s[i] != s[len(s) - 1 - i]:
            return False  # If they don't match, return false
    return True  # If all characters matched, return true

def main():
    s = input()  # Read input from the user

    # Check if the entire string is a palindrome and if the first half is also a palindrome
    if is_palindrome(s) and is_palindrome(s[:len(s) // 2]):
        print("Yes")  # Output "Yes" if both conditions are true
    else:
        print("No")  # Output "No" if either condition is false

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
