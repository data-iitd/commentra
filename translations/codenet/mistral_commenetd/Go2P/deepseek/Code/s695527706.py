# The main function is the entry point of the program
def main():
    # Read the input from the standard input
    n, s = input().split()
    n = int(n)
    
    # Convert the string s to an integer
    s = int(s)
    
    # Call the strings.Count function to count the number of occurrences of "ABC" in the string s
    # Print the result using the print function
    print(s.count("ABC"))

# This is the entry point of the program
if __name__ == "__main__":
    main()
