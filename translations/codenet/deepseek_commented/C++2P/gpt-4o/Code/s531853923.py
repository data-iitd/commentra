# Main function to execute the program
def main():
    # Read four integers from the standard input
    a, b, c, d = map(int, input().split())
    
    # Check if the product of a and b is odd and if the sum of c and d is also odd
    if (a * b) % 2 == 1 and (c + d) % 2 == 1:
        # If both conditions are true, print "No"
        print("No")
    else:
        # Otherwise, print "Yes"
        print("Yes")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
