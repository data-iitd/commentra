#include <stdio.h>
#include <string.h>

#define MAX_N 111111
#define MAX_K 222222

#define MAX(a, b) (a > b ? a : b)

def main():
    # Declare variables for input and results
    n, k, t, i, p, ret = 0, 0, 0, 0, 0, 0

    # Infinite loop to continuously read input until termination condition
    while True:
        # Read values for n and k
        n, k = map(int, input().split())
        
        # Break the loop if both n and k are zero
        if not n and not k: break

        # Initialize data and seq arrays to zero
        data = [0] * (MAX_N + 1)
        seq = [0] * (MAX_K + 1)

        # Read k integers and count their occurrences in the data array
        for i in range(k):
            t = int(input())
            data[t] += 1

        # Initialize pointer for the sequence array
        p = 0

        # Build the seq array based on the data array
        for i in range(1, n + 1):
            # If the current index has data, increment the sequence count
            if data[i]:
                seq[p] += 1
            else:
                # If no data, move the pointer by 2
                p += 2

        # Increment pointer to account for the last sequence
        p += 1

        # Calculate the maximum sequence length based on the presence of data[0]
        if data[0]:
            # If data[0] exists, consider sequences with gaps
            for i in range(p):
                ret = MAX(ret, seq[i] + seq[i + 2] + 1)
        else:
            # If data[0] does not exist, consider sequences without gaps
            for i in range(p):
                ret = MAX(ret, seq[i])

        # Print the maximum sequence length found
        print(ret)

if __name__ == "__main__":
    main()

