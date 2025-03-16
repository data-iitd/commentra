def main():
    # Read the number of characters
    n = int(input())

    # Read the sequence of characters
    s = input().strip()

    # Create a list to hold the numeric representation of colors
    ns = [0] * n
    # Convert characters to their respective numeric values
    for i in range(n):
        if s[i] == 'R':
            ns[i] = 0  # 'R' is represented as 0
        elif s[i] == 'G':
            ns[i] = 1  # 'G' is represented as 1
        elif s[i] == 'B':
            ns[i] = 2  # 'B' is represented as 2

    # Create a 2D list to hold cumulative counts of each color up to each index
    rgb = [[0] * 3 for _ in range(n + 1)]  # Initialize the first row with zero counts

    # Populate the cumulative counts for each color
    for i in range(1, n + 1):
        for j in range(3):
            rgb[i][j] = rgb[i - 1][j]  # Carry forward the previous counts
        rgb[i][ns[i - 1]] += 1  # Increment the count for the current color

    # Variable to hold the total count of valid triplets
    total_count = 0

    # Iterate through all pairs of indices to find valid triplets
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            # Check if the colors at indices i and j are different
            if ns[i] != ns[j]:
                # Determine the third color that completes the triplet
                tn = 3 - ns[i] - ns[j]
                # Count how many times the third color appears after index j
                total_count += rgb[n][tn] - rgb[j + 1][tn]
                # Check if the third color appears at the position k
                k = 2 * j - i
                if k < n and ns[k] == tn:
                    total_count -= 1  # Adjust the count if the third color is at position k

    # Output the total count of valid triplets
    print(total_count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
