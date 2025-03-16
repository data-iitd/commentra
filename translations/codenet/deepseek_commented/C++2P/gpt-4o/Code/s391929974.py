def main():
    while True:
        n = int(input())  # Read input integer n
        if n == 0:
            break  # Break the loop if n is 0

        sq = [(i * i) % n for i in range(1, n)]  # Calculate squares modulo n
        com = []  # List to store unique squares

        for i in range(1, n):  # Find unique squares modulo n
            if sq[i - 1] not in com:  # Check if the square is already in com
                com.append(sq[i - 1])  # Add unique square to com

        fr = [0] * ((n - 1) // 2 + 1)  # Initialize frequency array

        for i in range(len(com)):  # Calculate differences between unique squares
            for j in range(len(com)):
                if i != j:  # Avoid comparing a square with itself
                    tmp = com[i] - com[j]  # Calculate difference
                    if tmp < 0:
                        tmp += n  # Adjust if tmp is negative
                    if tmp > (n - 1) // 2:
                        tmp = n - tmp  # Adjust if tmp is greater than half of n
                    fr[tmp] += 1  # Increment the count for the difference

        for i in range(1, (n - 1) // 2 + 1):
            print(fr[i])  # Output the frequencies

if __name__ == "__main__":
    main()

# <END-OF-CODE>
