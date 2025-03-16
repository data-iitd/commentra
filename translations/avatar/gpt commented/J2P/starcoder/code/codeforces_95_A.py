import sys
import string

class Main:
    def __init__(self, out=sys.stdout, verbose=False):
        self.out = out
        self.verbose = verbose

    def flush(self):
        self.out.flush()

    def println(self, *args, **kwargs):
        print(*args, **kwargs, file=self.out)

    def main(self):
        # Read the number of strings
        n = int(input())
        ss = []

        # Read each string and convert it to a character array
        for i in range(n):
            ss.append(input().strip())

        # Read the character array to be modified
        cc = input().strip()
        m = len(cc)

        # Read the character to be replaced
        c = input().strip()
        c_ = c.upper()

        # Determine the character to replace with
        a = c == 'a' and 'b' or 'a'
        a_ = a.upper()

        # Array to track positions that can be marked as lucky
        lucky = [False] * m

        # Loop through each position in the character array
        for j in range(m):
            for i in range(n):
                l = len(ss[i])
                # Check if the substring matches and mark lucky positions
                if m - j >= l and cc[j:j+l] == ss[i]:
                    for h in range(l):
                        lucky[j + h] = True

        # Replace characters in the original array based on lucky positions
        for j in range(m):
            if lucky[j]:
                # Replace with the determined character based on case
                if cc[j].lower() == c:
                    cc = cc[:j] + (a_ if cc[j].isupper() else a) + cc[j+1:]
                else:
                    cc = cc[:j] + (c_ if cc[j].isupper() else c) + cc[j+1:]

        # Print the modified character array
        self.println(cc)

if __name__ == '__main__':
    m = Main()
    m.main()
    m.flush()

