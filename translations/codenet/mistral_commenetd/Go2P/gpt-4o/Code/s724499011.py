def main():
    # Initialize variables
    n = int(input())  # Read the number of elements in the string 's'
    s = input().encode()  # Read the string 's' as bytes
    ns = [0] * n  # Create a list 'ns' of length 'n' to store the color index for each character in 's'

    # Read the string 's' into 'ns'
    for i in range(n):
        # Assign color index to 'ns' based on the character in 's'
        if s[i] == b'R'[0]:
            ns[i] = 0
        elif s[i] == b'G'[0]:
            ns[i] = 1
        elif s[i] == b'B'[0]:
            ns[i] = 2

    # Initialize 'rgb' list with zeros
    rgb = [[0] * 3 for _ in range(n + 1)]  # First row of 'rgb' list to store the total RGB values for each color
    for i in range(1, n + 1):
        # Initialize each inner row of 'rgb' list with values from the previous row
        rgb[i] = rgb[i - 1][:]
        # Increment the value of the cell in the current row and column based on the color index of the previous character
        rgb[i][ns[i - 1]] += 1

    # Calculate the sum of differences between adjacent rows in 'rgb' list
    total_sum = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            # Check if the characters in the current and next indices have different colors
            if ns[i] != ns[j]:
                # Calculate the total difference between the corresponding cells in the 'rgb' list
                tn = 3 - ns[i] - ns[j]
                total_sum += rgb[n][tn]  # Get the total RGB value of the last cell in the last row with the complementary color
                total_sum -= rgb[j + 1][tn]  # Subtract the total RGB value of the first cell in the next row with the complementary color

                # Check if there is a character with the same color index between the current and next indices
                k = 2 * j - i
                if k < n and ns[k] == tn:
                    total_sum -= 1  # Decrease the sum if there is a character with the same color index between the current and next indices

    # Print the final result
    print(total_sum)

# Call the main function
if __name__ == "__main__":
    main()
# <END-OF-CODE>
