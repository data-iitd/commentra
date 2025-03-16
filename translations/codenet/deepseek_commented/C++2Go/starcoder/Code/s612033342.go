<<<<<<< HEAD

import (
	"fmt"
	"math"
=======
package main

import (
	"bufio"
	"fmt"
>>>>>>> 98c87cb78a (data updated)
	"os"
	"strconv"
	"strings"
)

<<<<<<< HEAD
// Computes 2^a
func pow2(a int) int {
	ret := 1
	for i := 0; i < a; i++ {
		ret *= 2
	}
	return ret
}

// Counts the number of 1s in the grid hw where both the i-th row and the j-th column are selected
func count(hw [][]int, a, b int) int {
	sum := 0
	for i := 0; i < len(hw); i++ {
		for j := 0; j < len(hw[0]); j++ {
			if a>>i&1 == 1 && b>>j&1 == 1 && hw[i][j] == 1 {
=======
func main() {
	reader := bufio.NewReader(os.Stdin)
	h, w, k := readThreeNums(reader)
	hw := make([][]int, h)
	for i := 0; i < h; i++ {
		hw[i] = readNNums(reader, w)
	}
	res := solve(hw, h, w, k)
	fmt.Println(res)
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-'; x++ {
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func solve(hw [][]int, h int, w int, k int) int {
	var count func(int, int) int
	count = func(a, b int) int {
		var ret int
		for i := 0; i < h; i++ {
			for j := 0; j < w; j++ {
				if (a>>i&1) == 1 && (b>>j&1) == 1 && hw[i][j] == 1 {
					ret++
				}
			}
		}
		return ret
	}

	var sum int
	for a := 0; a < pow2(h); a++ {
		for b := 0; b < pow2(w); b++ {
			if count(a, b) == k {
>>>>>>> 98c87cb78a (data updated)
				sum++
			}
		}
	}
	return sum
}

<<<<<<< HEAD
func main() {
	h, w, k := 0, 0, 0
	fmt.Sscanf(os.Args[1], "%d", &h)
	fmt.Sscanf(os.Args[2], "%d", &w)
	fmt.Sscanf(os.Args[3], "%d", &k)

	// Initialize the grid with dimensions h x w, filled with 0s
	hw := make([][]int, h)
	for i := 0; i < h; i++ {
		hw[i] = make([]int, w)
	}

	// Read the grid and set 1s where there is a '#'
	for i := 0; i < h; i++ {
		s := strings.TrimSpace(os.Args[4+i])
		for j := 0; j < w; j++ {
			hw[i][j] = 0
			if s[j] == '#' {
				hw[i][j] = 1
			}
		}
	}

	sum := 0

	// Iterate over all possible combinations of row and column selections
	for i := 0; i < pow2(h); i++ {
		for j := 0; j < pow2(w); j++ {
			if count(hw, i, j) == k {
				sum++ // Check if the condition is met and sum the valid combinations
			}
		}
	}

	// Output the result
	fmt.Println(sum)
=======
func pow2(a int) int {
	var ret int
	for i := 0; i < a; i++ {
		ret *= 2
	}
	return ret
>>>>>>> 98c87cb78a (data updated)
}

