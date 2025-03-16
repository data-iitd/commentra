package main

import (
	"fmt"
)

const MAX_N = 1000 // maximum size of the array

func main() {
	var m, nmi, nma int // m: number of elements in the array, nmi and nma: indices of the subarray to find the maximum difference in
	data := make([]int, MAX_N) // array to store input data

	for {
		_, err := fmt.Scan(&m, &nmi, &nma) // read input
		if err != nil || nmi == 0 { // check for EOF or nmi is 0
			break
		}

		for i := 0; i < m; i++ {
			fmt.Scan(&data[i]) // read input data into the array
		}

		ma := 0 // initialize maximum difference to 0
		ans := 0 // initialize answer to 0

		for i := nmi - 1; i < nma-1; i++ { // iterate through the subarray
			if ma <= data[i]-data[i+1] { // if current difference is greater than the previous maximum difference
				ans = i + 1 // update answer with the index of the current element
				ma = data[i] - data[i+1] // update maximum difference with the current difference
			}
		}
		fmt.Println(ans) // print the answer
	}
}

// <END-OF-CODE>
