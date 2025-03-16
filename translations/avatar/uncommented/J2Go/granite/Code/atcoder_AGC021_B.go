
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)
	var N int
	scan.Scan()
	N, _ =...