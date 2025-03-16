package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	var n, k int
	fmt.Sscanf(input, "%d %d", &n, &k)

	M := make([]int, n)
	input, _ = reader.ReadString('\n')
	nums := bufio.NewScanner(strings.NewReader(input))
	nums.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		nums.Scan()
		M[i], _ = strconv.Atoi(nums.Text())
	}

	m := 0
	for j := 0; j < n; j++ {
		for p := 0; p < n; p++ {
			if M[p] == 0 {
				fmt.Printf("%d ", p+1)
				break
			}
		}
		for l := 0; l < p+1-k; l++ {
			M[l]--
		}
		M[p]--
	}
	fmt.Println()
}
