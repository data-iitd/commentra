n = int(input())
taro = 0
hanako = 0

for _ in range(n):
    t = input()
    h = input()
    
    if t < h:
        hanako += 3
    elif t > h:
        taro += 3
    else:
        taro += 1
        hanako += 1

print(taro, hanako)

# <END-OF-CODE>
