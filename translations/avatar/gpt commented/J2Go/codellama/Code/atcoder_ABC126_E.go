package main

import (
	"fmt"
	"os"
	"strconv"
)

// Scanner object to read input from the console
type Scanner struct {
	in  *os.File
	out *os.File
}

// Constant for modulo operation
const MOD = 1000000007

// Method to execute the main logic
func (sc *Scanner) doIt() {
	// Read the number of elements (nodes)
	n, _ := strconv.Atoi(sc.next())
	// Initialize Union-Find data structure with n elements
	utf := newUnionFindTree(n)
	// Read the number of connections (edges)
	m, _ := strconv.Atoi(sc.next())

	// Process each connection
	for i := 0; i < m; i++ {
		// Read the two nodes to unite and the weight (not used in this implementation)
		x, _ := strconv.Atoi(sc.next())
		y, _ := strconv.Atoi(sc.next())
		z, _ := strconv.Atoi(sc.next())
		// Unite the two nodes
		utf.unite(x-1, y-1)
	}

	// Count the number of unique connected components
	cnt := 0
	for i := 0; i < n; i++ {
		// Check if the current node is a root of a component
		if utf.par[i] == i {
			cnt++
		}
	}

	// Output the count of unique connected components
	fmt.Println(cnt)
}

// Inner class implementing Union-Find (Disjoint Set Union)
type unionFindTree struct {
	n    int
	par  []int
	rank []int
}

// Constructor to initialize the Union-Find structure
func newUnionFindTree(n int) *unionFindTree {
	utf := new(unionFindTree)
	utf.n = n
	utf.par = make([]int, n)
	utf.rank = make([]int, n)
	// Initialize each element to be its own parent and rank to 0
	for i := 0; i < n; i++ {
		utf.par[i] = i
		utf.rank[i] = 0
	}
	return utf
}

// Find the root of the set containing x with path compression
func (utf *unionFindTree) find(x int) int {
	if utf.par[x] == x {
		return x
	} else {
		return utf.par[x] = utf.find(utf.par[x])
	}
}

// Unite the sets containing x and y
func (utf *unionFindTree) unite(x, y int) {
	x = utf.find(x)
	y = utf.find(y)
	// If they are already in the same set, do nothing
	if x == y {
		return
	}
	// Union by rank
	if utf.rank[x] < utf.rank[y] {
		utf.par[x] = y
	} else {
		utf.par[y] = x
		if utf.rank[x] == utf.rank[y] {
			utf.rank[x]++
		}
	}
}

// Check if x and y are in the same set
func (utf *unionFindTree) same(x, y int) bool {
	return utf.find(x) == utf.find(y)
}

// Main method to start the program
func main() {
	sc := new(Scanner)
	sc.in = os.Stdin
	sc.out = os.Stdout
	sc.doIt()
}

