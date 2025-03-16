def max(a, b):
    if a > b:
        return a
    return b

# Declare global arrays to store data and sequences
data = [0] * 111111  # Array to store the frequency of each number
seq = [0] * 222222  # Array to store sequences of consecutive numbers

# Main function to process input and output results
def main():
    while True:
        # Read values of n and k
        n, k = map(int, input().split())
        if n == 0 and k == 0:
            break  # Break the loop if both n and k are zero

        # Initialize the data and seq arrays to zero
        data = [0] * 111111
        seq = [0] * 222222

        # Read k numbers and store their frequencies in data
        for _ in range(k):
            t = int(input())
            data[t] += 1

        # Construct the seq array based on the frequencies in data
        p = 0
        for i in range(1, n + 1):
            if data[i]:
                seq[p] += 1
            else:
                p += 2
        p += 1

        # Calculate the maximum value of ret based on the sequences in seq
        ret = 0
        if data[0]:
            for i in range(p):
                ret = max(ret, seq[i] + seq[i + 2] + 1)
        else:
            for i in range(p):
                ret = max(ret, seq[i])

        # Print the result
        print(ret)

# Call the main function
main()
