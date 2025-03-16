import sys

def main():
    S = input().strip()
    N = len(S)

    mod_arr = [0] * N
    mod_cnt = [0] * 2019
    radix = 1

    for i in range(N):
        tmp = 0

        # Calculating the value of the current digit in the given base
        tmp = (ord(S[N - 1 - i]) - ord('0')) * radix % 2019

        # Updating the temporary variable with the carry from the previous digit
        if i != 0:
            tmp = (tmp + mod_arr[i - 1]) % 2019

        # Storing the intermediate result in the array
        mod_arr[i] = tmp

        # Updating the frequency count of the current number in the array
        mod_cnt[tmp] += 1

        # Updating the radix for the next iteration
        radix = radix * 10 % 2019

    ans = 0

    # Calculating the answer by summing up the terms of the formula
    for i in range(2019):
        ans += mod_cnt[i] * (mod_cnt[i] - 1) // 2

    print(ans)

if __name__ == "__main__":
    main()
