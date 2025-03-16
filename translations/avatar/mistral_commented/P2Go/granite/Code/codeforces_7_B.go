
###
# Code
###

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input number of tests and memory size
	t, m := readTwoInt()

	// Initialize an array to represent the memory allocation status
	alocuente := make([]int, m)

	// Loop through each test case
	for i := 0; i < t; i++ {
		// Read the operation type and arguments
		op := readLine()
		args := strings.Split(op, " ")

		// Allocate memory if the operation type is 'alloc'
		if args[0] == "alloc" {
			pos := 0 // Initialize position counter
			for j := 0; j < m; j++ {
				// Check if the position is available for allocation
				if alocuente[j] == 0 {
					// If the position is available, allocate the memory block of the given size
					pos++
					if pos == int64(args[1]) {
						// Set the allocated memory blocks to the given index
						for k := j - int64(args[1])+1; k <= j; k++ {
							alocuente[k] = ind
						}
						// Print the allocated index
						fmt.Println(ind)
						// Increment the index for the next allocation
						ind++
						// Break the loop since we found the suitable position
						break
					} else {
						pos = 0 // Reset the position counter for the next iteration
					}
				}
			}
			if pos == 0 {
				// If no suitable position is found, print 'NULL'
				fmt.Println("NULL")
			}
		}

		// Erase memory if the operation type is 'erase'
		if args[0] == "erase" {
			pos := 0 // Initialize position counter
			// Check if the given index is valid and allocated
			if int64(args[1]) <= 0 || int64(args[1]) > int64(m) || alocuente[int64(args[1])-1] == 0 {
				// If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				// If the index is valid and allocated, free the memory block
				for j := 0; j < m; j++ {
					if int64(args[1]) > 0 && alocuente[j] == int64(args[1]) {
						// Set the memory block to 0 to indicate it is freed
						alocuente[j] = 0
					}
				}
			}
		}

		// Defragment memory if the operation type is 'defragment'
		if args[0] == "defragment" {
			cnt := 0 // Initialize free block counter
			// Count the number of free blocks
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					cnt++
				}
			}
			// Create a new list with only allocated blocks
			alocuente2 := make([]int, 0)
			for j := 0; j < m; j++ {
				if alocuente[j]!= 0 {
					alocuente2 = append(alocuente2, alocuente[j])
				}
			}
			// Add free blocks at the end of the list
			for j := 0; j < cnt; j++ {
				alocuente2 = append(alocuente2, 0)
			}
			// Copy the new list back to the original array
			copy(alocuente, alocuente2)
		}
	}
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func readTwoInt() (int, int) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	x := strings.Split(sc.Text(), " ")
	num1, _ := strconv.Atoi(x[0])
	num2, _ := strconv.Atoi(x[1])
	return num1, num2
}

func readThreeInt() (int, int, int) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	x := strings.Split(sc.Text(), " ")
	num1, _ := strconv.Atoi(x[0])
	num2, _ := strconv.Atoi(x[1])
	num3, _ := strconv.Atoi(x[2])
	return num1, num2, num3
}

func readLine() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	return sc.Text()
}

func printArray(X []int) {
	for _, v := range X {
		fmt.Print(v, " ")
	}
	fmt.Println()
}

func main1() {
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)

	t := readInt()
	m := readInt()

	alocuente := make([]int, m)

	for i := 0; i < t; i++ {
		op := readLine()
		args := strings.Split(op, " ")

		if args[0] == "alloc" {
			pos := 0
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					pos++
					if pos == int64(args[1]) {
						for k := j - int64(args[1])+1; k <= j; k++ {
							alocuente[k] = ind
						}
						fmt.Println(ind)
						ind++
						break
					} else {
						pos = 0
					}
				}
			}
			if pos == 0 {
				fmt.Println("NULL")
			}
		}

		if args[0] == "erase" {
			pos := 0
			if int64(args[1]) <= 0 || int64(args[1]) > int64(m) || alocuente[int64(args[1])-1] == 0 {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				for j := 0; j < m; j++ {
					if int64(args[1]) > 0 && alocuente[j] == int64(args[1]) {
						alocuente[j] = 0
					}
				}
			}
		}

		if args[0] == "defragment" {
			cnt := 0
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					cnt++
				}
			}
			alocuente2 := make([]int, 0)
			for j := 0; j < m; j++ {
				if alocuente[j]!= 0 {
					alocuente2 = append(alocuente2, alocuente[j])
				}
			}
			for j := 0; j < cnt; j++ {
				alocuente2 = append(alocuente2, 0)
			}
			copy(alocuente, alocuente2)
		}
	}
}