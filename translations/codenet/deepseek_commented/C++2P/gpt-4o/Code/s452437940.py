# Main function is the entry point of the program
def main():
    # Read three long long integers from standard input
    a, b, x = map(int, input().split())
    
    # Calculate the number of multiples of x between a and b inclusive
    s = (b // x - a // x)
    
    # Check if a is a multiple of x and adjust the count accordingly
    if a % x == 0:
        s += 1
    
    # Print the result
    print(s)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
