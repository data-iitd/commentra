# Include the standard input/output library

def main():  # Start of the main function
    a, b, c, x, y = map(int, input().split())  # Read five integers from the standard input and store them in variables a, b, c, x, and y

    c *= 2  # Multiply the value of variable c by 2

    if a + b <= c:  # Check if the sum of variables a and b is less than or equal to the value of variable c
        print(a * x + b * y)  # If the condition is true, print the result of multiplying variables a and x, and variables b and y

    else:  # If the condition in the if statement is false, execute the code in the else block

        if x <= y:  # Check if the value of variable x is less than or equal to the value of variable y

            if b <= c:  # Check if the value of variable b is less than or equal to the value of variable c
                print(c * x + (y - x) * b)  # If both conditions in the nested if statement are true, print the result
            else:  # If the first condition in the nested if statement is false, execute the code in this else block
                print(c * y)  # Print the result of multiplying variable c by the value of variable y

        else:  # If the condition in the outer if statement is false and the condition in the if statement that checks if x is less than or equal to y is also false, execute the code in this else block

            if a <= c:  # Check if the value of variable a is less than or equal to the value of variable c
                print(c * y + (x - y) * a)  # If the condition is true, print the result
            else:  # If the condition in the if statement that checks if a is less than or equal to c is false, execute the code in this else block
                print(c * x)  # Print the result of multiplying variable c by the value of x

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
