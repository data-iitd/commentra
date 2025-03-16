import sys

def main():
    str = [None] * 4
    i = -1

    while i != 3:
        i += 1
        str[i] = input()

    u = -1

    while u != 2:
        u += 1

        yes = 0
        i = -1

        while i != 2:
            i += 1

            if (str[u][i] == str[u][i + 1] and (str[u + 1][i] == str[u][i] or str[u + 1][i + 1] == str[u][i])) or \
               (str[u + 1][i] == str[u + 1][i + 1] and (str[u][i] == str[u + 1][i] or str[u][i + 1] == str[u + 1][i])):
                yes = 1
                print("YES")
                break

        if yes == 1:
            break

        if yes == 0:
            print("NO")

if __name__ == "__main__":
    main()
