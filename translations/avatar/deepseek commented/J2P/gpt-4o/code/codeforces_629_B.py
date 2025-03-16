def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])  # Read the number of entries
    FfriendPerDay = [0] * 367  # Array to store the number of female friends per day
    MfriendPerDay = [0] * 367  # Array to store the number of male friends per day
    answer = 0  # Variable to store the maximum number of friends on any single day

    # Loop through each entry
    for i in range(1, n + 1):
        entry = data[i].split()
        c = entry[0]  # Read the gender (M or F)
        a = int(entry[1])  # Read the start day
        b = int(entry[2])  # Read the end day

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
# <END-OF-CODE>
