
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Reading Input
	X, N := readTwoInt()

	// If no values are excluded, print X and exit
	if N == 0 {
		fmt.Println(X)
		return
	}

	// Step 2: Initializing Arrays
	plus := make([]int, 256)
	minus := make([]int, 256)
	for i := 0; i < 256; i++ {
		plus[i] = i
		minus[i] = -i
	}

	// Step 3: Marking Excluded Values
	for i := 0; i < N; i++ {
		j := readInt()
		plus[j] = 0
	}

	// Step 4: Finding the Nearest Non-Zero Value
	i_min := 0
	min := 1000
	for i := 255; i >= 0; i-- {
		if plus[i] == 0 && i > 0 {
			continue
		}
		k := X - plus[i]
		if k < 0 {
			k *= -1
		}
		if k <= min {
			min = k
			i_min = i
		}
	}

	// Step 5: Outputting the Result
	fmt.Println(i_min)
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readTwoInt() (int, int) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	buf := make([]byte, 0)
	sc.Scan()
	buf = append(buf, sc.Text()...)
	sc.Scan()
	buf = append(buf, sc.Text()...)

	res := make([]int, 0)
	for _, c := range buf {
		if c =='' {
			continue
		}
		i, _ := strconv.Atoi(string(c))
		res = append(res, i)
	}

	return res[0], res[1]
}

// 