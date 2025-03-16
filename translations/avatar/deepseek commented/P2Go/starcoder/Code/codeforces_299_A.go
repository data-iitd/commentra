
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a := make([]int, 0)
	for {
		line, _, err := reader.ReadLine()
		if err!= nil {
			break
		}
		for _, v := range strings.Split(string(line), " ") {
			i, _ := strconv.Atoi(v)
			a = append(a, i)
		}
	}
	sort.Ints(a)
	for _, v := range a {
		if v%a[0] == 0 {
			fmt.Println(v)
			return
		}
	}
	fmt.Println(-1)
}

