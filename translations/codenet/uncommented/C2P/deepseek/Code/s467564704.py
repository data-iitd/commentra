def main():
    input_matrix = [list(map(int, input().split())) for _ in range(3)]
    tc = int(input())
    for _ in range(tc):
        testcase = int(input())
        for i in range(3):
            for j in range(3):
                if input_matrix[i][j] == testcase:
                    input_matrix[i][j] = 0

    if (input_matrix[0][0] == 0 and input_matrix[1][1] == 0 and input_matrix[2][2] == 0) or \
       (input_matrix[0][2] == 0 and input_matrix[1][1] == 0 and input_matrix[2][0] == 0) or \
       (input_matrix[0][0] == 0 and input_matrix[0][1] == 0 and input_matrix[0][2] == 0) or \
       (input_matrix[1][0] == 0 and input_matrix[1][1] == 0 and input_matrix[1][2] == 0) or \
       (input_matrix[2][0] == 0 and input_matrix[2][1] == 0 and input_matrix[2][2] == 0) or \
       (input_matrix[0][0] == 0 and input_matrix[1][0] == 0 and input_matrix[2][0] == 0) or \
       (input_matrix[0][1] == 0 and input_matrix[1][1] == 0 and input_matrix[2][1] == 0) or \
       (input_matrix[0][2] == 0 and input_matrix[1][2] == 0 and input_matrix[2][2] == 0):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
