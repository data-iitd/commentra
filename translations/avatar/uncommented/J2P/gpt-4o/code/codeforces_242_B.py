import sys

INF = int(1e9) + 5

def main():
    n = int(input())
    a = []
    b = []
    left = INF
    right = 0
    
    for i in range(n):
        a_i = int(input())
        b_i = int(input())
        a.append(a_i)
        b.append(b_i)
        left = min(left, a_i)
        right = max(right, b_i)
    
    for i in range(n):
        if left == a[i] and right == b[i]:
            print(i + 1)
            return
    
    print(-1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
