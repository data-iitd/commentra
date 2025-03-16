def main():
    s = input()
    targ = list(s)
    map = {}

    for i in range(len(targ)):
        currentChar = targ[i]
        if currentChar not in map:
            map[currentChar] = 1
        else:
            map[currentChar] += 1

    ok = True
    for key, value in map.items():
        if value != 2:
            ok = False
            break

    if ok and len(map) == 2:
        print("Yes")
    else:
        print("No")

main()
