def main():
    a, b, c, x = map(int, input().split())  # Read input values for a, b, c, and x
    sum = 0  # Initialize a variable to store the result

    # Nested loops to iterate through all combinations of coins
    for i in range(a + 1):
        for j in range(b + 1):
            for k in range(c + 1):
                if 500 * i + 100 * j + 50 * k == x:  # Check if the total value equals the target value
                    sum += 1  # Increment the sum if the condition is met

    print(sum)  # Output the number of combinations that meet the condition

if __name__ == "__main__":
    main()

# <END-OF-CODE>
