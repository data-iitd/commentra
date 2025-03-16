
import sys

# Constructor initializes the output stream and the scanner
def __init__(self):
    self.out = sys.stdout
    self.sc = Scanner(sys.stdin)

# Main method reads two integers, n and k, from the input
def main(self):
    n = self.sc.nextInt()
    k = self.sc.nextInt()
    bb = [self.sc.nextInt() for _ in range(n)]

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

    # Print the contents of the array aa, incrementing each element by 1
    for i in range(n):
        self.out.write(str(aa[i] + 1) + " ")
    self.out.write("\n")

# Instantiate the Main class and call the main method
Main().main()