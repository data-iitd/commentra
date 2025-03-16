def main():
    s = input()
    targ = list(s)
    char_count = {}

    for char in targ:
        if char not in char_count:
            char_count[char] = 1
        else:
            char_count[char] += 1

    ok = True
    for count in char_count.values():
        if count != 2:
            ok = False
            break

    if ok and len(char_count) == 2:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
