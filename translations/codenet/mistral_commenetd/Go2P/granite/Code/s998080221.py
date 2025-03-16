

import bufio
import os
import sys

def main():
    reader = bufio.NewReader(sys.stdin)
    writer = bufio.NewWriter(sys.stdout)

    N, K = map(int, reader.readline().split())
    A = list(map(int, reader.readline().split()))

    max_profit = 0
    max_cnt = 0
    max_a = A[-1]
    for i in range(N - 2, -1, -1):
        profit = max(0, max_a - A[i])
        if max_profit < profit:
            max_profit = profit
            max_cnt = 1
        elif max_profit == profit:
            max_cnt += 1
        max_a = max(max_a, A[i])

    writer.write(str(max_cnt))
    writer.write("\n")
    writer.flush()

if __name__ == "__main__":
    main()

