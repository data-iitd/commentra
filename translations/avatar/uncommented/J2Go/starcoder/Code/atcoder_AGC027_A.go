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
	fmt.Println("Enter the number of sweets")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	fmt.Println("Enter the budget")
	x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	sweet := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Println("Enter sweet", i+1)
		sweet[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
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
		num -= 1
	}
	fmt.Println(num)
}

