def main():
    a, b, c = map(int, input().split())  # Read three integers from the user and store them in variables a, b, and c
    
    if a < b < c:  # Check if a is less than b and b is less than c
        print("Yes")  # Print "Yes" if the condition is true
    else:
        print("No")  # Print "No" if the condition is not met

main()  # Call the main function to execute the program

