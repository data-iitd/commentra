<<<<<<< HEAD

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		i, j, k, L, tmp, d, def, end, aj, max, min int
		an, a1, a2 [20]int
	)

	for {
		an[0], L = readInt()
		if L == 0 {
			break
		}
		aj = an[0]
		end = 0
		for k = 1; k < 20; k++ {
			aj /= 10
			for i = L - 1; i >= 0; i-- {
				a1[i] = aj % 10
				a2[i] = aj % 10
			}
			for i = 1; i < L; i++ {
				for j = 1; j < L; j++ {
					if a1[j-1] < a1[j] {
						a1[j-1], a1[j] = a1[j], a1[j-1]
					}
					if a2[j-1] > a2[j] {
						a2[j-1], a2[j] = a2[j], a2[j-1]
					}
				}
			}
=======
package main

import "fmt"

func main() {
	// Declare variables
	var i, j, k, L, tmp, d, def, end, aj, max, min int

	// Infinite loop to read input
	for {
		var an [20]int
		var a1 [6]int
		var a2 [6]int
		fmt.Scanf("%d %d", &an[0], &L)
		if L == 0 {
			break
		} // Exit the loop if the input length is zero

		aj = an[0]
		end = 0

		// Iterate through each number in the input array
		for k = 1; k < 20; k++ {
			// Iterate through each digit in the number from right to left
			for i = L - 1; i >= 0; i-- {
				a1[i] = aj % 10
				a2[i] = aj % 10
				aj /= 10
			}
			// Sort the digits in both arrays in ascending order
			for i = 1; i < L; i++ {
				for j = 1; j < L; j++ {
					if a1[j-1] < a1[j] { // Swap adjacent digits if they are in the wrong order
						tmp = a1[j-1]
						a1[j-1] = a1[j]
						a1[j] = tmp
					}
					if a2[j-1] > a2[j] { // Swap adjacent digits if they are in the wrong order
						tmp = a2[j-1]
						a2[j-1] = a2[j]
						a2[j] = tmp
					}
				}
			}
			// Calculate the difference between the two numbers
>>>>>>> 98c87cb78a (data updated)
			d = 1
			max = 0
			min = 0
			for i = L - 1; i >= 0; i-- {
				max += a1[i] * d
				min += a2[i] * d
				d *= 10
			}
<<<<<<< HEAD
			def = max - min
			for i = 0; i < k; i++ {
				if def == an[i] {
=======
			def = max - min // Store the difference in a variable

			// Check if the difference has already been encountered in the array 'an'
			for i = 0; i < k; i++ {
				if def == an[i] { // If a match is found, print the result and exit the loop
>>>>>>> 98c87cb78a (data updated)
					fmt.Printf("%d %d %d\n", i, def, k-i)
					end = 1
					break
				}
			}
			if end == 1 {
				break
<<<<<<< HEAD
			}
			an[k] = def
			aj = def
=======
			} // Exit the loop if a match is found
			an[k] = def
			aj = def // Update the array and the variable for the next iteration
>>>>>>> 98c87cb78a (data updated)
		}
	}
}

<<<<<<< HEAD
func readInt() (int, int) {
	var (
		a, b int
		err  error
	)
	a, err = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
	if err!= nil {
		panic(err)
	}
	b, err = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
	if err!= nil {
		panic(err)
	}
	return a, b
}

=======
>>>>>>> 98c87cb78a (data updated)
