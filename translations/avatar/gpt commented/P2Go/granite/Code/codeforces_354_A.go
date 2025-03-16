
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input values: n (number of elements), L (left multiplier), R (right multiplier), QL (left penalty), QR (right penalty)
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	L, _ := strconv.Atoi(readLine(reader))
	R, _ := strconv.Atoi(readLine(reader))
	QL, _ := strconv.Atoi(readLine(reader))
	QR, _ := strconv.Atoi(readLine(reader))

	// Read the list of weights W
	W := readNInt64s(reader, n)

	// Initialize a list to store cumulative sums, starting with 0 for the base case
	sumEl := make([]int64, n+1)

	// Calculate cumulative sums of the weights
	for i := 1; i <= n; i++ {
		sumEl[i] = W[i-1] + sumEl[i-1]
	}

	// Calculate the initial answer based on the total weight and the right multiplier
	answer := QR * (int64(n) - 1) + sumEl[n] * int64(R)

	// Iterate through each element to find the minimum energy configuration
	for i := 1; i <= n; i++ {
		// Calculate the energy for the current configuration
		energy := L * sumEl[i] + R * (sumEl[n] - sumEl[i])

		// Adjust energy based on the position of the current element relative to the midpoint
		if i > (n - i) {
			// If the current index is in the right half, apply left penalty
			energy += (int64(i) - (int64(n) - int64(i)) - 1) * int64(QL)
		} else if (n - i) > i {
			// If the current index is in the left half, apply right penalty
			energy += ((int64(n) - int64(i)) - int64(i) - 1) * int64(QR)
		}

		// Update the answer if the current energy is less than the previously recorded answer
		if energy < answer {
			answer = energy
		}
	}

	// Print the minimum energy found
	fmt.Println(answer)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
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

func readInt64(bytes []byte, from int, val *int64) int {
	i := from
	var tmp int64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int64(bytes[i]-'0')
		i++
	}
	*val = tmp
	return i
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readInt64(s, pos, &res[i])
	}

	return res
}

func readUint64s(reader *bufio.Reader, n int) []uint64 {
	res := make([]uint64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readUint64(s, pos, &res[i])
	}

	return res
}

func main1() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNInt64s(reader, n)
		res := solve(n, A)
		fmt.Println(res)
	}
}

func solve(n int, A []int64) int64 {
	// Your solution code here
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func sum(a []int) int {
	res := 0
	for i := 0; i < len(a); i++ {
		res += a[i]
	}
	return res
}

func sumN(a []int, n int) int {
	res := 0
	for i := 0; i < n; i++ {
		res += a[i]
	}
	return res
}

func reverse(arr []int) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func reverseRange(arr []int, l, r int) {
	for i := l; i < (l+r)/2; i++ {
		arr[i], arr[r-i+l] = arr[r-i+l], arr[i]
	}
}

func reverseString(arr []byte) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func reverseStringRange(arr []byte, l, r int) {
	for i := l; i < (l+r)/2; i++ {
		arr[i], arr[r-i+l] = arr[r-i+l], arr[i]
	}
}

func canPartition(nums []int) bool {
	// Your solution code here
}

func minSubArrayLen(s int, nums []int) int {
	// Your solution code here
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays1(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays2(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays3(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays4(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays5(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays6(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays7(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays8(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays9(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays10(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays11(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays12(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays13(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays14(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays15(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays16(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays17(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays18(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays19(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays20(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays21(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays22(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays23(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays24(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays25(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays26(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays27(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays28(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays29(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays30(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays31(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays32(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays33(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays34(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays35(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays36(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays37(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays38(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays39(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays40(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays41(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays42(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays43(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays44(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays45(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays46(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays47(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays48(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays49(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays50(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays51(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays52(nums1 []int, nums2 []int) float64 {
	// Your solution code here
}

func findMedianSortedArrays53(nums1 []int, nums2 []int) float64 {
	// Your solut