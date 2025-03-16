import sys

def main():
    n = int(input().strip())
    strings = []
    for _ in range(n):
        strings.append(input().strip())

    ans = True
    past = []
    next_char = ""

    for i in range(n):
        if strings[i] in past:
            ans = False
            break
        past.append(strings[i])

        if i != 0:
            if not next_char == strings[i][0]:
                ans = False
                break
        next_char = strings[i][-1]

    if ans:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
