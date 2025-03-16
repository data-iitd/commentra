
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		balls := make([][]int, n)
		for i := 0; i < n; i++ {
			balls[i] = make([]int, 2)
		}
		balls[0][0] = 0
		balls[0][1] = 1
		for i := 0; i < m; i++ {
			x, y := readTwoNums(reader)
			x--
			y--
			w_x, r_x := balls[x][0], balls[x][1]
			w_y, r_y := balls[y][0], balls[y][1]
			if w_x >= 1 && r_x >= 1 {
				balls[x][0]--
				balls[y][1]++
			} else if w_x == 0 {
				balls[x][1]--
				balls[y][1]++
			} else {
				balls[x][0]--
				balls[y][0]++
			}
		}
		var res int
		for i := 0; i < n; i++ {
			if balls[i][1] > 0 {
				res++
			}
		}
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
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

	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		balls := make([][]int, n)
		for i := 0; i < n; i++ {
			balls[i] = make([]int, 2)
		}
		balls[0][0] = 0
		balls[0][1] = 1
		for i := 0; i < m; i++ {
			x, y := readTwoNums(reader)
			x--
			y--
			w_x, r_x := balls[x][0], balls[x][1]
			w_y, r_y := balls[y][0], balls[y][1]
			if w_x >= 1 && r_x >= 1 {
				balls[x][0]--
				balls[y][1]++
			} else if w_x == 0 {
				balls[x][1]--
				balls[y][1]++
			} else {
				balls[x][0]--
				balls[y][0]++
			}
		}
		var res int
		for i := 0; i < n; i++ {
			if balls[i][1] > 0 {
				res++
			}
		}
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
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

	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		balls := make([][]int, n)
		for i := 0; i < n; i++ {
			balls[i] = make([]int, 2)
		}
		balls[0][0] = 0
		balls[0][1] = 1
		for i := 0; i < m; i++ {
			x, y := readTwoNums(reader)
			x--
			y--
			w_x, r_x := balls[x][0], balls[x][1]
			w_y, r_y := balls[y][0], balls[y][1]
			if w_x >= 1 && r_x >= 1 {
				balls[x][0]--
				balls[y][1]++
			} else if w_x == 0 {
				balls[x][1]--
				balls[y][1]++
			} else {
				balls[x][0]--
				balls[y][0]++
			}
		}
		var res int
		for i := 0; i < n; i++ {
			if balls[i][1] > 0 {
				res++
			}
		}
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
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

	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		balls := make([][]int, n)
		for i := 0; i < n; i++ {
			balls[i] = make([]int, 2)
		}
		balls[0][0] = 0
		balls[0][1] = 1
		for i := 0; i < m; i++ {
			x, y := readTwoNums(reader)
			x--
			y--
			w_x, r_x := balls[x][0], balls[x][1]
			w_y, r_y := balls[y][0], balls[y][1]
			if w_x >= 1 && r_x >= 1 {
				balls[x][0]--
				balls[y][1]++
			} else if w_x == 0 {
				balls[x][1]--
				balls[y][1]++
			} else {
				balls[x][0]--
				balls[y][0]++
			}
		}
		var res int
		for i := 0; i < n; i++ {
			if balls[i][1] > 0 {
				res++
			}
		}
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
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

	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		balls := make([][]int, n)
		for i := 0; i < n; i++ {
			balls[i] = make([]int, 2)
		}
		balls[0][0] = 0
		balls[0][1] = 1
		for i := 0; i < m; i++ {
			x, y := readTwoNums(reader)
			x--
			y--
			w_x, r_x := balls[x][0], balls[x][1]
			w_y, r_y := balls[y][0], balls[y][1]
			if w_x >= 1 && r_x >= 1 {
				balls[x][0]--
				balls[y][1]++
			} else if w_x == 0 {
				balls[x][1]--
				balls[y][1]++
			} else {
				balls[x][0]--
				balls[y][0]++
			}
		}
		var res int
		for i := 0; i < n; i++ {
			if balls[i][1] > 0 {
				res++
			}
		}
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
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

func readNNums(reader *bufio.Reader, n int) {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
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
	num := 0
	for i := 0; i < n; i++ {
		num = num*10 + int(bs[i]-'0')
		i++
	}
	*val = num
	return val
}

func readTwoNums(reader *bufio.Reader) 