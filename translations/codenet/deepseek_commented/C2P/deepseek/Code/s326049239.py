def main():
    while True:
        try:
            a = int(input())
        except EOFError:
            break
        
        if a < 3:
            print(0)
        else:
            b = a
            c = 0
            k = 0
            while a > 0:
                a -= 1
                b -= 1
                c += 1
                if c == 3:
                    k += 1
                    c = 0
            print(k)

main()
