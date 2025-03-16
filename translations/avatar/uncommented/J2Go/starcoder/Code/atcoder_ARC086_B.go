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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	a := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	r := make([]string, 0)
	m := 0
	for i := 1; i < n; i++ {
		if math.Abs(float64(a[m])) < math.Abs(float64(a[i])) {
			m = i
		}
	}
	for i := 0; i < n; i++ {
		if a[m] >= 0 && a[i] >= 0 || a[m] < 0 && a[i] < 0 {
			r = append(r, fmt.Sprintf("%d %d", m+1, i+1))
		}
	}
	if a[m] >= 0 {
		for i := 1; i < n; i++ {
			r = append(r, fmt.Sprintf("%d %d", i, i+1))
		}
	} else {
		for i := n; i > 1; i-- {
			r = append(r, fmt.Sprintf("%d %d", i, i-1))
		}
	}
	fmt.Println(len(r))
	for _, v := range r {
		fmt.Println(v)
	}
}

