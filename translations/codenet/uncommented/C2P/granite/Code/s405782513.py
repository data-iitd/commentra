
while True:
    try:
        c = list(map(int, input().split()))
        card = [0] * 10
        for i in c:
            card[i - 1] = 1
        count = 0
        sum = sum(c)
        for i in range(10):
            if card[i] == 0 and sum + i + 1 <= 20:
                count += 1
        if count >= 4:
            print("YES")
        else:
            print("NO")
    except EOFError:
        break

