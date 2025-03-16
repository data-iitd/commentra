import sys

def main():
    arr = []
    for i in range(4):
        arr.append(int(sys.stdin.readline()))
    ops = []
    for i in range(3):
        ops.append(sys.stdin.readline().strip())
    min = sys.maxint
    util(arr, ops, 0, min)
    print min

def util(arr, ops, idx, min):
    if idx == 3:
        min = min if min < sys.maxint else arr[0]
        return
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            a = []
            for k in range(len(arr)):
                if k!= j and k!= i:
                    a.append(arr[k])
            res = 0
            if idx < 3 and ops[idx] == "+":
                res = arr[i] + arr[j]
            else:
                res = arr[i] * arr[j]
            a.append(res)
            util(a, ops, idx+1, min)

if __name__ == "__main__":
    main()

