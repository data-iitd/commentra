

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	y, _ := strconv.Atoi(readLine(reader))  // Read an integer input for variable y
	arr := readLine(reader)                // Read a string input for variable arr
	arrSplit := strings.Split(arr, " ")   // Split the string input into a slice of strings
	arrInt := make([]int, len(arrSplit)) // Create an empty slice of integers to store the integers from arrSplit

	for i := 0; i < len(arrSplit); i++ {
		arrInt[i], _ = strconv.Atoi(arrSplit[i]) // Convert each string in arrSplit to an integer and store it in arrInt
	}

	for i := 0; i < len(arrInt); i++ {
		for j := 0; j < len(arrInt); j++ {
			if i == j {
				continue // Skip if i and j are the same index
			}
			for k := 0; k < len(arrInt); k++ {
				if arrInt[k]!= arrInt[j] && arrInt[k]!= arrInt[i] && arrInt[k] == arrInt[i]+arrInt[j] {
					// Check if arrInt[k] is the sum of arrInt[i] and arrInt[j] and different from both
					fmt.Printf("%d %d %d\n", k+1, j+1, i+1) // Print the positions of arrInt[k], arrInt[j], and arrInt[i] (1-indexed)
					os.Exit(0)                              // Exit the program
				}
			}
		}
	}
	fmt.Println(-1) // Print -1 if no such element is found
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}
