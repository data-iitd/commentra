# <START-OF-CODE>
a, b, c = map(int, input().split())

if b <= c:
    print("NO")
else:
    d = a
    e = d % b
    
    for i in range(b):
        d = d % b
        
        if d == c:
            print("YES")
            break
        elif i!= 0 and d == c:
            print("NO")
            break
        
        d += a

print("NO")
# 