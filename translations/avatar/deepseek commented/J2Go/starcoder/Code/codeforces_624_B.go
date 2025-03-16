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
	fmt.Println("Enter the number of elements in the array:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	ans := make([]int, n)
	fmt.Println("Enter the elements of the array:")
	for i := 0; i < n; i++ {
		ans[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	sort.Ints(ans)
	count := ans[n-1]
	for i := n - 2; i >= 0; i-- {
		if ans[i] < ans[i+1] {
			count += ans[i]
		} else {
			for ans[i] >= ans[i+1] {
				ans[i]--
			}
			if ans[i] > 0 {
				count += ans[i]
			}
		}
	}
	fmt.Println(count)
}

