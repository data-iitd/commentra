
import sys

class Main:
    min = sys.maxsize

    def main(self):
        arr = []
        ops = []
        for i in range(4):
            arr.append(int(input()))
        for i in range(3):
            ops.append(input())
        self.util(arr, ops, 0)
        print(min)

    def util(self, arr, ops, idx):
        if idx == 3:
            min = min(min, arr[0])
            return
        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                a = []
                for k in range(len(arr)):
                    if k!= j and k!= i:
                        a.append(arr[k])
                res = 0
                if idx < 3 and ops[idx] == '+':
                    res = arr[i] + arr[j]
                else:
                    res = arr[i] * arr[j]
                a.append(res)
                self.util(a, ops, idx + 1)

# 