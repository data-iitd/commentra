
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
	h, w := readTwoNums(reader)
	graph := make([][]int, h)
	for i := 0; i < h; i++ {
		graph[i] = readNNums(reader, w)
	}
	for x := 1; x < w; x++ {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x-1] + 1
			}
		}
	}
	for x := w - 2; x >= 0; x-- {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x+1] + 1
			}
		}
	}
	for y := 1; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y-1][x] + 1
			}
		}
	}
	for y := h - 2; y >= 0; y-- {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y+1][x] + 1
			}
		}
	}
	res := 0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > res {
				res = graph[y][x]
			}
		}
	}
	fmt.Println(res)
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
	h, w := readTwoNums(reader)
	graph := make([][]int, h)
	for i := 0; i < h; i++ {
		graph[i] = readNNums(reader, w)
	}
	for x := 1; x < w; x++ {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x-1] + 1
			}
		}
	}
	for x := w - 2; x >= 0; x-- {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x+1] + 1
			}
		}
	}
	for y := 1; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y-1][x] + 1
			}
		}
	}
	for y := h - 2; y >= 0; y-- {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y+1][x] + 1
			}
		}
	}
	res := 0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > res {
				res = graph[y][x]
			}
		}
	}
	fmt.Println(res)
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
	h, w := readTwoNums(reader)
	graph := make([][]int, h)
	for i := 0; i < h; i++ {
		graph[i] = readNNums(reader, w)
	}
	for x := 1; x < w; x++ {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x-1] + 1
			}
		}
	}
	for x := w - 2; x >= 0; x-- {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x+1] + 1
			}
		}
	}
	for y := 1; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y-1][x] + 1
			}
		}
	}
	for y := h - 2; y >= 0; y-- {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y+1][x] + 1
			}
		}
	}
	res := 0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > res {
				res = graph[y][x]
			}
		}
	}
	fmt.Println(res)
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
	h, w := readTwoNums(reader)
	graph := make([][]int, h)
	for i := 0; i < h; i++ {
		graph[i] = readNNums(reader, w)
	}
	for x := 1; x < w; x++ {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x-1] + 1
			}
		}
	}
	for x := w - 2; x >= 0; x-- {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x+1] + 1
			}
		}
	}
	for y := 1; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y-1][x] + 1
			}
		}
	}
	for y := h - 2; y >= 0; y-- {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y+1][x] + 1
			}
		}
	}
	res := 0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > res {
				res = graph[y][x]
			}
		}
	}
	fmt.Println(res)
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
	h, w := readTwoNums(reader)
	graph := make([][]int, h)
	for i := 0; i < h; i++ {
		graph[i] = readNNums(reader, w)
	}
	for x := 1; x < w; x++ {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x-1] + 1
			}
		}
	}
	for x := w - 2; x >= 0; x-- {
		for y := 0; y < h; y++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y][x+1] + 1
			}
		}
	}
	for y := 1; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y-1][x] + 1
			}
		}
	}
	for y := h - 2; y >= 0; y-- {
		for x := 0; x < w; x++ {
			if graph[y][x] == 0 {
				graph[y][x] = graph[y+1][x] + 1
			}
		}
	}
	res := 0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > res {
				res = graph[y][x]
			}
		}
	}
	fmt.Println(res)
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

func readNNums(reader, n int) {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9' ) && bs[x]!= '-' ) {
			x++
		}
		x = readInt(bs, x, &res[i] )
	return
}

func readUint64(bytes []byte, from int, val *uint64 ) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' ) {
		tmp = tmp*10 + uint64 (bytes[i] - '0' )
		i++
	}
	*val = tmp * sign
	return
}

func main() {
	reader := bufio.NewReader(os.Stdin )
	h, w := readTwoNums(reader, 2 )
	graph := make([][]int, h )
	for i := 0; i < h; i++ {
		graph[i] = readNNum