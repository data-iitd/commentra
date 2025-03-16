
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	ara := make([]int, n)
	mp := make(map[int]int)
	for i := 0; i < n; i++ {
		ara[i], _ = strconv.Atoi(reader.ReadLine())
		mp[ara[i]]++
	}
	max := 0
	for _, v := range mp {
		if v > max {
			max = v
		}
	}
	mp2 := make(map[int]int)
	for i := 0; i < n; i++ {
		mp2[ara[i]]++
		if mp2[ara[i]] == max {
			fmt.Fprintln(writer, ara[i])
			break
		}
	}

	writer.Flush()
}

// 