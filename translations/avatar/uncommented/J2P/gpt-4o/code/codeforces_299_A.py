import sys

def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    min_value = a[0]
    
    for value in a:
        if value % min_value != 0:
            print(-1)
            return
            
    print(min_value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
