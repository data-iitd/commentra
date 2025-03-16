
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

	var N, L int
	fmt.Fscanf(reader, "%d %d\n", &N, &L)

	s := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%s\n", &s[i])
	}

	sort.Strings(s)

	for i := 0; i < N; i++ {
		fmt.Print(s[i])
	}
	fmt.Println()
}

