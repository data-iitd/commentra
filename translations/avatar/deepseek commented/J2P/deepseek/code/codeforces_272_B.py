def rec(x):
    answer = 0
    for k in range(31, -1, -1):
        if x & (1 << k):
            answer += 1
    return answer

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = [0] * 33
    
    for i in range(1, n + 1):
        a[rec(int(data[i]))] += 1
    
    answer = 0
    
    for i in range(len(a)):
        summ = (1 + a[i] - 1) / 2 * (a[i] - 1)
        answer += summ
    
    print(int(answer))

main()
