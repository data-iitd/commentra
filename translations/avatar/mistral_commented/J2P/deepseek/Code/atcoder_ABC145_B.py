def cout(str):
    print(str)


def main():
    cin = input()
    n = int(cin)
    str = input()

    a = ""
    for i in range(n // 2):
        a += str[i]

    if str == a + a:
        cout("Yes")
    else:
        cout("No")


main()
