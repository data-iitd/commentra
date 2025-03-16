package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

const PI = 3.141592653589793238462643383279502884197169399375105820974
const ten5p1 = 100001
const ten6p1 = 1000001
const ten8p1 = 100000001
const ten9p1 = 1000000001

func readc() byte {
	var varr [1]byte
	os.Stdin.Read(varr[:])
	return varr[0]
}

func readi() int {
	var varr [11]byte
	os.Stdin.Read(varr[:])
	var s string = string(varr[:])
	res, _ := strconv.Atoi(s)
	return res
}

func readll() int64 {
	var varr [20]byte
	os.Stdin.Read(varr[:])
	var s string = string(varr[:])
	res, _ := strconv.ParseInt(s, 10, 64)
	return res
}

func repread(data []int) {
	for i := 0; i < len(data); i++ {
		data[i] = readi()
	}
}

func repreadll(data []int64) {
	for i := 0; i < len(data); i++ {
		data[i] = readll()
	}
}

func reads(maxsize int) string {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.TrimRight(str, "\n")
	return str
}

func writec(c byte) {
	os.Stdout.Write([]byte{c})
}

func writecsp(c byte) {
	os.Stdout.Write([]byte{c, ' '})
}

func writecln(c byte) {
	os.Stdout.Write([]byte{c, '\n'})
}

func writei(i int) {
	os.Stdout.Write([]byte(strconv.Itoa(i)))
}

func writeisp(i int) {
	os.Stdout.Write([]byte(strconv.Itoa(i) + " "))
}

func writellsp(i int64) {
	os.Stdout.Write([]byte(strconv.FormatInt(i, 10) + " "))
}

func writeiln(i int) {
	os.Stdout.Write([]byte(strconv.Itoa(i) + "\n"))
}

func writellln(i int64) {
	os.Stdout.Write([]byte(strconv.FormatInt(i, 10) + "\n"))
}

func writeulln(i uint64) {
	os.Stdout.Write([]byte(strconv.FormatUint(i, 10) + "\n"))
}

func writefln(f float64) {
	os.Stdout.Write([]byte(strconv.FormatFloat(f, 'f', -1, 64) + "\n"))
}

func writes(s string) {
	os.Stdout.Write([]byte(s))
}

func writesp() {
	os.Stdout.Write([]byte(" "))
}

func writeln() {
	os.Stdout.Write([]byte("\n"))
}

func iseven(x int) bool {
	return x&1 == 0
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func reversei(data []int, n int) {
	for i := 0; i < n/2; i++ {
		data[i], data[n-i-1] = data[n-i-1], data[i]
	}
}

func bsearch(val int, data []int, n int) int {
	if data[0] > val {
		return -1
	}
	if data[n-1] < val {
		return n
	}
	l, r := 0, n-1
	for l < r {
		mid := (l + r + 1) / 2
		if data[mid] <= val {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if data[r] != val {
		r++
	}
	return r
}

type Veci struct {
	data []int
	size int
	n    int
}

func initVeci(t *Veci, size int) {
	t.data = make([]int, size)
	t.size = size
	t.n = 0
}

func resizeVeci(t *Veci) {
	ns := int(float32(t.size) * 1.2)
	t.data = append(t.data, make([]int, ns-t.size)...)
	t.size = ns
}

func addVeci(t *Veci, val int) {
	if t.n >= t.size {
		resizeVeci(t)
	}
	t.data[t.n] = val
	t.n++
}

type Vecll struct {
	data []int64
	size int
	n    int
}

func initVecll(t *Vecll, size int) {
	t.data = make([]int64, size)
	t.size = size
	t.n = 0
}

func resizeVecll(t *Vecll) {
	ns := int(float32(t.size) * 1.2)
	t.data = append(t.data, make([]int64, ns-t.size)...)
	t.size = ns
}

func addVecll(t *Vecll, val int64) {
	if t.n >= t.size {
		resizeVecll(t)
	}
	t.data[t.n] = val
	t.n++
}

type Vecs struct {
	data []string
	size int
	n    int
}

func initVecs(t *Vecs, size int) {
	t.data = make([]string, size)
	t.size = size
	t.n = 0
}

func resizeVecs(t *Vecs) {
	ns := int(float32(t.size) * 1.2)
	t.data = append(t.data, make([]string, ns-t.size)...)
	t.size = ns
}

func addVecs(t *Vecs, val string) {
	if t.n >= t.size {
		resizeVecs(t)
	}
	t.data[t.n] = val
	t.n++
}

func ispali(a, b []int, n int) int {
	for i := 0; i < n; i++ {
		if a[i] != b[n-i-1] {
			return 0
		}
	}
	return 1
}

func ispalc(a, b []byte, n int) int {
	for i := 0; i < n; i++ {
		if a[i] != b[n-i-1] {
			return 0
		}
	}
	return 1
}

type Pairi struct {
	x, y int
}

func cmpPairi(a, b *Pairi) int {
	if a.x == b.x {
		if a.y < b.y {
			return -1
		} else {
			return 1
		}
	}
	if a.x < b.x {
		return -1
	} else {
		return 1
	}
}

func sortPairi(d []Pairi, n int) {
	quickSortPairi(d, 0, n-1)
}

func quickSortPairi(d []Pairi, left, right int) {
	if left >= right {
		return
	}
	pivot := d[left+(right-left)/2]
	i, j := left, right
	for i <= j {
		for cmpPairi(&d[i], &pivot) < 0 {
			i++
		}
		for cmpPairi(&d[j], &pivot) > 0 {
			j--
		}
		if i <= j {
			d[i], d[j] = d[j], d[i]
			i++
			j--
		}
	}
	quickSortPairi(d, left, j)
	quickSortPairi(d, i, right)
}

func expmod(x, n, m int64) int64 {
	ans := int64(1)
	for ; n > 0; n >>= 1 {
		if n&1 == 1 {
			ans = (ans * x) % m
		}
		x = (x * x) % m
	}
	return ans
}

func combmod(n, k, m int64) int64 {
	ret := int64(1)
	div := int64(1)
	for i := int64(0); i < k; i++ {
		ret = (ret * (n - i) % m) % m
		div = (div * (i + 1)) % m
	}
	div = expmod(div, m-2, m)
	return (ret * div) % m
}

func main() {
	RUN_LOCAL("dataabc155A.txt")
	a := readi()
	b := readi()
	if a < b {
		for i := 0; i < b; i++ {
			writei(a)
		}
		writeln()
	} else {
		for i := 0; i < a; i++ {
			writei(b)
		}
		writeln()
	}
}

