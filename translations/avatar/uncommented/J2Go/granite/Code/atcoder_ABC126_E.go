
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

type UnionFindTree struct {
	n   int
	par []int
	rank []int
}

func NewUnionFindTree(n int) *UnionFindTree {
	utf := new(UnionFindTree)
	utf.n = n
	utf.par = make([]int, n)
	utf.rank = make([]int, n)
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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func max(x, y int) int {
	if x < y {
		return y
	} else {
		return x
	}
}

func abs(x int) int {
	return x * (-1)
}

func pow(x, n int) int {
	ret := 1
	for i := 0; i < n; i++ {
		ret *= x
	}
	return ret
}

func mod(x, m int) int {
	if x < 0 {
		return m - (-x) % m
	}
	return x % m
}

func max3(a, b, c int) int {
	return max(max(a, b), c)
}

func min3(a, b, c int) int {
	return min(min(a, b), c)
}

func sort(a []int) []int {
	sort.Ints(a)
	return a
}

func reverse(a []int) []int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func reverse2d(a [][]int) [][]int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	for i := range a {
		a[i] = reverse(a[i])
	}
	return a
}

func inArray(a int, A []int) bool {
	for _, v := range A {
		if v == a {
			return true
		}
	}
	return false
}

func printArray(a []int) {
	fmt.Printf("[")
	for i, v := range a {
		if i > 0 {
			fmt.Printf(", ")
		}
		fmt.Printf("%v", v)
	}
	fmt.Printf("]\n")
}

func printMatrix(a [][]int) {
	for _, v := range a {
		printArray(v)
	}
}

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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func max(x, y int) int {
	if x < y {
		return y
	} else {
		return x
	}
}

func abs(x int) int {
	return x * (-1)
}

func pow(x, n int) int {
	ret := 1
	for i := 0; i < n; i++ {
		ret *= x
	}
	return ret
}

func mod(x, m int) int {
	if x < 0 {
		return m - (-x) % m
	}
	return x % m
}

func max3(a, b, c int) int {
	return max(max(a, b), c)
}

func min3(a, b, c int) int {
	return min(min(a, b), c)
}

func sort(a []int) []int {
	sort.Ints(a)
	return a
}

func reverse(a []int) []int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func reverse2d(a [][]int) [][]int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	for i := range a {
		a[i] = reverse(a[i])
	}
	return a
}

func inArray(a int, A []int) bool {
	for _, v := range A {
		if v == a {
			return true
		}
	}
	return false
}

func printArray(a []int) {
	fmt.Printf("[")
	for i, v := range a {
		if i > 0 {
			fmt.Printf(", ")
		}
		fmt.Printf("%v", v)
	}
	fmt.Printf("]\n")
}

func printMatrix(a [][]int) {
	for _, v := range a {
		printArray(v)
	}
}

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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func max(x, y int) int {
	if x < y {
		return y
	} else {
		return x
	}
}

func abs(x int) int {
	return x * (-1)
}

func pow(x, n int) int {
	ret := 1
	for i := 0; i < n; i++ {
		ret *= x
	}
	return ret
}

func mod(x, m int) int {
	if x < 0 {
		return m - (-x) % m
	}
	return x % m
}

func max3(a, b, c int) int {
	return max(max(a, b), c)
}

func min3(a, b, c int) int {
	return min(min(a, b), c)
}

func sort(a []int) []int {
	sort.Ints(a)
	return a
}

func reverse(a []int) []int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func reverse2d(a [][]int) [][]int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	for i := range a {
		a[i] = reverse(a[i])
	}
	return a
}

func inArray(a int, A []int) bool {
	for _, v := range A {
		if v == a {
			return true
		}
	}
	return false
}

func printArray(a []int) {
	fmt.Printf("[")
	for i, v := range a {
		if i > 0 {
			fmt.Printf(", ")
		}
		fmt.Printf("%v", v)
	}
	fmt.Printf("]\n")
}

func printMatrix(a [][]int) {
	for _, v := range a {
		printArray(v)
	}
}

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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func max(x, y int) int {
	if x < y {
		return y
	} else {
		return x
	}
}

func abs(x int) int {
	return x * (-1)
}

func pow(x, n int) int {
	ret := 1
	for i := 0; i < n; i++ {
		ret *= x
	}
	return ret
}

func mod(x, m int) int {
	if x < 0 {
		return m - (-x) % m
	}
	return x % m
}

func max3(a, b, c int) int {
	return max(max(a, b), c)
}

func min3(a, b, c int) int {
	return min(min(a, b), c)
}

func sort(a []int) []int {
	sort.Ints(a)
	return a
}

func reverse(a []int) []int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func reverse2d(a [][]int) [][]int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	for i := range a {
		a[i] = reverse(a[i])
	}
	return a
}

func inArray(a int, A []int) bool {
	for _, v := range A {
		if v == a {
			return true
		}
	}
	return false
}

func printArray(a []int) {
	fmt.Printf("[")
	for i, v := range a {
		if i > 0 {
			fmt.Printf(", ")
		}
		fmt.Printf("%v", v)
	}
	fmt.Printf("]\n")
}

func printMatrix(a [][]int) {
	for _, v := range a {
		printArray(v)
	}
}

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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func max(x, y int) int {
	if x < y {
		return y
	} else {
		return x
	}
}

func abs(x int) int {
	return x * (-1)
}

func pow(x, n int) int {
	ret := 1
	for i := 0; i < n; i++ {
		ret *= x
	}
	return ret
}

func mod(x, m int) int {
	if x < 0 {
		return m - (-x) % m
	}
	return x % m
}

func max3(a, b, c int) int {
	return max(max(a, b), c)
}

func min3(a, b, c int) int {
	return min(min(a, b), c)
}

func sort(a []int) []int {
	sort.Ints(a)
	return a
}

func reverse(a []int) []int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	return a
}

func reverse2d(a [][]int) [][]int {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
	for i := range a {
		a[i] = reverse(a[i])
	}
	return a
}

func inArray(a int, A []int) bool {
	for _, v := range A {
		if v == a {
			return true
		}
	}
	return false
}

func printArray(a []int) {
	fmt.Printf("[")
	for i, v := range a {
		if i > 0 {
			fmt.Printf(", ")
		}
		fmt.Printf("%v", v)
	}
	fmt.Printf("]\n")
}

func printMatrix(a [][]int) {
	for _, v := range a {
		printArray(v)
	}
}

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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func abs(x int) int {
	return x * (-1)
}

func pow(x, n int) int {
	ret := 1
	for i := 0; i < n; i++ {
		ret *= x
	}
	return ret
}

func mod(x, m int) int {
	if x < 0 {
		return m - (-x) % m
	}
	return x % m
}

func max3(a, b, c int) int {
	return max(max(a, b), c )
}

func min3(a, b, c int) int {
	return min(min(a, b ), c )
}

func sort(a []int) []int {
	sort.Ints(a)
	return a
}

func reverse(a []int) []int {
	for i := 0; i < len(a)/2; i++ {
		a[i], a[len(a)-1-i ] = a[len(a)-1-i ]
	}
	return a
}
