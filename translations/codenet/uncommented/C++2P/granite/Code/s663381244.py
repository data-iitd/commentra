
m = [10, 50, 100, 500]

while True:
    money = int(input())
    if money == 0:
        break

    num = [int(input()) for _ in range(4)]
    sum_ = sum(num[i] * m[i] for i in range(4))
    change = sum_ - money

    for i in range(3, -1, -1):
        if change >= m[i]:
            num[i] -= change // m[i]
            change %= m[i]

    for i in range(4):
        if num[i] > 0:
            print(m[i], num[i])

print("