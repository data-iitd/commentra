

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(reader, "%d\n", &n)
	N := 100005
	cnt := make([]int, 21)
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(reader, "%d\n", &a)
		cnt[a+10]++
	}
	res := int64(0)
	for i := 0; i < 10; i++ {
		res += int64(cnt[i]) * int64(cnt[20-i])
	}
	res += int64(cnt[10]) * int64(cnt[10]-1) / 2
	fmt.Println(res)
}

