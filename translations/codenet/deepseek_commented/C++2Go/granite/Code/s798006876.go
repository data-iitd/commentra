
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAX_N = 1000 // Define the maximum size of the array
var data [MAX_N]int // Declare the array to store the data

func main() {
	reader := bufio.NewReader(os.Stdin)
	var m, nmi, nma int
	for {
		fmt.Fscanf(reader, "%d %d %d\n", &m, &nmi, &nma) // Read the values of m, nmi, and nma, and break if nmi is 0
		if nmi == 0 {
			break
		}
		for i := 0; i < m; i++ {
			fmt.Fscanf(reader, "%d", &data[i]) // Read m integers into the array data
		}
		ma := 0 // Initialize the maximum difference to 0
		ans := 0 // Initialize the answer index to 0
		for i := nmi - 1; i < nma; i++ { // Loop through the range from nmi-1 to nma-1
			if ma <= data[i]-data[i+1] { // Check if the current difference is greater than the maximum difference found so far
				ans = i + 1 // Update the answer index
				ma = data[i] - data[i+1] // Update the maximum difference
			}
		}
		fmt.Println(ans) // Print the answer index
	}
}

