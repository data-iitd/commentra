def main():
    str = [input() for _ in range(4)]
    yes = 0
    for u in range(3):
        for i in range(3):
            if (str[u][i] == str[u][i + 1] and (str[u + 1][i] == str[u][i] or str[u + 1][i + 1] == str[u][i])) or \
               (str[u + 1][i] == str[u + 1][i + 1] and (str[u][i] == str[u + 1][i] or str[u][i + 1] == str[u + 1][i])):
                print("YES")
                yes = 1
                break
        if yes == 1:
            break
    if yes == 0:
        print("NO")

if __name__ == "__main__":
    main()
