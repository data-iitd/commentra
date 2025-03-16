package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	gcd := func(a, b int) int {
		for b != 0 {
			a, b = b, a%b
		}
		return a
	}

	ceil := func(a, b int) int {
		return (a + b - 1) / b
	}

	sqrt := func(a int) int {
		return int(math.Sqrt(float64(a)))
	}

	ii1 := func() int {
		numStr, _ := reader.ReadString('\n')
		num, _ := strconv.Atoi(numStr[:len(numStr)-1])
		return num
	}

	is1 := func() string {
		str, _ := reader.ReadString('\n')
		return str[:len(str)-1]
	}

	iia := func() []int {
		line, _ := reader.ReadString('\n')
		numsStr := line[:len(line)-1]
		nums := []int{}
		for _, numStr := range strings.Split(numsStr, " ") {
			num, _ := strconv.Atoi(numStr)
			nums = append(nums, num)
		}
		return nums
	}

	isa := func() []string {
		line, _ := reader.ReadString('\n')
		words := []string{}
		for _, word := range strings.Split(line[:len(line)-1], " ") {
			words = append(words, word)
		}
		return words
	}

	k := ii1()
	t := 0
	for i := 1; i <= k; i++ {
		t = (t % k) * 10 + 7
		if t%k == 0 {
			fmt.Fprintln(writer, i)
			break
		}
	} else {
		fmt.Fprintln(writer, -1)
	}
}
