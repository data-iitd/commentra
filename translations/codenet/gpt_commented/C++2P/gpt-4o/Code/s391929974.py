def main():
    while True:
        n = int(input())  # Read an integer from input
        if n == 0:  # Exit the loop if the input is zero
            break

        # Calculate the squares of numbers from 1 to n-1 modulo n
        sq = [(i * i) % n for i in range(1, n)]
        com = []  # List to store unique square values

        # Collect unique square values into the list 'com'
        for value in sq:
            if value not in com:  # Check if the square is unique
                com.append(value)  # Add to 'com' if unique

        # Initialize frequency list to count occurrences of differences
        fr = [0] * ((n - 1) // 2 + 1)

        # Calculate the frequency of differences between unique squares
        for i in range(len(com)):
            for j in range(len(com)):
                if i != j:  # Ensure we are not comparing the same element
                    tmp = com[i] - com[j]  # Calculate the difference
                    if tmp < 0:
                        tmp += n  # Adjust if negative
                    if tmp > (n - 1) // 2:
                        tmp = n - tmp  # Adjust to be within the range
                    fr[tmp] += 1  # Increment the frequency count for this difference

        # Output the frequency counts for differences from 1 to (n-1)/2
        for i in range(1, (n - 1) // 2 + 1):
            print(fr[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
