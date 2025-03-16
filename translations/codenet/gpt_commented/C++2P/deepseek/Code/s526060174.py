def main():
    # Read the number of groups (n) and the maximum number (m)
    n, m = map(int, input().split())

    # Array to count occurrences of each number from 1 to m
    x = [0] * 31

    # Loop through each group
    for _ in range(n):
        # Read the number of elements in the current group
        k = int(input())
        # Loop through each element in the current group
        for _ in range(k):
            # Read the element and increment its count in the array
            a = int(input())
            x[a] += 1

    # Initialize the answer variable to count how many numbers appear in all groups
    ans = 0

    # Check each number from 1 to m
    for i in range(1, m + 1):
        # If the number appears in all n groups, increment the answer
        if x[i] == n:
            ans += 1

    # Output the final count of numbers that appeared in all groups
    print(ans)


main()
