import sys

def main():
    while True:
        W, N = map(int, sys.stdin.readline().split(','))
        if W == 0:
            break
        input_data = [list(map(int, sys.stdin.readline().split(','))) for _ in range(N)]
        
        ans = [[0, 0] for _ in range(1024)]
        
        for i in range(N):
            for j in range(1023, input_data[i][1] - 1, -1):
                if ans[j][0] < input_data[i][0] + ans[j - input_data[i][1]][0]:
                    ans[j][0] = input_data[i][0] + ans[j - input_data[i][1]][0]
                    ans[j][1] = input_data[i][1] + ans[j - input_data[i][1]][1]
        
        j = 0
        while ans[W][0] == ans[W - j - 1][0]:
            j += 1
        
        print(f"Case {j + 1}:")
        print(ans[W - j][0])
        print(ans[W - j][1])

if __name__ == "__main__":
    main()
