
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	hcell, _ := strconv.Atoi(readLine(r))
	wcell, _ := strconv.Atoi(readLine(r))
	hpaint, _ := strconv.Atoi(readLine(r))
	wpaint, _ := strconv.Atoi(readLine(r))
	nblack := (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint)
	nwhite := (hcell*wcell) - nblack
	fmt.Println(nwhite)
}

func readLine(r *bufio.Reader) string {
	str, _, err := r.ReadLine()
	if err == nil {
		return string(str)
	} else {
		panic(err)
	}
}

