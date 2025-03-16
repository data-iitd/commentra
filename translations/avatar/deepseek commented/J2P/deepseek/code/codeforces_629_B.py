import sys

def main():
    # Read the number of entries
    n = int(input().strip())
    # Initialize lists to store the number of female and male friends per day
    FfriendPerDay = [0] * 367
    MfriendPerDay = [0] * 367
    answer = 0

    # Loop through each entry
    for _ in range(n):
        # Read the gender (M or F) and the start and end days
        c, a, b = input().strip().split()
        a, b = int(a), int(b)

        # Update the friend counts for each day in the range
        for j in range(a, b + 1):
            if c == 'M':
                MfriendPerDay[j] += 1  # Increment male friend count
            else:
                FfriendPerDay[j] += 1  # Increment female friend count

            # Determine which gender has the lower count and update the answer
            if MfriendPerDay[j] < FfriendPerDay[j]:
                if MfriendPerDay[j] > answer:
                    answer = MfriendPerDay[j]  # Update answer if current male count is greater
            else:
                if FfriendPerDay[j] > answer:
                    answer = FfriendPerDay[j]  # Update answer if current female count is greater

    # Output the result, which is twice the maximum number of friends on any single day
    print(answer * 2)

if __name__ == "__main__":
    main()
