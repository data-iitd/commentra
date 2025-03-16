<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
<<<<<<< HEAD
	var (
		n   int
		t   []string
		h   []string
		taro, hanako int
	)
	fmt.Scanf("%d", &n)
	t = make([]string, n)
	h = make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s", &t[i])
		fmt.Scanf("%s", &h[i])
		if strings.Compare(t[i], h[i]) < 0 {
			hanako += 3
		}
		if strings.Compare(t[i], h[i]) > 0 {
			taro += 3
		}
		if strings.Compare(t[i], h[i]) == 0 {
			taro += 1
			hanako += 1
		}
	}
	fmt.Printf("%d %d\n", taro, hanako)
=======
	var n int
	fmt.Scanf("%d", &n)
	t := make([]string, n)
	h := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s", &t[i])
		fmt.Scanf("%s", &h[i])
		if t[i] < h[i] {
			fmt.Println(3)
		} else if t[i] > h[i] {
			fmt.Println(0)
		} else {
			fmt.Println(1)
		}
	}
>>>>>>> 98c87cb78a (data updated)
}

