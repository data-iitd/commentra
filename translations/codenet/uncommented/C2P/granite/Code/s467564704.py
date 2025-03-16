
input = [[0 for _ in range(3)] for _ in range(3)]
for i in range(3):
    for j in range(3):
        input[i][j] = int(input())

tc = int(input())
testcase = []
for i in range(tc):
    testcase.append(int(input()))

for i in range(3):
    for j in range(3):
        if input[i][j] in testcase:
            input[i][j] = 0

if input[0][0] == 0 and input[1][1] == 0 and input[2][2] == 0:
    print("Yes")
elif input[0][2] == 0 and input[1][1] == 0 and input[2][0] == 0:
    print("Yes")
elif input[0][0] == 0 and input[0][1] == 0 and input[0][2] == 0:
    print("Yes")
elif input[1][0] == 0 and input[1][1] == 0 and input[1][2] == 0:
    print("Yes")
elif input[2][0] == 0 and input[2][1] == 0 and input[2][2] == 0:
    print("Yes")
elif input[0][0] == 0 and input[1][0] == 0 and input[2][0] == 0:
    print("Yes")
elif input[0][1] == 0 and input[1][1] == 0 and input[2][1] == 0:
    print("Yes")
elif input[0][2] == 0 and input[1][2] == 0 and input[2][2] == 0:
    print("Yes")
else:
    print("No")

