
import sys

# Constructor for the Main class
class Main:
    def __init__(self):
        self.out = sys.stdout
        self.flush = self.out.flush
        self.writable = self.out.writable
        self.write = lambda s: self.out.write(s.encode("ascii"))
        self.read = lambda: self.out.read().decode("ascii")
        self.readline = lambda: self.out.readline().decode("ascii")
        self.readlines = lambda: self.out.readlines().decode("ascii")

# Main method to compare two character arrays with case insensitivity
def compare(aa, i, bb, j, m):
    while m > 0:
        # Convert characters to uppercase for comparison
        a = aa[i].upper()
        b = bb[j].upper()
        # Return the difference if characters do not match
        if a!= b:
            return ord(a) - ord(b)
        i += 1
        j += 1
        m -= 1
    # Return 0 if all characters match
    return 0

# Main method to modify the character array based on lucky positions
def main():
    # Create an instance of Main
    o = Main()
    # Read the number of strings
    n = int(o.readline())
    # Read each string and convert it to a character array
    ss = [o.readline().rstrip() for _ in range(n)]
    # Read the character array to be modified
    cc = o.readline().rstrip()
    m = len(cc)
    # Read the character to be replaced
    c = o.readline().rstrip()[0]
    c_ = c.upper()
    # Determine the character to replace with
    a = 'a' if c == 'b' else 'b'
    a_ = a.upper()
    # Array to track positions that can be marked as lucky
    lucky = [False] * m
    # Loop through each position in the character array
    for j in range(m):
        for i in range(n):
            l = len(ss[i])
            # Check if the substring matches and mark lucky positions
            if m - j >= l and compare(cc, j, ss[i], 0, l) == 0:
                for h in range(l):
                    lucky[j + h] = True
    # Replace characters in the original array based on lucky positions
    for j in range(m):
        if lucky[j]:
            # Replace with the determined character based on case
            if cc[j].lower() == c:
                cc = cc[:j] + (a_ if cc[j].isupper() else a) + cc[j + 1:]
            else:
                cc = cc[:j] + (c_ if cc[j].isupper() else c) + cc[j + 1:]
    # Print the modified character array
    o.write(cc + '\n')

# Call the main method
if __name__ == '__main__':
    main()
