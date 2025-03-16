def main():
    import sys
    input = sys.stdin.read
    data = input().strip()
    # Create two lists to manipulate the string
    a = list(data)
    b = list(data)
    # Initialize counters for the number of changes needed
    a1 = 0
    a2 = 0

    # First loop to change characters to make the string colorful
    for i in range(1, len(data)):
        if a[i] == a[i - 1]:
            # Change the character to the opposite
            a[i] = '0' if a[i] == '1' else '1'
            # Increment the counter
            a1 += 1

    # Second loop to change characters to make the string colorful
    for i in range(len(data) - 1, 0, -1):
        if b[i] == b[i - 1]:
            # Change the character to the opposite
            b[i - 1] = '0' if b[i - 1] == '1' else '1'
            # Increment the counter
            a2 += 1

    # Output the minimum number of changes needed
    print(min(a1, a2))


main()
