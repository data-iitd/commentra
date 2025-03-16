def main():
    n = int(input())
    arr = list(map(int, input().split()))
    total_sum = sum(arr)
    count = 0
    result_indices = []

    for i in range(n):
        if (total_sum - arr[i]) % (n - 1) == 0 and (total_sum - arr[i]) // (n - 1) == arr[i]:
            count += 1
            result_indices.append(i + 1)

    print(count)
    if count > 0:
        print(" ".join(map(str, result_indices)))

if __name__ == "__main__":
    main()
