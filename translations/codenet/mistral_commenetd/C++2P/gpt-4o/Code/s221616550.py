# Function to check if a given string is a palindrome
def is_palindrome(s):
    # Iterate through the first half of the string
    for i in range(len(s) // 2):
        # Check if the character at current index is same as its mirror index
        if s[i] != s[len(s) - 1 - i]:
            # If no, return false as the string is not a palindrome
            return False
    # If we reach here, it means all characters in the first half are same as their mirror index
    # So, the string is a palindrome
    return True

def main():
    # Take user input and store it in the string variable
    s = input()
    # Check if the given string is a palindrome and its first half is also a palindrome
    if is_palindrome(s) and is_palindrome(s[:len(s) // 2]):
        # If yes, print "Yes"
        print("Yes")
    else:
        # If no, print "No"
        print("No")

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
