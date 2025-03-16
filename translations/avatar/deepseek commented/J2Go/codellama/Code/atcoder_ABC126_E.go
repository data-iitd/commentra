
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	utf := NewUnionFindTree(n)
	m := nextInt(sc)
	for i := 0; i < m; i++ {
		x := nextInt(sc) - 1
		y := nextInt(sc) - 1
		z := nextInt(sc)
		utf.Unite(x, y)
	}
	cnt := 0
	for i := 0; i < n; i++ {
		if utf.par[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

type UnionFindTree struct {
	n    int
	par  []int
	rank []int
}

func NewUnionFindTree(n int) *UnionFindTree {
	utf := &UnionFindTree{n: n, par: make([]int, n), rank: make([]int, n)}
	for i := 0; i < n; i++ {
		utf.par[i] = i
		utf.rank[i] = 0
	}
	return utf
}

func (utf *UnionFindTree) Find(x int) int {
	if utf.par[x] == x {
		return x
	} else {
		return utf.par[x] = utf.Find(utf.par[x])
	}
}

func (utf *UnionFindTree) Unite(x, y int) {
	x = utf.Find(x)
	y = utf.Find(y)
	if x == y {
		return
	}
	if utf.rank[x] < utf.rank[y] {
		utf.par[x] = y
	} else {
		utf.par[y] = x
		if utf.rank[x] == utf.rank[y] {
			utf.rank[x]++
		}
	}
}

func (utf *UnionFindTree) Same(x, y int) bool {
	return utf.Find(x) == utf.Find(y)
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextIntLine(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextStringLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextIntArray(sc *bufio.Scanner) []int {
	sc.Scan()
	ns := strings.Split(sc.Text(), " ")
	nsInt := make([]int, 0, len(ns))
	for _, s := range ns {
		n, _ := strconv.Atoi(s)
		nsInt = append(nsInt, n)
	}
	return nsInt
}

func nextStringArray(sc *bufio.Scanner) []string {
	sc.Scan()
	return strings.Split(sc.Text(), " ")
}

func nextIntMatrix(sc *bufio.Scanner, row int, col int) [][]int {
	sc.Scan()
	ns := strings.Split(sc.Text(), " ")
	nsInt := make([][]int, 0, row)
	for i := 0; i < row; i++ {
		nsInt = append(nsInt, make([]int, col))
		for j := 0; j < col; j++ {
			nsInt[i][j], _ = strconv.Atoi(ns[i*col+j])
		}
	}
	return nsInt
}

func nextStringMatrix(sc *bufio.Scanner, row int, col int) [][]string {
	sc.Scan()
	ns := strings.Split(sc.Text(), " ")
	nsStr := make([][]string, 0, row)
	for i := 0; i < row; i++ {
		nsStr = append(nsStr, make([]string, col))
		for j := 0; j < col; j++ {
			nsStr[i][j] = ns[i*col+j]
		}
	}
	return nsStr
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func memset(a []int, v int) {
	for i := 0; i < len(a); i++ {
		a[i] = v
	}
}

func memset32(a []int32, v int32) {
	for i := 0; i < len(a); i++ {
		a[i] = v
	}
}

func memset64(a []int64, v int64) {
	for i := 0; i < len(a); i++ {
		a[i] = v
	}
}

func memsetByte(a []byte, v byte) {
	for i := 0; i < len(a); i++ {
		a[i] = v
	}
}

func memsetFloat32(a []float32, v float32) {
	for i := 0; i < len(a); i++ {
		a[i] = v
	}
}

func memsetFloat64(a []float64, v float64) {
	for i := 0; i < len(a); i++ {
		a[i] = v
	}
}

func memsetBool(a []bool, v bool) {
	for i := 0; i < len(a); i++ {
		a[i] = v
	}
}

func memsetRune(a []rune, v rune) {
	for i := 0; i < len(a); i++ {
		a[i] = v
	}
}

func maxInt(a ...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt(a ...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxInt64(a ...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt64(a ...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxFloat64(a ...float64) float64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minFloat64(a ...float64) float64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxInt32(a ...int32) int32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt32(a ...int32) int32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxInt16(a ...int16) int16 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt16(a ...int16) int16 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxInt8(a ...int8) int8 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt8(a ...int8) int8 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxUint64(a ...uint64) uint64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minUint64(a ...uint64) uint64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxUint32(a ...uint32) uint32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minUint32(a ...uint32) uint32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxUint16(a ...uint16) uint16 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minUint16(a ...uint16) uint16 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxUint8(a ...uint8) uint8 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minUint8(a ...uint8) uint8 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxFloat32(a ...float32) float32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minFloat32(a ...float32) float32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxRune(a ...rune) rune {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minRune(a ...rune) rune {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxByte(a ...byte) byte {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minByte(a ...byte) byte {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxComplex64(a ...complex64) complex64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if cmplx.Abs(a[i]) > cmplx.Abs(res) {
			res = a[i]
		}
	}
	return res
}

func minComplex64(a ...complex64) complex64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if cmplx.Abs(a[i]) < cmplx.Abs(res) {
			res = a[i]
		}
	}
	return res
}

func maxComplex128(a ...complex128) complex128 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if cmplx.Abs(a[i]) > cmplx.Abs(res) {
			res = a[i]
		}
	}
	return res
}

func minComplex128(a ...complex128) complex128 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if cmplx.Abs(a[i]) < cmplx.Abs(res) {
			res = a[i]
		}
	}
	return res
}

func maxTime(a ...time.Time) time.Time {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i].After(res) {
			res = a[i]
		}
	}
	return res
}

func minTime(a ...time.Time) time.Time {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i].Before(res) {
			res = a[i]
		}
	}
	return res
}

func maxDuration(a ...time.Duration) time.Duration {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minDuration(a ...time.Duration) time.Duration {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxError(a ...error) error {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] != nil {
			res = a[i]
		}
	}
	return res
}

func minError(a ...error) error {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] != nil && a[i] != res {
			res = a[i]
		}
	}
	return res
}

func maxBool(a ...bool) bool {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] {
			res = a[i]
		}
	}
	return res
}

func minBool(a ...bool) bool {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if !a[i] && a[i] != res {
			res = a[i]
		}
	}
	return res
}

func maxString(a ...string) string {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minString(a ...string) string {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxBytes(a ...[]byte) []byte {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if bytes.Compare(a[i], res) == 1 {
			res = a[i]
		}
	}
	return res
}

func minBytes(a ...[]byte) []byte {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if bytes.Compare(a[i], res) == -1 {
			res = a[i]
		}
	}
	return res
}

func maxRuneSlice(a ...[]rune) []rune {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if len(a[i]) > len(res) {
			res = a[i]
		}
	}
	return res
}

func minRuneSlice(a ...[]rune) []rune {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if len(a[i]) < len(res) {
			res = a[i]
		}
	}
	return res
}

func maxFloat32Slice(a ...[]float32) []float32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if len(a[i]) > len(res) {
			res = a[i]
		}
	}
	return res
}

func minFloat32Slice(a ...[]float32) []float32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if len(a[i]) < len(res) {
			res = a[i]
		}
	}
	return res
}

func maxFloat64Slice(a ...[]float64) []float64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if len(a[i]) > len(res) {
			res = a[i]
		}
	}
	return res
}

func minFloat64Slice(a ..