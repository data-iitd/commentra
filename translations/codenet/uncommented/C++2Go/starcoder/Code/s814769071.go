#pragma region
package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	var MOD = 1e9 + 7
	var mx, mn int
	mx = n * (n + 1) / 2 - (n - k)*(n - k + 1) / 2
	mn = k * (k - 1) / 2
	var res int
	for i := k; i <= n+1; i++ {
		res += mx - mn + 1
		mx += n - i
		mn += i
		res %= MOD
	}
	fmt.Println(res)
}
#pragma endregion

