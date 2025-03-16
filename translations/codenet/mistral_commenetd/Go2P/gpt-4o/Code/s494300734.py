# Import statements, importing the sys and string modules
import sys

# Entry point of the program
def main():
    # Initialize a variable s and read a string input from the standard input
    s = input().strip()

    # Initialize a variable ans with the string value "No"
    ans = "No"

    # Check if the index of the substring "C" in the string s is less than the index of the substring "F"
    if s.find("C") < s.rfind("F"):
        # If it is, then change the value of ans to "Yes"
        ans = "Yes"

    # Check if the index of the substring "C" in the string s is less than 0
    if s.find("C") < 0:
        # If it is, then do not change the value of ans
        pass

    # Print the value of ans to the standard output
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
