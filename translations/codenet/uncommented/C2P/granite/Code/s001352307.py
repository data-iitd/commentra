
def main():
    t = 0
    while True:
        W, N = map(int, input().split())
        if W == 0:
            break
        input = [list(map(int, input().split(','))) for _ in range(N)]
        ans = [[0, 0] for _ in range(1024)]
        for i in range(N):
            for j in range(1023, input[i][1] - 1, -1):
                if ans[j][0] < input[i][0] + ans[j - input[i][1]][0]:
                    ans[j][0] = input[i][0] + ans[j - input[i][1]][0]
                    ans[j][1] = input[i][1] + ans[j - input[i][1]][1]
        for j in range(1024):
            if ans[W][0] == ans[W - j - 1][0]:
                break
        print(f"Case {t + 1}:\n{ans[W - j][0]}\n{ans[W - j][1]}")
        t += 1

if __name__ == "__main__":
    main()

