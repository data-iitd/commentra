def main():
    str = input().strip()
    p = input().strip()

    tmp = str
    str = str + tmp

    slen = len(str)
    plen = len(p)

    flag = 0
    for i in range(slen - plen + 1):
        if str[i:i+plen] == p:
            flag = 1
            break

    if flag:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
