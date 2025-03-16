
import sys

class Main:
    N = 200 + 10
    f = [0] * N
    b = [0] * N

    # Computes the failure array for the given pattern
    def getFail(b, m):
        j = 0
        f[0] = f[1] = 0
        for i in range(2, m + 1):
            while j > 0 and b[j + 1]!= b[i]:
                j = f[j]
            if b[j + 1] == b[i]:
                j += 1
            f[i] = j

    # Main function
    def main(self):
        # Read input values
        n = int(sys.stdin.readline())
        s1 = sys.stdin.readline().strip()
        str = sys.stdin.readline().strip()

        # Construct a combined string
        cnt = 0
        for i in range(0, n):
            b[cnt + 1] = str[i]
            cnt += 1
        for i in range(0, n):
            b[cnt + 1] = s1[i]
            cnt += 1

        # Compute the failure array for the combined string
        self.getFail(b, cnt)

        # Calculate the result based on the failure array
        len = min(f[cnt], min(n, n))

        # Print the result
        print(2 * n - len)

# 