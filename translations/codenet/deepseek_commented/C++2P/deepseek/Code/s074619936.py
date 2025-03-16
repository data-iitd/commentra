def main():
    while True:
        str = input()
        if str == "0":
            break
        sum = 0
        for char in str:
            num = int(char)
            sum += num
        print(sum)

main()

