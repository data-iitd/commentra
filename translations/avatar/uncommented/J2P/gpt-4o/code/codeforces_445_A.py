import sys

def main():
    inp = sys.stdin.readline().strip().split()
    n = int(inp[0])
    m = int(inp[1])
    ans = []

    for i in range(n):
        str_input = sys.stdin.readline().strip()
        temp = []

        for j in range(m):
            if str_input[j] == '-':
                temp.append('-')
            else:
                if (i + j) % 2 == 1:
                    temp.append('W')
                else:
                    temp.append('B')

        ans.append(''.join(temp))

    for line in ans:
        print(line)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
