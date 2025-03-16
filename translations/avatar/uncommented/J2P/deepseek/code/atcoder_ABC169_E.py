import sys
import math

def main():
    num = 998244353
    input_line = sys.stdin.readline().strip()
    n = int(input_line)
    
    ai = []
    bi = []
    
    for _ in range(n):
        input_line = sys.stdin.readline().strip()
        a, b = map(int, input_line.split())
        ai.append(a)
        bi.append(b)
    
    ai.sort()
    bi.sort()
    
    if n % 2 == 1:
        print(bi[n // 2] - ai[n // 2] + 1)
    else:
        b = (ai[n // 2] + ai[n // 2 - 1]) / 2
        c = (bi[n // 2] + bi[n // 2 - 1]) / 2
        print(math.floor(2 * (c - b) + 1))

if __name__ == "__main__":
    main()
