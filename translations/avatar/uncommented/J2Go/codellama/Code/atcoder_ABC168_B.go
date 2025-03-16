
package main

import "fmt"
import "os"

func main() {
	var K int
	var S string
	fmt.Scan(&K)
	fmt.Scan(&S)
	if len(S) <= K {
		fmt.Println(S)
	} else {
		fmt.Println(S[0:K] + "...")
	}
}

