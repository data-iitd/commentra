
import sys
def util(arr, ops, idx):
    if idx == 3:
        global min
        min = min(min, arr[0])
        return
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            a = []
            for k in range(len(arr)):
                if k!= j and k!= i:
                    a.append(arr[k])
            res = arr[i] + arr[j] if ops[idx] == "+" else arr[i] * arr[j]
            a.append(res)
            util(a, ops, idx + 1)

min = sys.maxsize
arr = [int(x) for x in input().split()]
ops = input().split()
util(arr, ops, 0)
print(min)
