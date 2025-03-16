def search(A, n, key):
    A.append(key)  # Append the key to the end of the list
    i = 0
    while A[i] != key:
        i += 1
    return i != n

def main():
    n = int(input())
    A = list(map(int, input().split()))
    q = int(input())
    sum = 0
    
    for _ in range(q):
        key = int(input())
        if search(A, n, key):
            sum += 1
            
    print(sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
