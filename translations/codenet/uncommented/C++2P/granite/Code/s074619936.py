
while True:
    str = input()
    if str == "0":
        break
    sum = 0
    for i in range(len(str)):
        tmp = str[i]
        num = int(tmp)
        sum += num
    print(sum)

