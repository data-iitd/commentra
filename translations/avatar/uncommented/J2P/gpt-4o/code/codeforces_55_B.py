import sys

min_value = sys.maxsize

def util(arr, ops, idx):
    global min_value
    if idx == 3:
        min_value = min(min_value, arr[0])
        return
    
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            a = [arr[k] for k in range(len(arr)) if k != j and k != i]
            if idx < 3 and ops[idx] == "+":
                res = arr[i] + arr[j]
            else:
                res = arr[i] * arr[j]
            a.append(res)
            util(a, ops, idx + 1)

def main():
    global min_value
    arr = []
    for _ in range(4):
        arr.append(int(input()))
    
    ops = [input() for _ in range(3)]
    
    util(arr, ops, 0)
    print(min_value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
