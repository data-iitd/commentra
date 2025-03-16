
package main

import (
	"bufio"
	"fmt"
	"os"
)

func check(lis []int, k, mid int) bool {
	// This function checks if it's possible to distribute the elements of lis
	// such that each element is at most mid and the total number of operations
	// does not exceed k.
	for _, i := range lis {
		if i%mid == 0 { // If i is divisible by mid, increment k by 1.
			k += 1
		}
		k -= i / mid // Subtract the number of elements that can be handled by mid from k.
	}
	return k >= 0 // Return true if k is non-negative, else false.
}

func main() {
	// Read the number of elements (n) and the initial value of k from input.
	reader := bufio.NewReader(os.Stdin)
	n, k := readTwoNums(reader)

	// Read the list of integers from input.
	lis := readNNums(reader, n)

	// Initialize the search range with 1 and the maximum value in the list.
	a, b := 1, max(lis...)

	// Initialize the answer with the maximum value in the list.
	ans := b

	// Perform a binary search to find the maximum value of mid that satisfies the condition.
	for a <= b {
		mid := (a + b) / 2 // Calculate the middle value of the current search range.
		if check(lis, k, mid) { // Check if the current mid value is valid.
			ans = mid // Update the answer to the current mid value.
			b = mid - 1 // Adjust the upper bound of the search range.
		} else {
			a = mid + 1 // Adjust the lower bound of the search range.
		}
	}

	// Print the result, which is the maximum value of mid that satisfies the condition.
	fmt.Println(ans)
}

func readInt(bytes []byte, from int, val *int) int {
	// Read an integer from the given bytes array.
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
	// Read a single integer from the input reader.
	bytes, _ := reader.ReadBytes('\n')
	readInt(bytes, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	// Read two integers from the input reader.
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	// Read three integers from the input reader.
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	// Read n integers from the input reader.
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
	// Read a uint64 from the given bytes array.
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func max(a...int) int {
	// Find the maximum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min(a...int) int {
	// Find the minimum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func solve(n int, k int, A []int) int {
	// Solve the problem by finding the maximum value of mid that satisfies the condition.
	a, b := 1, max(A...)

	for a < b {
		mid := (a + b) / 2
		if check(n, k, A, mid) {
			b = mid
		} else {
			a = mid + 1
		}
	}

	return a
}

func check(n int, k int, A []int, mid int) bool {
	// Check if it's possible to distribute the elements of A such that each element is at most mid and the total number of operations does not exceed k.
	for _, num := range A {
		if num%mid == 0 {
			k--
		} else {
			k -= num / mid
		}
		if k < 0 {
			return false
		}
	}
	return true
}

func max(a...int) int {
	// Find the maximum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min(a...int) int {
	// Find the minimum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func readInt(bytes []byte, from int, val *int) int {
	// Read an integer from the given bytes array.
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
	// Read a single integer from the input reader.
	bytes, _ := reader.ReadBytes('\n')
	readInt(bytes, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	// Read two integers from the input reader.
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	// Read three integers from the input reader.
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	// Read n integers from the input reader.
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
	// Read a uint64 from the given bytes array.
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func max(a...int) int {
	// Find the maximum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min(a...int) int {
	// Find the minimum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func solve(n int, k int, A []int) int {
	// Solve the problem by finding the maximum value of mid that satisfies the condition.
	a, b := 1, max(A...)

	for a < b {
		mid := (a + b) / 2
		if check(n, k, A, mid) {
			b = mid
		} else {
			a = mid + 1
		}
	}

	return a
}

func check(n int, k int, A []int, mid int) bool {
	// Check if it's possible to distribute the elements of A such that each element is at most mid and the total number of operations does not exceed k.
	for _, num := range A {
		if num%mid == 0 {
			k--
		} else {
			k -= num / mid
		}
		if k < 0 {
			return false
		}
	}
	return true
}

func max(a...int) int {
	// Find the maximum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min(a...int) int {
	// Find the minimum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func readInt(bytes []byte, from int, val *int) int {
	// Read an integer from the given bytes array.
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
	// Read a single integer from the input reader.
	bytes, _ := reader.ReadBytes('\n')
	readInt(bytes, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	// Read two integers from the input reader.
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	// Read three integers from the input reader.
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	// Read n integers from the input reader.
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
	// Read a uint64 from the given bytes array.
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func max(a...int) int {
	// Find the maximum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min(a...int) int {
	// Find the minimum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func solve(n int, k int, A []int) int {
	// Solve the problem by finding the maximum value of mid that satisfies the condition.
	a, b := 1, max(A...)

	for a < b {
		mid := (a + b) / 2
		if check(n, k, A, mid) {
			b = mid
		} else {
			a = mid + 1
		}
	}

	return a
}

func check(n int, k int, A []int, mid int) bool {
	// Check if it's possible to distribute the elements of A such that each element is at most mid and the total number of operations does not exceed k.
	for _, num := range A {
		if num%mid == 0 {
			k--
		} else {
			k -= num / mid
		}
		if k < 0 {
			return false
		}
	}
	return true
}

func max(a...int) int {
	// Find the maximum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min(a...int) int {
	// Find the minimum value in the given list of integers.
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func readInt(bytes []byte, from int, val *int) int {
	// Read an integer from the given bytes array.
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

func r