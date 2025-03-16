
import sys

# Function to return the maximum of two integers
def max(a, b):
    if a > b:
        return a
    return b

# Main function to process input and print output
def main():
    for line in sys.stdin:
        n, k = map(int, line.split())
        if n == 0 and k == 0:
            break

        data = [0] * (n + 1)
        seq = []

        # Read k numbers and store their frequencies in data
        for t in map(int, input().split()):
            data[t] += 1

        # Construct the seq array based on the frequencies in data
        p = 0
        for i in range(1, n + 1):
            if data[i]:
                seq.append(seq[p] + 1)
            else:
                p += 2

        # Calculate the maximum value of ret based on the sequences in seq
        if data[0]:
            ret = max(seq[0] + seq[2] + 1, seq[-1])
        else:
            ret = max(seq[0], seq[-1])

        # Print the result
        print(ret)

if __name__ == "__main__":
    main()

