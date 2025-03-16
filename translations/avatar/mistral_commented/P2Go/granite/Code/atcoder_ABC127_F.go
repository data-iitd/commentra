
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	q, _ := readTwoNums(reader)
	ans := make([]int, 2)

	p1 := make([]int, 0)
	p2 := make([]int, 0)

	var sum_b int
	var sum_p1 int
	var sum_p2 int

	for i := 0; i < q; i++ {
		ops, _ := readThreeNums(reader)

		if ops[0] == 2 {
			if len(p1) == len(p2) {
				fmt.Printf("%d %d\n", p2[0], sum_p1-len(p1)*p2[0]+len(p2)*p2[0]-sum_p2+sum_b)
			} else {
				fmt.Printf("%d %d\n", p1[0], sum_p1-len(p1)*p1[0]+len(p2)*p1[0]-sum_p2+sum_b)
			}
		} else {
			sum_b += ops[2]

			if len(p1) == 0 {
				p1 = append(p1, ops[1])
				sum_p1 += ops[1]
			} else if p1[0] <= ops[1] {
				p1 = append(p1, ops[1])
				sum_p1 += ops[1]
			} else {
				p2 = append(p2, -ops[1])
				sum_p2 += ops[1]
				sum_p1 -= ops[1]
				sum_p2 -= ops[1]
			}

			if len(p1) < len(p2) {
				k := p2[0]
				p2 = p2[1:]
				p1 = append(p1, -k)
				sum_p2 += k
				sum_p1 -= k
			}

			if len(p1)-1 > len(p2) {
				k := p1[0]
				p1 = p1[1:]
				p2 = append(p2, -k)
				sum_p1 -= k
				sum_p2 += k
			}
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

func main() {
	reader := bufio.NewReader(os.Stdin)

	q, _ := readTwoNums(reader)
	ans := make([]int, 2)

	p1 := make([]int, 0)
	p2 := make([]int, 0)

	var sum_b int
	var sum_p1 int
	var sum_p2 int

	for i := 0; i < q; i++ {
		ops, _ := readThreeNums(reader)

		if ops[0] == 2 {
			if len(p1) == len(p2) {
				fmt.Printf("%d %d\n", p2[0], sum_p1-len(p1)*p2[0]+len(p2)*p2[0]-sum_p2+sum_b)
			} else {
				fmt.Printf("%d %d\n", p1[0], sum_p1-len(p1)*p1[0]+len(p2)*p1[0]-sum_p2+sum_b)
			}
		} else {
			sum_b += ops[2]

			if len(p1) == 0 {
				p1 = append(p1, ops[1])
				sum_p1 += ops[1]
			} else if p1[0] <= ops[1] {
				p1 = append(p1, ops[1])
				sum_p1 += ops[1]
			} else {
				p2 = append(p2, -ops[1])
				sum_p2 += ops[1]
				sum_p1 -= ops[1]
				sum_p2 -= ops[1]
			}

			if len(p1) < len(p2) {
				k := p2[0]
				p2 = p2[1:]
				p1 = append(p1, -k)
				sum_p2 += k
				sum_p1 -= k
			}

			if len(p1)-1 > len(p2) {
				k := p1[0]
				p1 = p1[1:]
				p2 = append(p2, -k)
				sum_p1 -= k
				sum_p2 += k
			}
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