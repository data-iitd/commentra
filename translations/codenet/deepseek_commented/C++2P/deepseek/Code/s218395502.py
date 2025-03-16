def main():
    # Step 4: Read input values from the user
    a, b, c = map(int, input().split())

    # Step 5: Calculate the number formed by the digits a, b, and c
    number = 100 * a + 10 * b + c

    # Step 6: Check if the number is divisible by 4
    if number % 4 == 0:
        # Output the result if the number is divisible by 4
        print("YES")
    else:
        # Output the result if the number is not divisible by 4
        print("NO")


main()
