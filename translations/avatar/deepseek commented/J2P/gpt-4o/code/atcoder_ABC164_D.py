def main():
    import sys
    from collections import defaultdict

    S = sys.stdin.readline().strip()
    N = len(S)

    # Array to store remainders at each position
    mod_arr = [0] * N
    # Dictionary to count occurrences of each remainder
    mod_cnt = defaultdict(int)
    # Radix initialized to 1 for the least significant digit
    radix = 1

    # Process each character in the string from right to left
    for i in range(N):
        tmp = (int(S[N - 1 - i]) * radix) % 2019
        if i != 0:
            tmp = (tmp + mod_arr[i - 1]) % 2019
        mod_arr[i] = tmp
        mod_cnt[tmp] += 1
        radix = (radix * 10) % 2019

    # Calculate the number of valid pairs using combinatorics
    ans = 0
    mod_cnt[0] += 1  # Ensure 0 is counted
    for i in range(2019):
        ans += mod_cnt[i] * (mod_cnt[i] - 1) // 2

    # Output the result
    print(ans)

if __name__ == "__main__":
    main()
# <END-OF-CODE>
