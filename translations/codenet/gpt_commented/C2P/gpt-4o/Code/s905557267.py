def min(a, b):
    return a if a <= b else b

def Chain(b, n):
    a = b[:]  # Copy input list b to list a

    # Loop through the array to find sequences of four identical colors
    i = 0
    while i < n - 3:
        # Check if there are four consecutive identical colors
        if a[i] != 0 and a[i] == a[i + 1] == a[i + 2] == a[i + 3]:
            count = 0
            color = a[i]

            # Set the found colors to zero and count them
            j = i
            while j < n and a[j] == color:
                a[j] = 0  # Remove the color by setting it to zero
                count += 1
                j += 1

            # Shift the remaining colors to fill the gap left by removed colors
            for j in range(n - count):
                if i + j + count < n:
                    a[i + j] = a[i + j + count]
                else:
                    a[i + j] = 0  # Set the shifted out colors to zero

            # Reset the index to start checking from the beginning
            i = 0
        else:
            i += 1

    # Count the number of remaining colors in the array
    count = 0
    while count < n and a[count] != 0:
        count += 1

    # Check if there are exactly four of the same color left at the start
    if count == 4 and a[0] == a[1] == a[2] == a[3]:
        return 0  # Return 0 if four identical colors remain

    return count  # Return the count of remaining colors

def main():
    while True:
        a = [0] * 10000  # Initialize the array to zero

        # Read the number of colors
        n = int(input())
        if n == 0:
            break  # Exit the loop if n is 0

        ans = n  # Initialize ans with the number of colors

        # Read the colors into the array
        for i in range(n):
            a[i] = int(input())

        # Check for groups of four colors to replace
        for i in range(n - 3):
            count = [0, 0, 0]  # Array to count occurrences of colors

            # Count occurrences of colors in the current window of four
            for j in range(i, i + 4):
                if a[j] - 1 >= 0:
                    count[a[j] - 1] += 1

            color = 0  # Reset color
            # Determine if any color appears at least three times
            for j in range(3):
                if count[j] >= 3:
                    color = j + 1  # Set the color to replace
                    break

            # If a color is found to replace, perform the replacement
            if color != 0:
                for j in range(i, i + 4):
                    buf = a[j]  # Store the current color
                    a[j] = color  # Replace with the new color
                    ans = min(ans, Chain(a, n))  # Calculate the new answer
                    a[j] = buf  # Restore the original color

        # Print the final answer for the current test case
        print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
