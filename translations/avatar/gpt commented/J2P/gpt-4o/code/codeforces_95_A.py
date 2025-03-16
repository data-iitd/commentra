class Main:
    def __init__(self):
        pass

    def compare(self, aa, i, bb, j, m):
        while m > 0:
            a = aa[i].upper()
            b = bb[j].upper()
            if a != b:
                return ord(a) - ord(b)
            i += 1
            j += 1
            m -= 1
        return 0

    def main(self):
        import sys
        input = sys.stdin.read
        data = input().splitlines()
        
        n = int(data[0])  # Read the number of strings
        ss = [data[i + 1] for i in range(n)]  # Read each string
        
        cc = list(data[n + 1])  # Read the character array to be modified
        m = len(cc)
        
        c = data[n + 2]  # Read the character to be replaced
        c_ = c.upper()
        
        a = 'b' if c == 'a' else 'a'
        a_ = a.upper()
        
        lucky = [False] * m  # Array to track positions that can be marked as lucky
        
        for j in range(m):
            for i in range(n):
                l = len(ss[i])
                if m - j >= l and self.compare(cc, j, ss[i], 0, l) == 0:
                    for h in range(l):
                        lucky[j + h] = True
        
        for j in range(m):
            if lucky[j]:
                if cc[j].lower() == c:
                    cc[j] = a_ if cc[j].isupper() else a
                else:
                    cc[j] = c_ if cc[j].isupper() else c
        
        print(''.join(cc))  # Print the modified character array

if __name__ == "__main__":
    Main().main()

# <END-OF-CODE>
