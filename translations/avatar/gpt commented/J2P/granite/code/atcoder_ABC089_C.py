
import sys

def main():
    # Read the number of strings
    n = int(input())
    # Initialize an array to count occurrences of specific starting letters
    cnt = [0] * 5
    # Process each string input
    for i in range(n):
        str = input()
        # Increment the count based on the first character of the string
        if str[0] == 'M':
            cnt[0] += 1
        elif str[0] == 'A':
            cnt[1] += 1
        elif str[0] == 'R':
            cnt[2] += 1
        elif str[0] == 'C':
            cnt[3] += 1
        elif str[0] == 'H':
            cnt[4] += 1
    # Calculate the result based on combinations of counts
    res = cnt[0] * cnt[1] * cnt[2] + \
           cnt[0] * cnt[1] * cnt[3] + \
           cnt[0] * cnt[1] * cnt[4] + \
           cnt[0] * cnt[2] * cnt[3] + \
           cnt[0] * cnt[2] * cnt[4] + \
           cnt[0] * cnt[3] * cnt[4] + \
           cnt[1] * cnt[2] * cnt[3] + \
           cnt[1] * cnt[2] * cnt[4] + \
           cnt[1] * cnt[3] * cnt[4] + \
           cnt[2] * cnt[3] * cnt[4]
    # Output the result
    print(res)

if __name__ == "__main__":
    main()
