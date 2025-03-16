
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
		n := readNum(reader)
		P := make([][]int, n)
		for i := 0; i < n; i++ {
			P[i] = readNNums(reader, 2)
		}
		res := solve(P)
		for i := 0; i < n; i++ {
			buf.WriteString(fmt.Sprintf("%.20f\n", res[i]))
		}
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

func solve(P [][]int) []float64 {
	n := len(P)
	if n == 2 {
		return []float64{0.5, 0.5}
	}
	ch := make([]int, n)
	m := jarvis(P, n, ch)
	var sum float64
	for i := 0; i < m; i++ {
		sum += angle(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]])
	}
	ans := make([]float64, n)
	for i := 0; i < n; i++ {
		ans[i] = angle(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]]) / (2 * PI)
	}
	return ans
}

const PI = 3.14159265358979323846

func angle(p1, p2, p3 []int) float64 {
	dx1 := float64(p2[0]) - float64(p1[0])
	dy1 := float64(p2[1]) - float64(p1[1])
	dx2 := float64(p3[0]) - float64(p1[0])
	dy2 := float64(p3[1]) - float64(p1[1])
	return math.Acos(dx1*dx2+dy1*dy2)
}

func jarvis(P [][]int, n int, ch []int) int {
	var d, i, o, s, l, t int
	for d = 0; d < n; d++ {
		if P[d][0] < P[l][0] || P[d][0] == P[l][0] && P[d][1] < P[l][1] {
			l = d
		}
	}
	ch[0] = l
	s = l
	d = 1
	for {
		o = l
		for i = 0; i < n; i++ {
			if cross(P[o], P[l], P[i]) > 0 || cross(P[o], P[l], P[i]) == 0 && between(P[l], P[o], P[i]) <= 0 {
				l = i
			}
		}
		ch[d] = l
		d++
		if l == s {
			break
		}
	}
	return d - 1
}

func cross(p1, p2, p3 []int) int {
	dx1 := float64(p2[0]) - float64(p1[0])
	dy1 := float64(p2[1]) - float64(p1[1])
	dx2 := float64(p3[0]) - float64(p1[0])
	dy2 := float64(p3[1]) - float64(p1[1])
	return int(dx1 * dy2 - dx2 * dy1)
}

func between(p1, p2, p3 []int) int {
	return (p3[0]-p1[0])*(p2[0]-p1[0]) + (p3[1]-p1[1])*(p2[1]-p1[1])
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		P := make([][]int, n)
		for i := 0; i < n; i++ {
			P[i] = readNNums(reader, 2)
		}
		res := solve(P)
		for i := 0; i < n; i++ {
			buf.WriteString(fmt.Sprintf("%.20f\n", res[i]))
		}
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

func solve(P [][]int) []float64 {
	n := len(P)
	if n == 2 {
		return []float64{0.5, 0.5}
	}
	ch := make([]int, n)
	m := jarvis(P, n, ch)
	var sum float64
	for i := 0; i < m; i++ {
		sum += angle(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]])
	}
	ans := make([]float64, n)
	for i := 0; i < n; i++ {
		ans[i] = angle(P[ch[i]], P[ch[(i-1+m)%m]], P[ch[(i+1)%m]]) / (2 * PI)
	}
	return ans
}

const PI = 3.14159265358979323846

func angle(p1, p2, p3 []int) float64 {
	dx1 := float64(p2[0]) - float64(p1[0])
	dy1 := float64(p2[1]) - float64(p1[1])
	dx2 := float64(p3[0]) - float64(p1[0])
	dy2 := float64(p3[1]) - float64(p1[1])
	return math.Acos(dx1*dx2 + dy1*dy2)
}

func jarvis(P [][]int, n int, ch []int) int {
	var d, i, o, s, l, t int
	for d = 0; d < n; d++ {
		if P[d][0] < P[l][0] || P[d][0] == P[l][0] && P[d][1] < P[l][1] {
			l = d
		}
	}
	ch[0] = l
	s = l
	d = 1
	for {
		o = l
		for i = 0; i < n; i++ {
			if cross(P[o], P[l], P[i]) > 0 || cross(P[o], P[l], P[i]) == 0 && between(P[l], P[o], P[i]) <= 0 {
				l = i
			}
		}
		ch[d] = l
		d++
		if l == s {
			break
		}
	}
	return d - 1
}

func cross(p1, p2, p3 []int) int {
	dx1 := float64(p2[0]) - float64(p1[0])
	dy1 := float64(p2[1]) - float64(p1[1])
	dx2 := float64(p3[0]) - float64(p1[0])
	dy2 := float64(p3[1]) - float64(p1[1])
	return int(dx1 * dy2 - dx2 * dy1)
}

func between(p1, p2, p3 []int) int {
	return (p3[0]-p1[0])*(p2[0]-p1[0]) + (p3[1]-p1[1])*(p2[1]-p1[1])
}