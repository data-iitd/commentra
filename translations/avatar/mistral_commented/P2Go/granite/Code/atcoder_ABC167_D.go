
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Taking the number of nodes 'N' and the number of edges 'K' as input
	N, K := readTwoInt()

	// Initializing the list 'L' with the given number of edges
	L := readNInt64s(N)

	// Adding a special node with index -1 at the beginning of the list 'L'
	L = append([]int64{-1}, L...)

	// Initializing an empty list 'path' to store the shortest path
	path := []int64{1}

	// Initializing variables 'ind' and 'count'
	ind := 0
	count := 0

	// Initializing variables 'x' and 't'
	x := int64(1)
	t := int64(-1)

	// Initializing a boolean variable 'flag'
	flag := false

	// Creating an empty dictionary 'Hash' using map
	Hash := make(map[int64]int64)

	// Traversing through all the nodes from 0 to 'N'
	for i := int64(0); i <= N; i++ {
		// Getting the next edge 'ne' from the current node 'x'
		ne := L[x]

		// Checking if the current node 'ne' is already in the hash table 'Hash'
		if Hash[ne]!= 0 {
			// Setting the boolean variable 'flag' to True and storing the index of the previous occurrence of the node 'ne' in 't'
			flag = true
			t = Hash[ne]
			break
		}

		// Appending the next edge 'ne' to the list 'path'
		path = append(path, ne)

		// Incrementing the index 'ind' and storing it in the hash table 'Hash' with the key as the current node 'ne' and value as 'ind'
		ind++
		Hash[ne] = int64(ind)

		// Updating the current node 'x' to the next node 'ne'
		x = ne
	}

	// Checking if there is a cycle in the graph
	if flag == true {
		// Storing the list of nodes in the cycle 'loop'
		loop := path[t:]

		// Checking if the length of the path is less than 'K'
		if len(path) < int(K) {
			// Printing the 'K'th node in the path
			fmt.Println(path[K])
		}

		// If the length of the path is greater than or equal to 'K', then we need to find the 'K'th node in the cycle 'loop'
		else {
			// Updating the value of 'K' by subtracting the length of the path and taking the modulo with the length of the cycle 'loop'
			K = K - int64(len(path))
			K = K % int64(len(loop))

			// Printing the 'K'th node in the cycle 'loop'
			fmt.Println(loop[K])
		}
	}

	// If there is no cycle in the graph, then we simply print the 'K'th node in the path
	else {
		// Printing the 'K'th node in the path
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

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readInt64(bytes []byte, from int, val *int64) int {
	i := from
	var tmp int64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int64(bytes[i]-'0')
		i++
	}
	*val = tmp
	return i
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readInt64(s, pos, &res[i])
	}

	return res
}

func readUint64s(reader *bufio.Reader, n int) []uint64 {
	res := make([]uint64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readUint64(s, pos, &res[i])
	}

	return res
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

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readInt64(bytes []byte, from int, val *int64) int {
	i := from
	var tmp int64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int64(bytes[i]-'0')
		i++
	}
	*val = tmp
	return i
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readInt64(s, pos, &res[i])
	}

	return res
}

func readUint64s(reader *bufio.Reader, n int) []uint64 {
	res := make([]uint64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readUint64(s, pos, &res[i])
	}

	return res
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
		n, k := readTwoNums(reader)
		L := readNInt64s(reader, n)
		res := solve(n, k, L)
		fmt.Println(res)
	}
}

func solve(n int, k int, L []int64) int64 {
	path := []int64{1}
	ind := 0
	count := 0
	x := int64(1)
	t := int64(-1)
	flag := false
	hash := make(map[int64]int64)

	for i := int64(0); i <= n; i++ {
		ne := L[x-1]
		if hash[ne]!= 0 {
			flag = true
			t = hash[ne]
			break
		}
		path = append(path, ne)
		ind++
		hash[ne] = int64(ind)
		x = ne
	}

	if flag {
		loop := path[t:]
		if len(path) < k {
			return path[k]
		}
		k -= len(path)
		k %= int64(len(loop))
		return loop[k]
	}

	return path[k-1]
}