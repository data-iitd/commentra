import math

def main():
    minA = math.pow(10, 9) + 1
    num = 0
    
    n, t = map(int, input().split())
    A = list(map(int, input().split()))
    
    f = 0
    
    for i in range(n):
        if minA > A[i]:
            minA = A[i]
        else:
            if f == A[i] - minA:
                num += 1
            elif f < A[i] - minA:
                num = 1
                f = A[i] - minA
    
    print(num)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
