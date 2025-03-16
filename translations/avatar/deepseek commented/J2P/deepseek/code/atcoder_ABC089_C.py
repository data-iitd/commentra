import sys
import itertools

def main():
    n = int(sys.stdin.readline().strip())
    cnt = [0] * 5
    # Read the number of strings and initialize the count array.

    for _ in range(n):
        str = sys.stdin.readline().strip()
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
        # Count the occurrences of each character at the start of the strings.

    res = 0
    for a, b, c in itertools.combinations(cnt, 3):
        res += a * b * c
    # Calculate the number of combinations and print the result.

    print(res)

if __name__ == "__main__":
    main()

