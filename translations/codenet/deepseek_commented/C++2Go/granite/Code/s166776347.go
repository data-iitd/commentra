
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// 入力
	reader := bufio.NewReader(os.Stdin)
	N, K := readTwoInt64s(reader)
	A := readNInt64s(reader, N)

	// 解法
	ans1 := int64(0)
	for i := int64(0); i < N; i++ {
		for j := int64(0); j < N; j++ {
			if i >= j {
				continue
			}
			if A[i] > A[j] {
				ans1++
			}
			ans1 %= int64(1e9 + 7)
		}
	}

	// Count the frequency of each element in the array A
	count := make([]int64, 2005)
	for i := int64(0); i < N; i++ {
		count[A[i]-1]++
	}

	ans2 := int64(0)
	remain := N
	for i := int64(0); i < 2005; i++ {
		remain -= count[i]
		ans2 += count[i] * remain
	}

	// Calculate the final answer
	tmp := K * (K - 1)
	tmp /= 2
	tmp %= int64(1e9 + 7)
	tmp *= ans2
	tmp %= int64(1e9 + 7)
	ans := int64(0)
	ans += ans1 * K
	ans %= int64(1e9 + 7)
	ans += tmp
	ans %= int64(1e9 + 7)

	// Output the final answer
	fmt.Println(ans)
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

func main() {
	// 入力
	reader := bufio.NewReader(os.Stdin)
	N, K := readTwoInt64s(reader)
	A := readNInt64s(reader, N)

	// 解法
	ans1 := int64(0)
	for i := int64(0); i < N; i++ {
		for j := int64(0); j < N; j++ {
			if i >= j {
				continue
			}
			if A[i] > A[j] {
				ans1++
			}
			ans1 %= int64(1e9 + 7)
		}
	}

	// Count the frequency of each element in the array A
	count := make([]int64, 2005)
	for i := int64(0); i < N; i++ {
		count[A[i]-1]++
	}

	ans2 := int64(0)
	remain := N
	for i := int64(0); i < 2005; i++ {
		remain -= count[i]
		ans2 += count[i] * remain
	}

	// Calculate the final answer
	tmp := K * (K - 1)
	tmp /= 2
	tmp %= int64(1e9 + 7)
	tmp *= ans2
	tmp %= int64(1e9 + 7)
	ans := int64(0)
	ans += ans1 * K
	ans %= int64(1e9 + 7)
	ans += tmp
	ans %= int64(1e9 + 7)

	// Output the final answer
	fmt.Println(ans)
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