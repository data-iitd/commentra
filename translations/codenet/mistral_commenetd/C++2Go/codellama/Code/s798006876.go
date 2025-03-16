
package main

import "fmt"

const MAX_N = 1000 // maximum size of the array

func main() {
	var m, nmi, nma int // m: number of elements in the array, nmi and nma: indices of the subarray to find the maximum difference in
	for {
		fmt.Scan(&m, &nmi, &nma) // read input until EOF or nmi is 0
		if nmi == 0 {
			break
		}
		var data [MAX_N]int // array to store input data
		for i := 0; i < m; i++ {
			fmt.Scan(&data[i]) // read input data into the array
		}
		var ma int = 0 // initialize maximum difference to 0
		var ans int = 0 // initialize answer to 0
		for i := nmi - 1; i < nma; i++ { // iterate through the subarray
			if ma <= data[i]-data[i+1] { // if current difference is greater than the previous maximum difference
				ans = i + 1 // update answer with the index of the current element
				ma = data[i] - data[i+1] // update maximum difference with the current difference
			}
		}
		fmt.Println(ans) // print the answer
	}
}

