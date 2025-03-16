<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Define a structure QUEUE to store the values of a, b, c, and the total number of operations.
type QUEUE struct {
	a, b, c, tot int
}

// Define a transformation matrix F with six possible transformations.
var F = [][]int{{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}}

// Define a hash table as an array of vectors to store unique states.
var Hash [7007] []int

// Function to check if a state has been visited before.
func HASH(n int) bool {
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Main function to execute the program.
func main() {
	var Push QUEUE
	var que []QUEUE
	fmt.Scanf("%d%d%d", &Push.a, &Push.b, &Push.c)
	que = append(que, Push)
	for len(que) > 0 {
		Fro := que[0]
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Printf("%d\n", Fro.tot)
			os.Exit(0)
		}
		for i := 0; i < 6; i++ {
			Push = Fro
			Push.tot++
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]
			n := Push.a*10000 + Push.b*100 + Push.c
			if!HASH(n) {
				continue
			}
			que = append(que, Push)
		}
		que = que[1:]
	}
}

