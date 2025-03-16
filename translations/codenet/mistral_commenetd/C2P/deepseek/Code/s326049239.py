def main():
    while True:
        try:
            a = int(input())
        except EOFError:
            break

        c = 0
        k = 0

        if a < 3:
            print(0)
            continue

        b = a

        while a > 0:
            a -= 1
            b -= 1
            c += 1

            if c == 3:
                k += 1
                c = 0

        print(k)


main()

