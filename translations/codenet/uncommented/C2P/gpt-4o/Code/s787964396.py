def counting_sort(a, k):
    I = 10000
    c = [0] * (I + 1)
    
    for j in range(k):
        c[a[j + 1]] += 1
    
    for i in range(1, I + 1):
        c[i] += c[i - 1]
    
    b = [0] * (k + 1)
    for j in range(k, 0, -1):
        b[c[a[j]]] = a[j]
        c[a[j]] -= 1
    
    return b

def main():
    n = int(input())
    a = [0] * (n + 1)
    
    for i in range(n):
        a[i + 1] = int(input())
    
    b = counting_sort(a, n)
    
    print(b[1], end="")
    for i in range(2, n + 1):
        print(" ", b[i], end="")
    print()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
