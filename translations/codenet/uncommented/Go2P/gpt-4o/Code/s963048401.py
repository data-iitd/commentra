import sys
import bisect

def int_scanner():
    return int(sys.stdin.readline().strip())

def main():
    mod = 1000000007
    n = int_scanner()
    as_list = [int_scanner() for _ in range(n)]
    
    xs = [as_list[0]]
    for j in range(1, n):
        idx = bisect.bisect_left(xs, as_list[j])
        if idx == len(xs):
            xs.append(as_list[j])
        else:
            xs[idx] = as_list[j]
    
    print(len(xs))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
