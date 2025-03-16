
while True:
    x = input()
    if x == '0':
        break
    sum = 0
    for i in range(len(x)):
        if x[i] == '0':
            print(sum)
            break
        else:
            sum += int(x[i])

