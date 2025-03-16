N = 1000000
Q = 50000

def binary_search(S, key):
    left, right = 0, len(S)
    while left < right:
        mid = (left + right) // 2
        if S[mid] == key:
            return 1
        elif key < S[mid]:
            right = mid
        else:
            left = mid + 1
    return 0

def main():
    n = int(input())
    S = list(map(int, input().split()))
    
    q = int(input())
    T = list(map(int, input().split()))
    
    c = 0
    for i in range(q):
        if binary_search(S, T[i]) == 1:
            c += 1
    
    print(c)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
