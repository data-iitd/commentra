def main():
    # Read the input values
    n, m = map(int, input().split())

    # Check if n is 0
    if n == 0:
        if m != 0:
            print("Impossible")
        else:
            print("0 0")
        return

    # If n is not 0, check if m is less than or equal to n
    if m <= n:
        if m == 0:
            m = 1
        print(n, m + n - 1)
        return

    # If m is greater than n, print the values of m and m + n - 1
    print(m, m + n - 1)


# Call the main function
main()
