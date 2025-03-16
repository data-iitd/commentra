<<<<<<< HEAD

import (
	"fmt"
	"os"
	"strconv"
)
=======
package main

import "fmt"
>>>>>>> 98c87cb78a (data updated)

// Array to represent the segments of the digits 0-9
var seg = [][]bool{
	[]bool{0, 1, 1, 1, 1, 1, 1}, // 0
	[]bool{0, 0, 0, 0, 1, 1, 0}, // 1
	[]bool{1, 0, 1, 1, 0, 1, 1}, // 2
	[]bool{1, 0, 0, 1, 1, 1, 1}, // 3
	[]bool{1, 1, 0, 0, 1, 1, 0}, // 4
	[]bool{1, 1, 0, 1, 1, 0, 1}, // 5
	[]bool{1, 1, 1, 1, 1, 0, 1}, // 6
	[]bool{0, 1, 0, 0, 1, 1, 1}, // 7
	[]bool{1, 1, 1, 1, 1, 1, 1}, // 8
	[]bool{1, 1, 0, 1, 1, 1, 1}, // 9
}

func main() {
	var n, t int
	var st [7]bool
	for {
<<<<<<< HEAD
		if _, err := fmt.Scanf("%d", &n); err!= nil {
			break
		}
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &t)
=======
		if fmt.Fscanf(os.Stdin, "%d", &n) == EOF {
			break
		}
		for i := 0; i < n; i++ {
			fmt.Fscanf(os.Stdin, "%d", &t)
>>>>>>> 98c87cb78a (data updated)
			ans := make([]byte, 8)
			for j := 0; j < 7; j++ {
				ans[j] = byte(st[j] ^ seg[t][j])
				st[j] = seg[t][j]
			}
			fmt.Println(string(ans))
		}
	}
}

