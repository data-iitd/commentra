import sys

def main():
    n = int(sys.stdin.readline().strip())
    a = 0
    b = 0
    c = 0
    
    for _ in range(n):
        a += int(sys.stdin.readline().strip())
    
    for _ in range(n - 1):
        b += int(sys.stdin.readline().strip())
    
    for _ in range(n - 2):
        c += int(sys.stdin.readline().strip())
    
    x = a - b
    y = b - c
    
    print(x)
    print(y)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
