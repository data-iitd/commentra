import sys

def get_next_word(scanner):
    return next(scanner)

def get_next_int(scanner):
    return int(get_next_word(scanner))

def main():
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1])

    scanner = iter(fp.read().split())
    
    n = get_next_int(scanner)
    m = get_next_int(scanner)
    aa = set()
    for _ in range(m):
        aa.add(get_next_int(scanner))

    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(n):
        for ii in range(1, 3):
            if i + ii <= n:
                if (i + ii) in aa:
                    continue
                dp[i + ii] = (dp[i + ii] + dp[i]) % 1000000007

    print(dp[n])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
