def min(a, b):
    if a <= b:
        return a
    return b

def chain(b, n):
    a = b[:]
    
    for i in range(n - 4):
        if a[i] != 0 and a[i] == a[i + 1] == a[i + 2] == a[i + 3]:
            count = 0
            color = a[i]
            
            for j in range(i, n):
                if a[j] == color:
                    a[j] = 0
                    count += 1
                else:
                    break
            
            for j in range(n - count):
                if i + j + count < n:
                    a[i + j] = a[i + j + count]
                    if i + j + count < n:
                        a[i + j + count] = 0
            
            i = -1  # Reset i to start from the beginning again
            
    count = 0
    while count < n and a[count] != 0:
        count += 1
    
    if count == 4 and a[0] == a[1] == a[2] == a[3]:
        return 0
    
    return count

def main():
    while True:
        a = [0] * 10000
        
        n = int(input())
        if n == 0:
            break
        ans = n
        
        for i in range(n):
            a[i] = int(input())
        
        for i in range(n - 4):
            count = [0, 0, 0]
            for j in range(i, i + 4):
                if a[j] - 1 >= 0:
                    count[a[j] - 1] += 1
            
            color = 0
            for j in range(3):
                if count[j] >= 3:
                    color = j + 1
                    break
            
            if color != 0:
                for j in range(i, i + 4):
                    buf = a[j]
                    a[j] = color
                    ans = min(ans, chain(a, n))
                    a[j] = buf
        
        print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
