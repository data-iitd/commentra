package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007

func ii1() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func is1() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func iia() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	nums := []int{}
	parts := strings.Split(scanner.Text(), " ")
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		nums = append(nums, num)
	}
	return nums
}

func isa() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return strings.Split(scanner.Text(), " ")
}

func main() {
	k := ii1()
	t := 0
	for i := 1; i <= k; i++ {
		t = (t*10 + 7) % k
		if t == 0 {
			fmt.Println(i)
			return
		}
	}
	fmt.Println(-1)
}

