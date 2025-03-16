

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter an integer: ")
	text, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(text)

	ans := aaa(N, "0")
	fmt.Println(ans)
}

func aaa(N int, n string) int {
	if int(n[0]) > N {
		return 0
	}

	ans := 1
	for _, i := range "753" {
		ans += aaa(N, n+string(i))
	}

	return ans
}

// END-OF-CODE