W, N = 0, 0
input_data = [[0, 0] for _ in range(1024)]

case_number = 0

while True:
    ans = [[0, 0] for _ in range(1024)]
    
    W, N = map(int, input().split())
    if W == 0:
        break
    
    for i in range(N):
        input_data[i] = list(map(int, input().split(',')))

    for i in range(N):
        for j in range(1023, input_data[i][1] - 1, -1):
            if ans[j][0] < input_data[i][0] + ans[j - input_data[i][1]][0]:
                ans[j][0] = input_data[i][0] + ans[j - input_data[i][1]][0]
                ans[j][1] = input_data[i][1] + ans[j - input_data[i][1]][1]

    j = 0
    while ans[W][0] == ans[W - j - 1][0]:
        j += 1

    case_number += 1
    print(f"Case {case_number}:")
    print(ans[W - j][0])
    print(ans[W - j][1])

# <END-OF-CODE>
