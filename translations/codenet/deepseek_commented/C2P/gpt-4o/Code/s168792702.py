# Define the main function
def main():
    # Read three integers from the user and store them in variables a, b, and c
    a, b, c = map(int, input().split())
    
    # Check if a is less than b and b is less than c, and print "Yes" if true
    if a < b and b < c:
        print("Yes")  # Print "Yes" if the condition is met
    else:
        print("No")   # Print "No" if the condition is not met

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
