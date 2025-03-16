

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d", &a[i])
	}
	maxVal := 0
	maxSign := 0
	maxIndex := -1
	for i, a0 := range a {
		if abs(a0) > maxVal {
			maxVal = abs(a0)
			maxSign = mySign(a0)
			maxIndex = i
		}
	}
	if maxSign == 0 {
		fmt.Fprintln(w, 0)
	} else if maxSign == 1 {
		fmt.Fprintln(w, 2*n-1)
		fmt.Fprintf(w, "%d %d\n", maxIndex+1, 1)
		for i := 1; i < n; i++ {
			fmt.Fprintf(w, "%d %d\n", i+1, i+2)
		}
	} else {
		fmt.Fprintln(w, 2*n-1)
		fmt.Fprintf(w, "%d %d\n", maxIndex+1, 1)
		for i := n - 1; i > 0; i-- {
			fmt.Fprintf(w, "%d %d\n", i+1, i)
		}
	}
	w.Flush()
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func mySign(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	}
	return 0
}

func I() int {
	s, _ := r.ReadString('\n')
	x, _ := strconv.Atoi(s)
	return x
}

func II() (int, int) {
	s, _ := r.ReadString('\n')
	x, _ := strconv.Atoi(s[:len(s)-1])
	y, _ := strconv.Atoi(s[len(s)-1:])
	return x, y
}

func III() (int, int, int) {
	s, _ := r.ReadString('\n')
	x, _ := strconv.Atoi(s[:len(s)-1])
	y, _ := strconv.Atoi(s[len(s)-2:len(s)-1])
	z, _ := strconv.Atoi(s[len(s)-1:])
	return x, y, z
}

func Line(N int, num int) [][]int {
	if N <= 0 {
		return make([][]int, num)
	} else if num == 1 {
		res := make([][]int, N)
		for i := 0; i < N; i++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				x, _ := strconv.Atoi(x)
				res[i] = append(res[i], x)
			}
		}
		return res
	} else {
		res := make([][]int, num)
		for i := 0; i < num; i++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				x, _ := strconv.Atoi(x)
				res[i] = append(res[i], x)
			}
		}
		return res
	}
}

func Line2D(N int, M int) [][]int {
	res := make([][]int, N)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			x, _ := strconv.Atoi(x)
			res[i] = append(res[i], x)
		}
	}
	return res
}

func Line3D(N int, M int, K int) [][][]int {
	res := make([][][]int, N)
	for i := 0; i < N; i++ {
		res[i] = make([][]int, M)
		for j := 0; j < M; j++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				x, _ := strconv.Atoi(x)
				res[i][j] = append(res[i][j], x)
			}
		}
	}
	return res
}

func Read(r io.Reader) []int {
	var res []int
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		x, _ := strconv.Atoi(x)
		res = append(res, x)
	}
	return res
}

func Read2D(r io.Reader, N int, M int) [][]int {
	res := make([][]int, N)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			x, _ := strconv.Atoi(x)
			res[i] = append(res[i], x)
		}
	}
	return res
}

func Read3D(r io.Reader, N int, M int, K int) [][][]int {
	res := make([][][]int, N)
	for i := 0; i < N; i++ {
		res[i] = make([][]int, M)
		for j := 0; j < M; j++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				x, _ := strconv.Atoi(x)
				res[i][j] = append(res[i][j], x)
			}
		}
	}
	return res
}

func ReadStr(r io.Reader) []string {
	var res []string
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		res = append(res, x)
	}
	return res
}

func ReadStr2D(r io.Reader, N int, M int) [][]string {
	res := make([][]string, N)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			res[i] = append(res[i], x)
		}
	}
	return res
}

func ReadStr3D(r io.Reader, N int, M int, K int) [][][]string {
	res := make([][][]string, N)
	for i := 0; i < N; i++ {
		res[i] = make([][]string, M)
		for j := 0; j < M; j++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				res[i][j] = append(res[i][j], x)
			}
		}
	}
	return res
}

func ReadMap(r io.Reader) map[string]int {
	m := make(map[string]int)
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		m[x]++
	}
	return m
}

func ReadMap2D(r io.Reader, N int, M int) map[string][][]int {
	m := make(map[string][][]int)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			m[x] = append(m[x], i)
		}
	}
	return m
}

func ReadMap3D(r io.Reader, N int, M int, K int) map[string][][][]int {
	m := make(map[string][][][]int)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				m[x] = append(m[x], i, j)
			}
		}
	}
	return m
}

