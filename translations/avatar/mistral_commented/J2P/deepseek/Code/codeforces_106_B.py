import sys

def main():
    input = sys.stdin.readline
    n = int(input())

    vec = []
    for _ in range(n):
        vec.append(list(map(int, input().split())))

    ans = 500
    ansprice = 20000

    for i in range(n):
        flag = 1
        for j in range(n):
            if vec[i][0] < vec[j][0] and vec[i][1] < vec[j][1] and vec[i][2] < vec[j][2]:
                flag = 0
                break
        if flag == 1:
            if vec[i][3] < ansprice:
                ansprice = vec[i][3]
                ans = i + 1

    print(ans)

if __name__ == "__main__":
    main()
