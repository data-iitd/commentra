
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

	var n, l int
	fmt.Fscanf(reader, "%d %d\n", &n, &l)

	var s []string
	for i := 0; i < n; i++ {
		str, _ := reader.ReadString('\n')
		s = append(s, strings.TrimSpace(str))
	}

	sort.Strings(s)

	for _, v := range s {
		fmt.Println(v)
	}
}

