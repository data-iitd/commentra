import sys

def main():
    input_reader = sys.stdin
    print_writer = sys.stdout

    f = Fast()
    f.sol(input_reader, print_writer)

class Fast:
    def sol(self, input_reader, print_writer):
        s = input_reader.readline().strip()
        cum = [0] * (len(s) + 1)
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cum[i] = cum[i - 1] + 1
            else:
                cum[i] = cum[i - 1]
        q = int(input_reader.readline().strip())
        for _ in range(q):
            l, r = map(int, input_reader.readline().strip().split())
            print_writer.write(str(cum[r - 1] - cum[l - 1]) + '\n')

if __name__ == "__main__":
    main()
