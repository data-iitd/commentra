<<<<<<< HEAD

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, x, min, m, i int
	fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d %d %d", &n, &x, &min)
	x -= min
	for i = 1; i < n; i++ {
		fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d", &m)
=======
package main

import "fmt"

func main() {
	var n, x, min, m, i int
	fmt.Scanf("%d %d %d", &n, &x, &min)
	x -= min
	for i = 1; i < n; i++ {
		fmt.Scanf("%d", &m)
>>>>>>> 98c87cb78a (data updated)
		x -= m
		if min > m {
			min = m
		}
	}
	fmt.Printf("%d\n", n+x/min)
}

