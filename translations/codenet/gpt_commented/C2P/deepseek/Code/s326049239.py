def main():
    while True:
        try:
            a = int(input())
            c = 0
            k = 0

            if a < 3:
                print(0)
            else:
                b = a
                while a > 0:
                    a -= 1
                    b -= 1
                    c += 1
                    if c == 3:
                        k += 1
                        c = 0
                print(k)
        except EOFError:
            break


main()
