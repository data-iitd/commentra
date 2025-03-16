import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin

    def main(self):
        n, k = map(int, self.sc.readline().split())
        bb = list(map(int, self.sc.readline().split()))

        # Initialize an array to store the result
        aa = [0] * n
        m = 0

        # Process the array bb in reverse order
        for a in range(n - 1, -1, -1):
            j = 0
            while bb[a] > 0:
                if aa[j] >= a + k:
                    bb[a] -= 1
                j += 1
            
            for j_ in range(m, j, -1):
                aa[j_] = aa[j_ - 1]
            aa[j] = a
            m += 1

        # Print the contents of the array aa, incrementing each element by 1
        print(" ".join(str(aa[i] + 1) for i in range(n)))

if __name__ == "__main__":
    o = Main()
    o.main()

# <END-OF-CODE>
