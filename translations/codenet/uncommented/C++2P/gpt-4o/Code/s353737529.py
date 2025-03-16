# これを入れて実行
# python code.py

def main():
    n = int(input())

    s = ""

    if n == 0:
        print('0')
        return

    while n != 0:
        if n % 2 == 0:
            s += '0'
        else:
            s += '1'

        n -= abs(n % 2)
        n //= -2

    s = s[::-1]  # Reverse the string

    print(s)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
