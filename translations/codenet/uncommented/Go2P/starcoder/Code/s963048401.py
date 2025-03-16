import sys

def main():
    n = int(sys.stdin.readline())
    as = [int(x) for x in sys.stdin.readline().split()]
    xs = [as[0]]
    for j in range(1, n):
        idx = bisect.bisect_left(xs, as[j])
        if idx == len(xs):
            xs.append(as[j])
        else:
            xs[idx] = as[j]
    print(len(xs))

if __name__ == '__main__':
    main()

