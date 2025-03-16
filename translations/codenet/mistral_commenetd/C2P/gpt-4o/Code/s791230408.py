def main():
    j = int(input("Enter the number of test cases: "))  # Prompt user to enter the number of test cases

    for i in range(j):  # Loop through each test case
        a, b, c = map(int, input(f"Enter the values of a, b, and c for test case {i + 1}: ").split())  # Read values of a, b, and c

        max_value = a  # Initialize max with the value of a
        k = 0  # Initialize k with 0

        if max_value <= b:  # Check if max is less than or equal to b
            max_value = b  # If true, update max with the value of b
            k = 1  # Set k to 1 to indicate that b is greater than a

        if max_value <= c:  # Check if max is less than or equal to c
            max_value = c  # If true, update max with the value of c
            k = 2  # Set k to 2 to indicate that c is greater than max (which was previously a or b)

        max_value *= max_value  # Calculate max*max
        a *= a  # Calculate a*a
        b *= b  # Calculate b*b
        c *= c  # Calculate c*c

        if k == 0 and max_value == b + c:  # Check if k is 0 and max is equal to the sum of b and c
            print("YES")  # Print "YES" to the console
        elif k == 1 and max_value == a + c:  # Check if k is 1 and max is equal to the sum of a and c
            print("YES")  # Print "YES" to the console
        elif k == 2 and max_value == a + b:  # Check if k is 2 and max is equal to the sum of a and b
            print("YES")  # Print "YES" to the console
        else:  # If none of the above conditions are true
            print("NO")  # Print "NO" to the console

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
