def main():
    s = input().strip()

    max_tmp = 0
    max_length = 0
    for i in range(len(s)):
        flag = False
        if s[i] in "ACTG":
            max_tmp += 1
        else:
            flag = True

        if i == len(s) - 1:
            flag = True
        if flag:
            if max_length < max_tmp:
                max_length = max_tmp
            max_tmp = 0

    print(max_length)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
