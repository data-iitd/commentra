import sys

def absint(a):
    return -a if a < 0 else a

def main():
    input_file = sys.stdin
    if len(sys.argv) > 1:
        input_file = open(sys.argv[1], 'r')

    n = int(input_file.readline().strip())
    aa = [0] * (n + 2)
    sum_abs = 0

    for i in range(n):
        aa[i + 1] = int(input_file.readline().strip())
        sum_abs += absint(aa[i + 1] - aa[i])
    
    sum_abs += absint(aa[n + 1] - aa[n])

    results = []
    for i in range(1, n + 1):
        ans = sum_abs - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1])
        results.append(ans)

    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
