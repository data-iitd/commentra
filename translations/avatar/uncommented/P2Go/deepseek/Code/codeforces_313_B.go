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
	soz, _ := reader.ReadString('\n')
	soz = strings.TrimSpace(soz)

	a := make([]int, len(soz)+1)
	for i := 1; i < len(soz); i++ {
		a[i] = a[i-1]
		if soz[i-1] == soz[i] {
			a[i]++
		}
	}

	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		mL, _ := reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(mL), " ")
		m, _ := strconv.Atoi(parts[0])
		l, _ := strconv.Atoi(parts[1])
		arr[i] = a[l-1] - a[m-1]
	}

	for _, i := range arr {
		fmt.Println(i)
	}
}

