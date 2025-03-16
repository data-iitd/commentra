

import sys

min = sys.maxsize

def util(arr, ops, idx):
    if idx == 3:
        global min
        min = min if min < arr[0] else arr[0]
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

if __name__ == "__main__":
    arr = [int(x) for x in input().split()]
    ops = input().split()
    util(arr, ops, 0)
    print(min)

This Python code is equivalent to the given Java code. It reads the input numbers and operators from the standard input, and then calls the util function to find the minimum value. The util function recursively performs the specified operations and updates the minimum value accordingly. Finally, it prints the minimum value found.

Please note that the Python code uses the sys module to set the initial value of min to sys.maxsize, which is equivalent to Long.MAX_VALUE in Java.