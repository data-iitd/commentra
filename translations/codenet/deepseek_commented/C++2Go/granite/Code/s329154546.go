
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
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	L, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i] = strings.TrimSpace(readLine(reader))
	}
	sort.Strings(S)
	for _, s := range S {
		fmt.Println(s)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

