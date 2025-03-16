
# Function main is the entry point of the program
def main():
    # Declare and initialize two integer variables n and m using input
    n, m = input(), input()

    # Calculate the value of x using the given formula
    x = m*1900 + (n-m)*100

    # Print the result using print
    print(x * 2**m)

# Call the main function
main()

