def main():
    import sys
    from heapq import nlargest

    input = sys.stdin.read
    data = input().split()
    
    X = int(data[0])
    Y = int(data[1])
    Z = int(data[2])
    K = int(data[3])
    
    A = list(map(int, data[4:4 + X]))
    B = list(map(int, data[4 + X:4 + X + Y]))
    C = list(map(int, data[4 + X + Y:4 + X + Y + Z]))
    
    A.sort(reverse=True)
    B.sort(reverse=True)
    C.sort(reverse=True)
    
    AB = []
    for a in A:
        for b in B:
            AB.append(a + b)
    
    AB.sort(reverse=True)
    
    ABC = []
    for i in range(min(K, len(AB))):
        for c in C:
            ABC.append(AB[i] + c)
    
    ABC.sort(reverse=True)
    
    for i in range(K):
        print(ABC[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
