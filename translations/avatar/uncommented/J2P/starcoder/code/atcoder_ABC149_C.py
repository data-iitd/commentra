
# <START-OF-CODE>

x = int(input())
if x!= 2 and x % 2 == 0:
    x += 1
while True:
    i = 3
    sqrtNum = math.sqrt(x)
    while i <= sqrtNum:
        if x % i == 0:
            break
        i += 2
    if i > sqrtNum:
        break
    x += 2
print(x)

# 