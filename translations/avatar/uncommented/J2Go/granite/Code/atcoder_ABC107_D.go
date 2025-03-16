
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
		A := readNNums(reader, n)
		res := solve(A)
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

func solve(A []int) int {
	n := len(A)
	B := make([]int, n)
	copy(B, A)
	sort.Ints(B)

	var total int64

	for i := 0; i < n; i++ {
		total += int64(i+1)
	}

	var left, right int

	for left < right {
		mid := left + (right-left)/2
		if check(A, B, mid, total) {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return B[left]
}

func check(A, B []int, mid int, total int64) bool {
	n := len(A)

	var sum int

	bit := NewBIT(2 * n)

	for i := 0; i < n; i++ {
		sum += int(A[i] <= B[mid])
		bit.Update(sum, 1)
	}

	var res int64

	for i := 0; i <= n; i++ {
		res += int64(bit.Query(i+n))
	}

	return res >= total/2+1
}

type BIT struct {
	arr []int
}

func NewBIT(n int) *BIT {
	arr := make([]int, n+1)
	return &BIT{arr}
}

func (bit *BIT) Update(num int, val int) {
	num += 1
	for num <= len(bit.arr) {
		bit.arr[num] += val
		num += num & -num
	}
}

func (bit *BIT) Query(num int) int {
	res := 0
	for num > 0 {
		res += bit.arr[num]
		num -= num & -num
	}
	return res
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)
	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(A)
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

func solve(A []int) int {
	n := len(A)
	B := make([]int, n)
	copy(B, A)
	sort.Ints(B)

	var total int64

	for i := 0; i < n; i++ {
		total += int64(i+1)
	}

	var left, right int

	for left < right {
		mid := left + (right-left)/2
		if check(A, B, mid, total) {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return B[left]
}

func check(A, B []int, mid int, total int64) bool {
	n := len(A)

	var sum int

	bit := NewBIT(2 * n)

	for i := 0; i < n; i++ {
		sum += int(A[i] <= B[mid])
		bit.Update(sum, 1)
	}

	var res int64

	for i := 0; i <= n; i++ {
		res += int64(bit.Query(i+n))
	}

	return res >= total/2+1
}

type BIT struct {
	arr []int
}

func NewBIT(n int) *BIT {
	arr := make([]int, n+1)
	return &BIT{arr}
}

func (bit *BIT) Update(num int, val int) {
	num += 1
	for num <= len(bit.arr) {
		bit.arr[num] += val
		num += num & -num
	}
}

func (bit *BIT) Query(num int) int {
	res := 0
	for num > 0 {
		res += bit.arr[num]
		num -= num & -num
	}
	return res
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)
	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(A)
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

func solve(A []int) int {
	n := len(A)
	B := make([]int, n)
	copy(B, A)
	sort.Ints(B)

	var total int64

	for i := 0; i < n; i++ {
		total += int64(i+1)
	}

	var left, right int

	for left < right {
		mid := left + (right-left)/2
		if check(A, B, mid, total) {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return B[left]
}

func check(A, B []int, mid int, total int64) bool {
	n := len(A)

	var sum int

	bit := NewBIT(2 * n)

	for i := 0; i < n; i++ {
		sum += int(A[i] <= B[mid])
		bit.Update(sum, 1)
	}

	var res int64

	for i := 0; i <= n; i++ {
		res += int64(bit.Query(i+n))
	}

	return res >= total/2+1
}

type BIT struct {
	arr []int
}

func NewBIT(n int) *BIT {
	arr := make([]int, n+1)
	return &BIT{arr}
}

func (bit *BIT) Update(num int, val int) {
	num += 1
	for num <= len(bit.arr) {
		bit.arr[num] += val
		num += num & -num
	}
}

func (bit *BIT) Query(num int) int {
	res := 0
	for num > 0 {
		res += bit.arr[num]
		num -= num & -num
	}
	return res
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)
	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(A)
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

func solve(A []int) int {
	n := len(A)
	B := make([]int, n)
	copy(B, A)
	sort.Ints(B)

	var total int64

	for i := 0; i < n; i++ {
		total += int64(i+1)
	}

	var left, right int

	for left < right {
		mid := left + (right-left)/2
		if check(A, B, mid, total) {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return B[left]
}

func check(A, B []int, mid int, total int64) bool {
	n := len(A)

	var sum int

	bit := NewBIT(2 * n)

	for i := 0; i < n; i++ {
		sum += int(A[i] <= B[mid])
		bit.Update(sum, 1)
	}

	var res int64

	for i := 0; i <= n; i++ {
		res += int64(bit.Query(i+n))
	}

	return res >= total/2+1
}

type BIT struct {
	arr []int
}

func NewBIT(n int) *BIT {
	arr := make([]int, n+1)
	return &BIT{arr}
}

func (bit *BIT) Update(num int, val int) {
	num += 1
	for num <= len(bit.arr) {
		bit.arr[num] += val
		num += num & -num
	}
}

func (bit *BIT) Query(num int) int {
	res := 0
	for num > 0 {
		res += bit.arr[num]
		num -= num & -num
	}
	return res
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)
	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(A)
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
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' ) {
		tmp = tmp * sign
		i++
	}
	*val = tmp
	return i
}

func readNum(reader *bufio.Re