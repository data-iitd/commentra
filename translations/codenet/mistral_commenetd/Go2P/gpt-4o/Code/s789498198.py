import sys

# Initialize scanner and read the first line
class Scanner:
    def __init__(self):
        self.buf = []
        self.cur = 0
        self.readln()  # Read the first line

    def readln(self):
        line = sys.stdin.readline().strip()
        self.buf = line.split()
        self.cur = 0

    def is_full(self):
        return self.cur == len(self.buf)

    def reset_cur(self):
        self.cur = 0

    def next(self):
        if self.cur == 0:
            self.readln()
        res = self.buf[self.cur]
        self.cur += 1
        if self.is_full():
            self.reset_cur()
        return res

    def next_ints(self):
        self.readln()
        res = list(map(int, self.buf))
        self.reset_cur()
        return res

# Main function
def main():
    sc = Scanner()
    
    # Read the first two integers from the input
    AB = sc.next_ints()
    A = AB[0]
    B = AB[1]

    # Check if the sum of A and B is even
    if (A + B) % 2 == 0:
        # If it is, print the result (the average)
        print((A + B) // 2)
    else:
        # If the sum is odd, print "IMPOSSIBLE"
        print("IMPOSSIBLE")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
