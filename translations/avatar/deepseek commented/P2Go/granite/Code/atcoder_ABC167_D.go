

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the values of N and K from input
	N, K := readTwoInt64()

	// Read the list L of integers from input
	L := readNInt64(N)

	// Insert -1 at the beginning of the list L
	L = append([]int64{-1}, L...)

	// Initialize the path list with the first element 1
	path := []int64{1}

	// Initialize index tracker to 0
	ind := int64(0)

	// Initialize count to 0
	count := int64(0)

	// Initialize current position to 1
	x := int64(1)

	// Initialize loop start index to -1
	t := int64(-1)

	// Initialize flag to indicate loop detection
	flag := false

	// Initialize a map to keep track of indices of elements in path
	Hash := make(map[int64]int64)

	// Main loop to traverse the path
	for i := int64(0); i <= N; i++ {
		// Get the next element in the path
		ne := L[x]

		// Check if the next element is already in the Hash
		if Hash[ne] > 0 {
			// Loop detected, set flag and record the start index
			flag = true
			t = Hash[ne]
			break
		}

		// Append the next element to the path and update index
		path = append(path, ne)
		ind++

		// Update the Hash with the current index
		Hash[ne] = ind

		// Move to the next element
		x = ne
	}

	// Check if a loop is detected
	if flag {
		// Create a loop slice from the detected start index to the end
		loop := path[t:]

		// If K is within the bounds of the path length, print the K-th element
		if K < int64(len(path)) {
			fmt.Println(path[K])
		} else {
			// Adjust K for the loop length
			K = K - int64(len(path))
			K = K % int64(len(loop))
			// Print the K-th element of the loop
			fmt.Println(loop[K])
		}
	} else {
		// If no loop, print the (K-1)-th element of the path
		fmt.Println(path[K-1])
	}
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

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoInt64() (a int64, b int64) {
	res := readNInt64(2)
	a, b = res[0], res[1]
	return
}

func readThreeInt64() (a int64, b int64, c int64) {
	res := readNInt64(3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNInt64(n int) []int64 {
	res := make([]int64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64() uint64 {
	bytes, _ := reader.ReadBytes('\n')
	res := uint64(0)
	for i := 0; i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9'; i++ {
		res = res*10 + uint64(bytes[i]-'0')
	}
	return res
}

func readInt64() int64 {
	bytes, _ := reader.ReadBytes('\n')
	res := int64(0)
	sign := 1
	if bytes[0] == '-' {
		sign = -1
		bytes = bytes[1:]
	}
	for i := 0; i < len(bytes); i++ {
		res = res*10 + int64(bytes[i]-'0')
	}
	return res * int64(sign)
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
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
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64() uint64 {
	bytes, _ := reader.ReadBytes('\n')
	res := uint64(0)
	for i := 0; i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9'; i++ {
		res = res*10 + uint64(bytes[i]-'0')
	}
	return res
}

func readInt64() int64 {
	bytes, _ := reader.ReadBytes('\n')
	res := int64(0)
	sign := 1
	if bytes[0] == '-' {
		sign = -1
		bytes = bytes[1:]
	}
	for i := 0; i < len(bytes); i++ {
		res = res*10 + int64(bytes[i]-'0')
	}
	return res * int64(sign)
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
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
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoInt64()
		L := readNInt64(n)
		L = append([]int64{-1}, L...)
		path := []int64{1}
		ind := int64(0)
		count := int64(0)
		x := int64(1)
		t := int64(-1)
		flag := false
		Hash := make(map[int64]int64)

		for i := int64(0); i <= n; i++ {
			ne := L[x]

			if Hash[ne] > 0 {
				flag = true
				t = Hash[ne]
				break
			}

			path = append(path, ne)
			ind++

			Hash[ne] = ind

			x = ne
		}

		if flag {
			loop := path[t:]

			if k < int64(len(path)) {
				fmt.Println(path[k])
			} else {
				k = k - int64(len(path))
				k = k % int64(len(loop))
				fmt.Println(loop[k])
			}
		} else {
			fmt.Println(path[k-1])
		}
	}
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

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoInt64() (a int64, b int64) {
	res := readNInt64(2)
	a, b = res[0], res[1]
	return
}

func readThreeInt64() (a int64, b int64, c int64) {
	res := readNInt64(3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNInt64(n int) []int64 {
	res := make([]int64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64() uint64 {
	bytes, _ := reader.ReadBytes('\n')
	res := uint64(0)
	for i := 0; i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9'; i++ {
		res = res*10 + uint64(bytes[i]-'0')
	}
	return res
}

func readInt64() int64 {
	bytes, _ := reader.ReadBytes('\n')
	res := int64(0)
	sign := 1
	if bytes[0] == '-' {
		sign = -1
		bytes = bytes[1:]
	}
	for i := 0; i < len(bytes); i++ {
		res = res*10 + int64(bytes[i]-'0')
	}
	return res * int64(sign)
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
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
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoInt64()
		L := readNInt64(n)
		L = append([]int64{-1}, L...)
		path := []int64{1}
		ind := int64(0)
		count := int64(0)
		x := int64(1)
		t := int64(-1)
		flag := false
		Hash := make(map[int64]int64)

		for i := int64(0); i <= n; i++ {
			ne := L[x]

			if Hash[ne] > 0 {
				flag = true
				t = Hash[ne]
				break
			}

			path = append(path, ne)
			ind++

			Hash[ne] = ind

			x = ne
		}

		if flag {
			loop := path[t:]

			if k < int64(len(path)) {
				fmt.Println(path[k])
			} else {
				k = k - int64(len(path))
				k = k % int64(len(loop))
				fmt.Println(loop[k])
			}
		} else {
			fmt.Println(path[k-1])
		}
	}
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

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoInt64() (a int64, b int64) {
	res := readNInt64(2)
	a, b = res[0], res[1]
	return
}

func readThreeInt64() (a int64, b int64, c int64) {
	res := readNInt64(3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNInt64(n int) []int64 {
	res := make([]int64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64() uint64 {
	bytes, _ := reader.ReadBytes('\n')
	res := uint64(0)
	for i := 0; i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		res = res*10 + uint64(bytes[i]-'0')
		i++
	}
	return res
}

func readInt64() int64 {
	bytes, _ := reader.ReadBytes('\n')
	res := int64(0)
	for i := 0; i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		res = res*10 + int64(bytes[i]-'0')
		i++
	}
	return res
}

func readString(reader *bufio.Reader) strin