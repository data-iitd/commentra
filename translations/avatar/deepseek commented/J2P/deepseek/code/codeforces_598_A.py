def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    q = int(data[0])
    index = 1
    
    for _ in range(q):
        n = int(data[index])
        index += 1
        
        x = int(math.log2(n)) + 1
        s = -1 * (2 ** x) + 2 + (n * (n + 1) // 2) - (2 ** x)
        
        print(s)

import math
if __name__ == "__main__":
    main()
