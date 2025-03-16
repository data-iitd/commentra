def linear_search(S, n, key):
    i = 0
    while i < n:
        if S[i] == key:
            return 0
        i += 1
    return 1

def main():
    n = int(input())
    S = list(map(int, input().split()))
    
    q = int(input())
    T = list(map(int, input().split()))
    
    count = 0
    for j in range(q):
        key = T[j]
        if linear_search(S, n, key) == 1:
            count += 1
            
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
