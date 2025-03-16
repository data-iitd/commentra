####### 
# Importing necessary Python libraries
#######
import sys

####### 
# Main function is the entry point of the Python application
#######
def main():
    # Reading the first line of input as a list of strings
    str_input = input().split()

    # Reading the second line of input as separate tokens
    a, b = map(int, input().split())

    # Reading the third line of input as a string
    u = input()

    # Checking if the first string from the first line matches with the given string 'u'
    if u == str_input[0]:
        # If the condition is true, then print the result as (a-1) and b
        print(a - 1, b)
    else:
        # If the condition is false, then print the result as a and (b-1)
        print(a, b - 1)

# Calling the main function to execute the program
if __name__ == "__main__":
    main()

####### 
# End of the Python code
#######
# <END-OF-CODE>
