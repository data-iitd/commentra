
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the size of the array")
	size, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the elements of the array")
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadString('\n'))
	}
	fmt.Println("Enter the number of queries")
	queries, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the queries")
	for i := 0; i < queries; i++ {
		query := strings.Split(reader.ReadString('\n'), " ")
		if query[0] == "1" {
			fmt.Println("Enter the index of the element to be updated")
			index, _ := strconv.Atoi(query[1])
			fmt.Println("Enter the new value of the element")
			value, _ := strconv.Atoi(query[2])
			arr[index-1] = value
		} else {
			fmt.Println("Enter the index of the element to be searched")
			index, _ := strconv.Atoi(query[1])
			fmt.Println("Enter the value to be searched")
			value, _ := strconv.Atoi(query[2])
			if arr[index-1] == value {
				fmt.Println("Found")
			} else {
				fmt.Println("Not found")
			}
		}
	}
}

