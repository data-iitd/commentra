# Define the main function
def main():
    # Read three long long integers from the user
    a, b, c = map(int, input().split())
    
    # Calculate the difference between c and the sum of a and b
    d = c - a - b
    
    # Check if the difference is positive and satisfies the specific condition
    if d > 0 and (4 * a * b) < d * d:
        print("Yes")  # Print "Yes" if the condition is met
    else:
        print("No")  # Print "No" otherwise

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
