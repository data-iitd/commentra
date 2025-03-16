#include <stdio.h>
#include <string.h>

int main() {
    char S[200001];
    int N, mod_arr[200001], mod_cnt[2019] = {0};
    long long ans = 0;
    int radix = 1, tmp, i;

    // Read input
    scanf("%s", S);
    N = strlen(S);

    // Process the string
    for (i = 0; i < N; i++) {
        tmp = 0;

        // Calculate the value of the current digit in the given base
        tmp = ((S[N - 1 - i] - '0') * radix) % 2019;

        // Update the temporary variable with the carry from the previous digit
        if (i != 0) tmp = (tmp + mod_arr[i - 1]) % 2019;

        // Store the intermediate result in the array
        mod_arr[i] = tmp;

        // Update the frequency count of the current number in the array
        mod_cnt[tmp]++;

        // Update the radix for the next iteration
        radix = (radix * 10) % 2019;
    }

    // Calculate the answer
    for (i = 0; i < 2019; i++) {
        ans += (long long)mod_cnt[i] * (mod_cnt[i] - 1) / 2;
    }

    // Print the final answer
    printf("%lld\n", ans);

    return 0;
}
