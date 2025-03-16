package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

var in = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

const PI = 3.141592653589793238462643383279502884197169399375105820974
const ten5p1 = 100001
const ten6p1 = 1000001
const ten8p1 = 100000001
const ten9p1 = 1000000001

func readInt() int {
	var n int
	fmt.Fscan(in, &n)
	return n
}

func readLong() int64 {
	var n int64
	fmt.Fscan(in, &n)
	return n
}

func readString() string {
	var str string
	fmt.Fscan(in, &str)
	return str
}

func readLine() string {
	var str string
	for {
		if str, _ = in.ReadString('\n'); str != "\n" && str != "\r\n" {
			break
		}
	}
	return strings.TrimSpace(str)
}

func writeChar(c byte) {
	out.WriteByte(c)
}

func writeCharSpace(c byte) {
	out.WriteByte(c)
	out.WriteByte(' ')
}

func writeCharLn(c byte) {
	out.WriteByte(c)
	out.WriteByte('\n')
}

func writeInt(n int) {
	out.WriteString(strconv.Itoa(n))
}

func writeIntSpace(n int) {
	out.WriteString(strconv.Itoa(n))
	out.WriteByte(' ')
}

func writeLongSpace(n int64) {
	out.WriteString(strconv.FormatInt(n, 10))
	out.WriteByte(' ')
}

func writeIntLn(n int) {
	out.WriteString(strconv.Itoa(n))
	out.WriteByte('\n')
}

func writeLongLn(n int64) {
	out.WriteString(strconv.FormatInt(n, 10))
	out.WriteByte('\n')
}

func writeUintLn(n uint) {
	out.WriteString(strconv.FormatUint(uint64(n), 10))
	out.WriteByte('\n')
}

func writeFloatLn(n float64) {
	out.WriteString(strconv.FormatFloat(n, 'f', -1, 64))
	out.WriteByte('\n')
}

func writeString(str string) {
	out.WriteString(str)
}

func writeSpace() {
	out.WriteByte(' ')
}

func writeLn() {
	out.WriteByte('\n')
}

func isEven(x int) bool {
	return x&1 == 0
}

func reverseInt(data []int) {
	n := len(data)
	k := n >> 1
	for i := 0; i < k; i++ {
		data[i], data[n-i-1] = data[n-i-1], data[i]
	}
}

func binarySearch(val int, data []int) int {
	if data[0] > val {
		return -1
	}
	if data[len(data)-1] < val {
		return len(data)
	}
	l, r := 0, len(data)-1
	for l < r {
		mid := (l + r + 1) >> 1
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

func initVeci(size int) Veci {
	return Veci{make([]int, size), size, 0}
}

func (v *Veci) resize() {
	ns := int(float32(v.size) * 1.2)
	v.data = append(v.data, make([]int, ns-v.size)...)
	v.size = ns
}

func (v *Veci) add(val int) {
	if v.n >= v.size {
		v.resize()
	}
	v.data[v.n] = val
	v.n++
}

func (v *Veci) free() {
	v.data = nil
}

type Vecll struct {
	data []int64
	size int
	n    int
}

func initVecll(size int) Vecll {
	return Vecll{make([]int64, size), size, 0}
}

func (v *Vecll) resize() {
	ns := int(float32(v.size) * 1.2)
	v.data = append(v.data, make([]int64, ns-v.size)...)
	v.size = ns
}

func (v *Vecll) add(val int64) {
	if v.n >= v.size {
		v.resize()
	}
	v.data[v.n] = val
	v.n++
}

func (v *Vecll) free() {
	v.data = nil
}

type Vecs struct {
	data []string
	size int
	n    int
}

func initVecs(size int) Vecs {
	return Vecs{make([]string, size), size, 0}
}

func (v *Vecs) resize() {
	ns := int(float32(v.size) * 1.2)
	v.data = append(v.data, make([]string, ns-v.size)...)
	v.size = ns
}

func (v *Vecs) add(val string) {
	if v.n >= v.size {
		v.resize()
	}
	v.data[v.n] = val
	v.n++
}

func (v *Vecs) free() {
	v.data = nil
}

func isPalindromeInt(a, b []int, n int) int {
	for i := 0; i < n; i++ {
		if a[i] != b[n-i-1] {
			return 0
		}
	}
	return 1
}

func isPalindromeString(a, b []string, n int) int {
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

func quickSortPairi(d []Pairi, l, r int) {
	if l >= r {
		return
	}
	pivot := d[l+(r-l)/2]
	i, j := l, r
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
	quickSortPairi(d, l, j)
	quickSortPairi(d, i, r)
}

func expmod(x, n, m int64) int64 {
	ans := int64(1)
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * x) % m
		}
		x = (x * x) % m
		n >>= 1
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
	// Uncomment the following line to enable local testing
	// in = bufio.NewReader(os.Stdin)
	// out = bufio.NewWriter(os.Stdout)

	a := readInt()
	b := readInt()
	if a < b {
		for i := 0; i < b; i++ {
			writeInt(a)
			writeLn()
		}
	} else {
		for i := 0; i < a; i++ {
			writeInt(b)
			writeLn()
		}
	}
	out.Flush()
}

