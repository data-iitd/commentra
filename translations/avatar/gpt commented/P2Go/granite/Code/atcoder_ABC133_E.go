
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	N, K := readTwoNums(reader)
	graph := make([][]int, N)
	for i := 0; i < N; i++ {
		graph[i] = make([]int, 0, 2)
	}
	for i := 0; i < N-1; i++ {
		a, b := readTwoNums(reader)
		a--
		b--
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	mod := int(1e9 + 7)
	var dfs func(p, u int, f int) int
	dfs = func(p, u int, f int) int {
		caseNum := f
		colorNum := K - 1
		if f == K {
			colorNum = K - 2
		}
		for _, v := range graph[u] {
			if v == p {
				continue
			}
			pat := dfs(u, v, colorNum)
			if pat == 0 {
				caseNum = 0
				break
			}
			caseNum = int(int64(caseNum) * int64(pat) % int64(mod))
			colorNum--
		}
		return caseNum
	}

	res := dfs(-1, 0, K)

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

	N, K := readTwoNums(reader)
	graph := make([][]int, N)
	for i := 0; i < N; i++ {
		graph[i] = make([]int, 0, 2)
	}
	for i := 0; i < N-1; i++ {
		a, b := readTwoNums(reader)
		a--
		b--
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	mod := int(1e9 + 7)
	var dfs func(p, u int, f int) int
	dfs = func(p, u int, f int) int {
		caseNum := f
		colorNum := K - 1
		if f == K {
			colorNum = K - 2
		}
		for _, v := range graph[u] {
			if v == p {
				continue
			}
			pat := dfs(u, v, colorNum)
			if pat == 0 {
				caseNum = 0
				break
			}
			caseNum = int(int64(caseNum) * int64(pat) % int64(mod))
			colorNum--
		}
		return caseNum
	}

	res := dfs(-1, 0, K)

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

	N, K := readTwoNums(reader)
	graph := make([][]int, N)
	for i := 0; i < N; i++ {
		graph[i] = make([]int, 0, 2)
	}
	for i := 0; i < N-1; i++ {
		a, b := readTwoNums(reader)
		a--
		b--
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	mod := int(1e9 + 7)
	var dfs func(p, u int, f int) int
	dfs = func(p, u int, f int) int {
		caseNum := f
		colorNum := K - 1
		if f == K {
			colorNum = K - 2
		}
		for _, v := range graph[u] {
			if v == p {
				continue
			}
			pat := dfs(u, v, colorNum)
			if pat == 0 {
				caseNum = 0
				break
			}
			caseNum = int(int64(caseNum) * int64(pat) % int64(mod))
			colorNum--
		}
		return caseNum
	}

	res := dfs(-1, 0, K)

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

	N, K := readTwoNums(reader)
	graph := make([][]int, N)
	for i := 0; i < N; i++ {
		graph[i] = make([]int, 0, 2)
	}
	for i := 0; i < N-1; i++ {
		a, b := readTwoNums(reader)
		a--
		b--
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	mod := int(1e9 + 7)
	var dfs func(p, u int, f int) int
	dfs = func(p, u int, f int) int {
		caseNum := f
		colorNum := K - 1
		if f == K {
			colorNum = K - 2
		}
		for _, v := range graph[u] {
			if v == p {
				continue
			}
			pat := dfs(u, v, colorNum)
			if pat == 0 {
				caseNum = 0
				break
			}
			caseNum = int(int64(caseNum) * int64(pat) % int64(mod))
			colorNum--
		}
		return caseNum
	}

	res := dfs(-1, 0, K)

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

	N, K := readTwoNums(reader)
	graph := make([][]int, N)
	for i := 0; i < N; i++ {
		graph[i] = make([]int, 0, 2)
	}
	for i := 0; i < N-1; i++ {
		a, b := readTwoNums(reader)
		a--
		b--
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	mod := int(1e9 + 7)
	var dfs func(p, u int, f int) int
	dfs = func(p, u int, f int) int {
		caseNum := f
		colorNum := K - 1
		if f == K {
			colorNum = K - 2
		}
		for _, v := range graph[u] {
			if v == p {
				continue
			}
			pat := dfs(u, v, colorNum)
			if pat == 0 {
				caseNum = 0
				break
			}
			caseNum = int(int64(caseNum) * int64(pat) % int64(mod))
			colorNum--
		}
		return caseNum
	}

	res := dfs(-1, 0, K)

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

	N, K := readTwoNums(reader)
	graph := make([][]int, N)
	for i := 0; i < N; i++ {
		graph[i] = make([]int, 0, 2)
	}
	for i := 0; i < N-1; i++ {
		a, b := readTwoNums(reader)
		a, b = a-1, b-1
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	mod := int(1e9 + 7)
	dfs := func(u int, f int) int {
		caseNum := f
		colorNum := K - 1
		if f == K {
			colorNum = K - 2
		}
		for _, v := range graph[u] {
			if v == p {
				continue
			}
			pat := dfs(u, v, colorNum)
			if pat == 0 {
				caseNum = 0
				