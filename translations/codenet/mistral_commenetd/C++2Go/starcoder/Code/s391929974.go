<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var sq [10000]int
	var fr [5000]int
	var com []int
	var tmp int
	var i, j int
	var f bool

<<<<<<< HEAD
	// Start of the infinite loop
	for {
		// Read the number of elements in the array from the user
		fmt.Scanf("%d", &n)
=======
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		n, _ = strconv.Atoi(strings.TrimSpace(line))
>>>>>>> 98c87cb78a (data updated)
		if n == 0 {
			break
		}

		// Initialize square array
		for i = 1; i < n; i++ {
			sq[i] = (i * i) % n
		}
		com = com[:0] // Clear the vector before filling it with new unique squares

		// Find unique squares and store them in the vector
		for i = 1; i < n; i++ {
			f = true
			for j = 0; j < len(com); j++ {
				if com[j] == sq[i] {
					f = false
					break
				}
			}
			if f {
				com = append(com, sq[i])
			}
		}

		// Initialize frequency array
		for i = 0; i <= (n-1)/2; i++ {
			fr[i] = 0
		}

		// Find the frequency of each difference between unique squares
		for i = 0; i < len(com); i++ {
			for j = 0; j < len(com); j++ {
				if i!= j {
					tmp = com[i] - com[j]
					if tmp < 0 {
						tmp += n
					}
					if tmp > (n-1)/2 {
						tmp = n - tmp
					}
					fr[tmp]++
				}
			}
		}

		// Print the frequency of each difference
		for i = 1; i <= (n-1)/2; i++ {
			fmt.Println(fr[i])
		}
	}
}

