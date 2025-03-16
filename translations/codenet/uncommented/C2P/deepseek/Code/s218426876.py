while True:
    x = input()
    if x == '0':
        break
    sum = 0
    for char in x:
        sum += int(char)
    print(sum)
