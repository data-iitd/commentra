import sys

def main():
    n = int(input().strip())
    x = int(input().strip())
    srime_list = list(map(int, input().strip().split()))
    
    cost_list = []
    for i in range(n):
        cost_array = [0] * n
        cost_array[0] = srime_list[i]
        for cast_num in range(1, n):
            cost_array[cast_num] = min(cost_array[cast_num - 1], srime_list[(i - cast_num + n) % n])
        cost_list.append(cost_array)
    
    result = []
    for i in range(n):
        result.append(i * x + sum(cost_list[j][i] for j in range(n)))
    
    print(min(result))

if __name__ == "__main__":
    main()
