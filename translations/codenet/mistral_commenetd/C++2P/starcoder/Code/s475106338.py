# Include the iostream library for input/output operations
import sys

# The main function is the entry point of the program
def main():
    # Declare three integer variables: i for the loop counter, t for the user input, and n for the number of items
    i = 0
    t = 0
    n = 0

    # The for loop runs 4 times, each time reading user input and processing it accordingly
    for i in range(0, 4):
        t, n = input().split() # Read two integers from the user: t and n

        # Check the value of t and process the input accordingly
        if t == "1":
            print(6000*int(n)) # If t is 1, print the result of multiplying n by 6000 and ending the line
        elif t == "2":
            print(4000*int(n)) # If t is 2, print the result of multiplying n by 4000 and ending the line
        elif t == "3":
            print(3000*int(n)) # If t is 3, print the result of multiplying n by 3000 and ending the line
        elif t == "4":
            print(2000*int(n)) # If t is 4, print the result of multiplying n by 2000 and ending the line

# The entry point of the program
if __name__ == "__main__":
    main()

