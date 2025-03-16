
import sys

# Constructor to initialize the superclass with sys.stdout and auto-flush enabled
class Main(object):
    def __init__(self):
        super(Main, self).__init__(sys.stdout)
        self.flush = True

    # Scanner object to read input from sys.stdin
    sc = None

    # Main method which is overridden and calls another main method within the class
    def main(self):
        self.sc = Scanner(sys.stdin)
        self.main()
        self.flush = False

    # Compares two character arrays up to a specified length, ignoring case
    def compare(self, aa, i, bb, j, m):
        while m > 0:
            a = aa[i].upper()
            b = bb[j].upper()
            if a!= b:
                return ord(a) - ord(b)
            i += 1
            j += 1
            m -= 1
        return 0

    # Main logic of the program
    def main(self):
        # Reading the number of strings and the array of strings
        n = self.sc.nextInt()
        ss = [self.sc.next().upper() for _ in range(n)]

        # Reading the pattern array and the target character
        cc = self.sc.next().upper()
        m = len(cc)
        c = self.sc.next()
        c_ = c.upper()
        a = 'A' if c == 'a' else 'B'
        a_ = a.lower()

        # Array to mark positions in cc that match any string in ss
        lucky = [False] * m

        # Finding lucky positions and updating characters based on the target character c
        for j in range(m):
            for i in range(n):
                l = len(ss[i])
                if m - j >= l and self.compare(cc, j, ss[i], 0, l) == 0:
                    for h in range(l):
                        lucky[j + h] = True

        # Updating characters in cc based on the lucky positions and target character c
        for j in range(m):
            if lucky[j]:
                if cc[j] == c_:
                    cc[j] = a_
                else:
                    cc[j] = a

        # Printing the modified cc array
        print(''.join(cc))

# Instantiate the Main class and call the main method
Main().main()

