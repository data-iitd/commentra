
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	const MOD = 100000007
	r := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(r, "%d\n", new(int))
	s := make([]byte, n)
	for i := 0; i < n; i++ {
		s[i], _ = r.ReadByte()
	}
	cnt := make([]int, 26)
	for i := 0; i < n; i++ {
		cnt[s[i]-'a']++
	}
	ans := int64(cnt[0])
	for i := 1; i < 26; i++ {
		ans *= int64(cnt[i])
		ans %= MOD
	}
	fmt.Println(ans - 1)
}

