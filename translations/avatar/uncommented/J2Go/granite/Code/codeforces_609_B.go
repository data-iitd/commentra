
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	m, _ := strconv.Atoi(reader.ReadLine()[2:])
	arr := make([]int, n)
	gen := make([]int, 11)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadLine()[2:])
		gen[arr[i]]++
	}
	ans := int64(0)
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i!= k {
				ans += int64(gen[i]) * int64(gen[k])
			}
		}
	}
	fmt.Println(ans / 2)
}

