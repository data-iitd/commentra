
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
	fmt.Println("Enter the size of the grid")
	size, _ := strconv.Atoi(reader.ReadString())
	fmt.Println("Enter the grid")
	grid := make([]string, size)
	for i := 0; i < size; i++ {
		grid[i] = reader.ReadString()
	}
	fmt.Println("Enter the number of columns")
	col, _ := strconv.Atoi(reader.ReadString())
	fmt.Println("Enter the number of rows")
	row, _ := strconv.Atoi(reader.ReadString())
	var fine int
	for i := 0; i < col; i++ {
		var counter int
		for j := 0; j < size; j++ {
			if grid[j][i] == 'C' {
				counter++
			}
		}
		fine += counter * (counter - 1) / 2
	}
	for i := 0; i < row; i++ {
		var counter int
		for j := 0; j < size; j++ {
			if grid[i][j] == 'C' {
				counter++
			}
		}
		fine += counter * (counter - 1) / 2
	}
	fmt.Println(fine)
}