// Read a line of input from stdin and return a string.
func (sc *Scanner) next() string {
	sc.scan()
	return sc.buf.Text()
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextInt() int {
	sc.scan()
	n, _ := strconv.Atoi(sc.buf.Text())
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextInts() []int {
	sc.scan()
	var ints []int
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := strconv.Atoi(string(ch))
			ints = append(ints, n)
		}
	}
	return ints
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextStrings() []string {
	sc.scan()
	return sc.buf.Text()
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextLines() []string {
	sc.scan()
	return sc.buf.Text()
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextBytes() []byte {
	sc.scan()
	return sc.buf.Text()
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextRunes() []rune {
	sc.scan()
	return sc.buf.Text()
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextFloat() float64 {
	sc.scan()
	n, _ := strconv.ParseFloat(sc.buf.Text(), 64)
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextFloats() []float64 {
	sc.scan()
	var floats []float64
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := strconv.ParseFloat(string(ch), 64)
			floats = append(floats, n)
		}
	}
	return floats
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextBool() bool {
	sc.scan()
	n, _ := strconv.ParseBool(sc.buf.Text())
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextBools() []bool {
	sc.scan()
	var bools []bool
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := strconv.ParseBool(string(ch))
			bools = append(bools, n)
		}
	}
	return bools
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextComplex() complex128 {
	sc.scan()
	n, _ := strconv.ParseComplex(sc.buf.Text(), 128)
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextComplexs() []complex128 {
	sc.scan()
	var complexes []complex128
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := strconv.ParseComplex(string(ch), 128)
			complexes = append(complexes, n)
		}
	}
	return complexes
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextDuration() time.Duration {
	sc.scan()
	n, _ := time.ParseDuration(sc.buf.Text())
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextDurations() []time.Duration {
	sc.scan()
	var durations []time.Duration
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := time.ParseDuration(string(ch))
			durations = append(durations, n)
		}
	}
	return durations
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextTime() time.Time {
	sc.scan()
	n, _ := time.Parse(time.RFC3339, sc.buf.Text())
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextTimes() []time.Time {
	sc.scan()
	var times []time.Time
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := time.Parse(time.RFC3339, string(ch))
			times = append(times, n)
		}
	}
	return times
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextIP() net.IP {
	sc.scan()
	n := net.ParseIP(sc.buf.Text())
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextIPs() []net.IP {
	sc.scan()
	var ips []net.IP
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n := net.ParseIP(string(ch))
			ips = append(ips, n)
		}
	}
	return ips
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextIPMask() net.IPMask {
	sc.scan()
	n := net.ParseIP(sc.buf.Text())
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextIPMasks() []net.IPMask {
	sc.scan()
	var ipmasks []net.IPMask
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n := net.ParseIP(string(ch))
			ipmasks = append(ipmasks, n)
		}
	}
	return ipmasks
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextMAC() net.HardwareAddr {
	sc.scan()
	n, _ := net.ParseMAC(sc.buf.Text())
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextMACs() []net.HardwareAddr {
	sc.scan()
	var macs []net.HardwareAddr
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := net.ParseMAC(string(ch))
			macs = append(macs, n)
		}
	}
	return macs
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUint() uint {
	sc.scan()
	n, _ := strconv.ParseUint(sc.buf.Text(), 10, 64)
	return uint(n)
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUints() []uint {
	sc.scan()
	var uints []uint
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := strconv.ParseUint(string(ch), 10, 64)
			uints = append(uints, uint(n))
		}
	}
	return uints
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUint8() uint8 {
	sc.scan()
	n, _ := strconv.ParseUint(sc.buf.Text(), 10, 8)
	return uint8(n)
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUint8s() []uint8 {
	sc.scan()
	var uint8s []uint8
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := strconv.ParseUint(string(ch), 10, 8)
			uint8s = append(uint8s, uint8(n))
		}
	}
	return uint8s
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUint16() uint16 {
	sc.scan()
	n, _ := strconv.ParseUint(sc.buf.Text(), 10, 16)
	return uint16(n)
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUint16s() []uint16 {
	sc.scan()
	var uint16s []uint16
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := strconv.ParseUint(string(ch), 10, 16)
			uint16s = append(uint16s, uint16(n))
		}
	}
	return uint16s
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUint32() uint32 {
	sc.scan()
	n, _ := strconv.ParseUint(sc.buf.Text(), 10, 32)
	return uint32(n)
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUint32s() []uint32 {
	sc.scan()
	var uint32s []uint32
	for _, word := range sc.buf.Text() {
		for _, ch := range string(word) {
			n, _ := strconv.ParseUint(string(ch), 10, 32)
			uint32s = append(uint32s, uint32(n))
		}
	}
	return uint32s
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUint64() uint64 {
	sc.scan()
	n, _ := strconv.ParseUint(sc.buf.Text(), 10, 64)
	return n
}

// Read a line of input from stdin and split it into individual words.
func (sc *Scanner) nextUint64s() []uint64 {
	sc.scan()
	var uint64s []uint64
	for _, word := range sc.buf.Text() {
		for _, ch := range string(wor