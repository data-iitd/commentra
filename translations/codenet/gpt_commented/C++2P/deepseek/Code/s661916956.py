def main():
    # Read three integers from the user
    a, b, c = map(int, input().split())

    # Sort the integers using a simple sorting method
    if a > b:
        a, b = b, a
    if b > c:
        b, c = c, b
    if a > b:
        a, b = b, a

    # Output the sorted values of a, b, and c
    print(a, b, c)

# Call the main function
main()
