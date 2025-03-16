import sys

min_val = float('inf')

def util(arr, ops, idx):
    global min_val
    if idx == 3:
        min_val = min(min_val, arr[0])
        return

    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            new_arr = []
            for k in range(len(arr)):
                if k != i and k != j:
                    new_arr.append(arr[k])

            if ops[idx] == '+':
                res = arr[i] + arr[j]
            else:
                res = arr[i] * arr[j]

            new_arr.append(res)
            util(new_arr, ops, idx + 1)

def main():
    global min_val
    min_val = float('inf')
    arr = []

    for _ in range(4):
        arr.append(int(sys.stdin.readline().strip()))

    ops = []
    for _ in range(3):
        ops.append(sys.stdin.readline().strip())

    util(arr, ops, 0)
    print(min_val)

if __name__ == "__main__":
    main()
