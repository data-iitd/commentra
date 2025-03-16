
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	sort.Ints(a)
	found := false
	for i := 0; i < n-2; i++ {
		if a[i] == a[i+1]-1 && a[i+1] == a[i+2]-1 {
			found = true
		}
	}
	fmt.Println(strings.ToUpper(strconv.FormatBool(found)))
}

