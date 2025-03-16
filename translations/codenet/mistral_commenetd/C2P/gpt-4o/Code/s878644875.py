# Include the standard input/output library

def main():  # Declare the main function
    s = input()  # Read a string from the standard input and store it in variable s
    t = input()  # Read a string from the standard input and store it in variable t
    hit = 0  # Initialize a counter variable hit to 0
    for i in range(3):  # Start a for loop that iterates from 0 to 2 (3 times)
        if s[i] == t[i]:  # If the i-th character of string s is equal to the i-th character of string t
            hit += 1  # Increment the counter variable hit
    print(hit)  # Print the value of the counter variable hit to the standard output

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
