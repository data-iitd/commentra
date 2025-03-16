import sys
from collections import defaultdict

def read_int():
    return int(sys.stdin.readline().strip())

def main():
    m = defaultdict(int)
    N = read_int()
    M = read_int()
    
    for _ in range(N):
        m[read_int()] += 1
    
    for _ in range(M):
        B, C = read_int(), read_int()
        m[C] += B
    
    ints = list(m.keys())
    ints.sort(reverse=True)
    
    rest = N
    total_sum = 0
    
    for i in ints:
        num = m[i]
        if num >= rest:
            total_sum += rest * i
            break
        total_sum += num * i
        rest -= num
    
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
