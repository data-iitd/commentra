
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    print(sub(a, b))

def sub(a, b):
    min = min(a, b)
    max = max(a, b)
    result = 0
    while min > 0:
        result += max // min
        max = max % min
        curr_min = min(min, max)
        curr_max = max(min, max)
        min = curr_min
        max = curr_max
    return result

