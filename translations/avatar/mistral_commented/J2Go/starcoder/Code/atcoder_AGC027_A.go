
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
	fmt.Println("Enter the number of elements in the list")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the target value")
	x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	sweet := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Println("Enter the element")
		sweet[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	sort.Ints(sweet)
	num := 0
	for i := 0; i < N; i++ {
		if x-sweet[num] >= 0 {
			x = x - sweet[num]
			num++
		} else {
			break
		}
	}
	if (num == N) && (x > 0) {
		num--
	}
	fmt.Println(num)
}

