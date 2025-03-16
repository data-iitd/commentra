package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object for input and a BufferedWriter for output
	sc := bufio.NewScanner(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)
	
	// Read the dimensions of the grid and the parameters A and B
	sc.Scan()
	H := 0
	fmt.Sscan(sc.Text(), &H) // Height of the grid
	sc.Scan()
	W := 0
	fmt.Sscan(sc.Text(), &W) // Width of the grid
	sc.Scan()
	A := 0
	fmt.Sscan(sc.Text(), &A) // Parameter A
	sc.Scan()
	B := 0
	fmt.Sscan(sc.Text(), &B) // Parameter B
	
	// Check if the grid can accommodate the required number of 0s and 1s
	if W < 2 * A || H < 2 * B { 
		fmt.Println(-1) // Print -1 if the grid is too small
		return // Exit the program
	} 
	
	// Generate the grid based on the parameters A and B
	for i := 0; i < H; i++ { // Iterate over each row
		for j := 0; j < W; j++ { // Iterate over each column
			// Determine whether to write '0' or '1' based on the current position
			if (i < B && j < A) || (i >= B && j >= A) {
				bw.WriteString("0") // Write '0' for specified conditions
			} else {
				bw.WriteString("1") // Write '1' otherwise
			}
		} 
		bw.WriteByte('\n') // Move to the next line after finishing a row
	} 
	
	// Flush the BufferedWriter to ensure all data is written out
	bw.Flush()
}
