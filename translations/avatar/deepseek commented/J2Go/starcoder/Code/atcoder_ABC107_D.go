
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the size of the array")
	n, _ := reader.ReadString('\n')
	n = n[:len(n)-1]
	arr := make([]int, 0)
	for i := 0; i < len(n); i++ {
		arr = append(arr, int(n[i])-48)
	}
	fmt.Println("Enter the array elements")
	for i := 0; i < len(arr); i++ {
		fmt.Println("Enter the element", i+1)
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		arr[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the target value")
	target, _ := reader.ReadString('\n')
	target = target[:len(target)-1]
	fmt.Println("Enter the total number of elements")
	total, _ := reader.ReadString('\n')
	total = total[:len(total)-1]
	total = int(total)
	fmt.Println("Enter the number of elements less than or equal to the target value")
	cnt, _ := reader.ReadString('\n')
	cnt = cnt[:len(cnt)-1]
	cnt = int(cnt)
	fmt.Println("Enter the median value")
	median, _ := reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ := reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ := reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit := make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted := make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the sorted array")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		sorted = append(sorted, int(n[0])-48)
	}
	fmt.Println("Enter the median value")
	median, _ = reader.ReadString('\n')
	median = median[:len(median)-1]
	median = int(median)
	fmt.Println("Enter the search range")
	l, _ = reader.ReadString('\n')
	l = l[:len(l)-1]
	l = int(l)
	r, _ = reader.ReadString('\n')
	r = r[:len(r)-1]
	r = int(r)
	fmt.Println("Enter the binary indexed tree")
	bit = make([]int, 2*len(arr)+2)
	for i := 0; i < len(bit); i++ {
		fmt.Println("Enter the value of the", i+1, "element of the binary indexed tree")
		n, _ := reader.ReadString('\n')
		n = n[:len(n)-1]
		bit[i] = int(n[0]) - 48
	}
	fmt.Println("Enter the sorted array")
	sorted = make([]int, 0)
	for i := 0; i < len(sorted); i++