package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(nextInt(sc))]++
	}
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}
	fmt.Println(int(answer))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if x&(1<<k) != 0 {
			answer++
		}
	}
	return answer
}

func nextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextFloat(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, _ := strconv.ParseFloat(sc.Text(), 64)
	return f
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
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

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func print2DArray(arr [][]int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			fmt.Print(arr[i][j], " ")
		}
		fmt.Println()
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(nextInt(sc))]++
	}
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}
	fmt.Println(int(answer))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if x&(1<<k) != 0 {
			answer++
		}
	}
	return answer
}

func nextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextFloat(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, _ := strconv.ParseFloat(sc.Text(), 64)
	return f
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
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

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func print2DArray(arr [][]int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			fmt.Print(arr[i][j], " ")
		}
		fmt.Println()
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(nextInt(sc))]++
	}
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}
	fmt.Println(int(answer))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if x&(1<<k) != 0 {
			answer++
		}
	}
	return answer
}

func nextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextFloat(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, _ := strconv.ParseFloat(sc.Text(), 64)
	return f
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
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

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func print2DArray(arr [][]int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			fmt.Print(arr[i][j], " ")
		}
		fmt.Println()
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(nextInt(sc))]++
	}
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}
	fmt.Println(int(answer))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if x&(1<<k) != 0 {
			answer++
		}
	}
	return answer
}

func nextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextFloat(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, _ := strconv.ParseFloat(sc.Text(), 64)
	return f
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
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

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func print2DArray(arr [][]int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			fmt.Print(arr[i][j], " ")
		}
		fmt.Println()
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(nextInt(sc))]++
	}
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}
	fmt.Println(int(answer))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if x&(1<<k) != 0 {
			answer++
		}
	}
	return answer
}

func nextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextFloat(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, _ := strconv.ParseFloat(sc.Text(), 64)
	return f
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
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

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func print2DArray(arr [][]int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			fmt.Print(arr[i][j], " ")
		}
		fmt.Println()
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(nextInt(sc))]++
	}
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}
	fmt.Println(int(answer))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if x&(1<<k) != 0 {
			answer++
		}
	}
	return answer
}

func nextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextFloat(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, _ := strconv.ParseFloat(sc.Text(), 64)
	return f
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
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

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func print2DArray(arr [][]int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			fmt.Print(arr[i][j], " ")
		}
		fmt.Println()
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(nextInt(sc))]++
	}
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}
	fmt.Println(int(answer))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if x&(1<<k) != 0 {
			answer++
		}
	}
	return answer
}

func nextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextFloat(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, _ := strconv.ParseFloat(sc.Text(), 64)
	return f
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
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

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println()
}

func print2DArray(arr [][]int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			fmt.Print(arr[i][j], " ")
		}
		fmt.Println()
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(nextInt(sc))]++
	}
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}
	fmt.Println(int(answer))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()