
import sys

def main():
    # Read the number of entries
    n = int(input())

    # Initialize the arrays
    FfriendPerDay = [0] * 367
    MfriendPerDay = [0] * 367

    # Read each entry
    for i in range(n):
        c = input().strip()
        a = int(input())
        b = int(input())

        # Update the friend counts for each day in the range
        for j in range(a, b+1):
            if c == 'M':
                MfriendPerDay[j] += 1
            else:
                FfriendPerDay[j] += 1

            # Determine which gender has the lower count and update the answer
            if MfriendPerDay[j] < FfriendPerDay[j]:
                if MfriendPerDay[j] > answer:
                    answer = MfriendPerDay[j]
            else:
                if FfriendPerDay[j] > answer:
                    answer = FfriendPerDay[j]

    # Output the result, which is twice the maximum number of friends on any single day
    print(answer * 2)

if __name__ == "__main__":
    main()

