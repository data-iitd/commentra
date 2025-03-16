

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(reader, "%d\n", &n)
	cnt := make([]int, 26)
	for i := 0; i < n; i++ {
		var s string
		fmt.Fscanf(reader, "%s\n", &s)
		cnt[s[0]-'a']++
	}
	ans := int64(1)
	for _, v := range cnt {
		ans *= int64(v)
	}
	ans--
	fmt.Println(ans)
}

