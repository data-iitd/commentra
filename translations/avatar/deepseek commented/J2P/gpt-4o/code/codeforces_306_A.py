def main():
    # Read the values of n and m from the user
    n = int(input())
    m = int(input())

    # Initialize a list of size m
    a = [0] * m

    # Check if n is divisible by m
    if n % m == 0:
        # Fill the list with equal parts if n is divisible by m
        for i in range(len(a)):
            a[i] = n // m
    else:
        # Calculate the base part size
        sub = n // m

        # Fill the list with the base part size
        for i in range(len(a)):
            a[i] = sub

        # Distribute the remainder
        test = n - (sub * m)
        count = 0
        for i in range(test):
            a[count] += 1
            count += 1
            if count >= len(a):
                count = 0

    # Print the list elements in reverse order
    for i in range(len(a) - 1, -1, -1):
        print(a[i], end=" ")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
