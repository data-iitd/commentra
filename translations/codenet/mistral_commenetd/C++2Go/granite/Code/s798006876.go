

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MAX_N = 1e3 // maximum size of the array

func main() {
	reader := bufio.NewReader(os.Stdin)
	var m, nmi, nma int
	for {
		m, _ = strconv.Atoi(readLine(reader))
		if m == 0 {
			break
		}
		nmi, _ = strconv.Atoi(readLine(reader))
		nma, _ = strconv.Atoi(readLine(reader))
		data := make([]int, m)
		for i := 0; i < m; i++ {
			data[i], _ = strconv.Atoi(readLine(reader))
		}
		ma := 0 // initialize maximum difference to 0
		ans := 0 // initialize answer to 0
		for i := nmi - 1; i < nma; i++ { // iterate through the subarray
			if ma <= data[i]-data[i+1] { // if current difference is greater than the previous maximum difference
				ans = i + 1 // update answer with the index of the current element
				ma = data[i] - data[i+1] // update maximum difference with the current difference
			}
		}
		fmt.Println(ans) // print the answer
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

