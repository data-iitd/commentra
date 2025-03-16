
import sys

def get_scanner(fp):
    scanner = fp.split()
    return scanner

def get_next_string(scanner):
    return scanner.pop(0)

def get_next_int(scanner):
    return int(get_next_string(scanner))

def get_next_int64(scanner):
    return int(get_next_string(scanner), 10)

def get_next_uint64(scanner):
    return int(get_next_string(scanner), 10)

def get_next_float64(scanner):
    return float(get_next_string(scanner))

def main():
    fp = sys.stdin
    wfp = sys.stdout

    if len(sys.argv) > 1:
        fp = open(sys.argv[1])
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')

    scanner = get_scanner(fp)
    writer = wfp

    n = get_next_int(scanner)
    ll = [0] * n

    for i in range(n):
        ll[i] = get_next_int(scanner)

    ll.sort()

    ans = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            l = j + 1
            r = n
            while l < r:
                m = (l + r) >> 1
                if ll[m] < ll[i] + ll[j]:
                    l = m + 1
                    continue
                r = m
            ans += l - (j + 1)

    print(ans)

if __name__ == '__main__':
    main()

