import sys

def main():
    n, k = map(int, sys.stdin.readline().split())
    a = sys.stdin.readline().strip()
    
    if k > n // 2:
        while k < n:
            print("RIGHT")
            k += 1
    else:
        while k > 1:
            print("LEFT")
            k -= 1
    
    if k == 1:
        for i in range(len(a)):
            print(f"PRINT {a[i]}")
            if i < len(a) - 1:
                print("RIGHT")
    
    else:
        for i in range(len(a) - 1, -1, -1):
            print(f"PRINT {a[i]}")
            if i > 0:
                print("LEFT")

if __name__ == "__main__":
    main()