func ReadMapStr(r io.Reader) map[string]string {
	m := make(map[string]string)
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		m[x]++
	}
	return m
}

func ReadMapStr2D(r io.Reader, N int, M int) map[string][][]string {
	m := make(map[string][][]string)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			m[x] = append(m[x], i)
		}
	}
	return m
}

func ReadMapStr3D(r io.Reader, N int, M int, K int) map[string][][][]string {
	m := make(map[string][][][]string)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				m[x] = append(m[x], i, j)
			}
		}
	}
	return m
}

func ReadMapInt(r io.Reader) map[int]int {
	m := make(map[int]int)
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		m[x]++
	}
	return m
}

func ReadMapInt2D(r io.Reader, N int, M int) map[int][][]int {
	m := make(map[int][][]int)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			m[x] = append(m[x], i)
		}
	}
	return m
}

func ReadMapInt3D(r io.Reader, N int, M int, K int) map[int][][][]int {
	m := make(map[int][][][]int)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				m[x] = append(m[x], i, j)
			}
		}
	}
	return m
}

func ReadMapStrInt(r io.Reader) map[string]map[int]int {
	m := make(map[string]map[int]int)
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		m[x]++
	}
	return m
}

func ReadMapStrInt2D(r io.Reader, N int, M int) map[string][][]map[int]int {
	m := make(map[string][][]map[int]int)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			m[x] = append(m[x], i)
		}
	}
	return m
}

func ReadMapStrInt3D(r io.Reader, N int, M int, K int) map[string][][][]map[int]int {
	m := make(map[string][][][]map[int]int)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				m[x] = append(m[x], i, j)
			}
		}
	}
	return m
}

func ReadMapIntStr(r io.Reader) map[int]map[string]int {
	m := make(map[int]map[string]int)
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		m[x]++
	}
	return m
}

func ReadMapIntStr2D(r io.Reader, N int, M int) map[int][][]map[string]int {
	m := make(map[int][][]map[string]int)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			m[x] = append(m[x], i)
		}
	}
	return m
}

func ReadMapIntStr3D(r io.Reader, N int, M int, K int) map[int][][][]map[string]int {
	m := make(map[int][][][]map[string]int)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				m[x] = append(m[x], i, j)
			}
		}
	}
	return m
}

func ReadMapStrIntStr(r io.Reader) map[string]map[int]map[string]int {
	m := make(map[string]map[int]map[string]int)
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		m[x]++
	}
	return m
}

func ReadMapStrIntStr2D(r io.Reader, N int, M int) map[string][][]map[int]map[string]int {
	m := make(map[string][][]map[int]map[string]int)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			m[x] = append(m[x], i)
		}
	}
	return m
}

func ReadMapStrIntStr3D(r io.Reader, N int, M int, K int) map[string][][][]map[int]map[string]int {
	m := make(map[string][][][]map[int]map[string]int)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			s, _ := r.ReadString('\n')
			s = s[:len(s)-1]
			for _, x := range strings.Split(s, " ") {
				m[x] = append(m[x], i, j)
			}
		}
	}
	return m
}

func ReadMapIntStrIntStr(r io.Reader) map[int]map[string]map[int]map[string]int {
	m := make(map[int]map[string]map[int]map[string]int)
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		m[x]++
	}
	return m
}

func ReadMapIntStrIntStr2D(r io.Reader, N int, M int) map[int][][]map[string]map[int]map[string]int {
	m := make(map[int][][]map[string]map[int]int)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			m[x] = append(m[x], i)
		}
	}
	return m
}

func ReadMapIntStrIntStr3D(r io.Reader, N int, M int, K int) map[int][][][]map[string]map[int]int {
	m := make(map[int][][][]map[string]map[int]int)
	for i := 0; i < N; i++ {
		s, _ := r.ReadString('\n')
		s = s[:len(s)-1]
		for _, x := range strings.Split(s, " ") {
			m[x] = append(m[x], i)
		}
	}
	return m
}

func ReadMapStrIntStr(r io.Reader) map[string]map[int]map[string]int {
	m := make(map[string]map[int]map[string]int)
	s, _ := r.ReadString('\n')
	for _, x := range strings.Split(s, " ") {
		m[x] = append(m[x], i)
	}
	return m
}

func ReadMapStrIntStr2D(r io.Reader, N int, M int) map[string][][]map[int]int {
	m := make(map[string][][]int)
	for i := 0;