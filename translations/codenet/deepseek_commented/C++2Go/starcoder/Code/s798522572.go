<<<<<<< HEAD

import (
	"fmt"
	"sort"
)

func main() {
	var N, T int
	fmt.Scanf("%d %d", &N, &T)
	A := make([]int, N)
	B := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}
	m := A[0]
	B[1] = A[1] - m
	m = min(m, A[1])
=======
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements and a threshold value")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, "\r", "", -1)
	input_array := strings.Split(input, " ")
	N, _ := strconv.Atoi(input_array[0])
	T, _ := strconv.Atoi(input_array[1])
	fmt.Println("Enter the elements")
	A := make([]int, N)
	for i := 0; i < N; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		input = strings.Replace(input, "\n", "", -1)
		input = strings.Replace(input, "\r", "", -1)
		A[i], _ = strconv.Atoi(input)
	}
	B := make([]int, N)
	B[0] = A[1] - A[0]
	m := A[0]
>>>>>>> 98c87cb78a (data updated)
	for i := 2; i < N; i++ {
		B[i] = A[i] - m
		m = min(m, A[i])
	}
<<<<<<< HEAD
	max_value := B[0]
	for i := 1; i < N; i++ {
		if B[i] > max_value {
			max_value = B[i]
		}
	}
=======
	max_value := max(B)
>>>>>>> 98c87cb78a (data updated)
	fmt.Println(count(B, max_value))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

<<<<<<< HEAD
func count(A []int, max_value int) int {
	var count int
	for i := 0; i < len(A); i++ {
		if A[i] == max_value {
=======
func max(a []int) int {
	max_value := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > max_value {
			max_value = a[i]
		}
	}
	return max_value
}

func count(a []int, max_value int) int {
	count := 0
	for i := 0; i < len(a); i++ {
		if a[i] == max_value {
>>>>>>> 98c87cb78a (data updated)
			count++
		}
	}
	return count
}

