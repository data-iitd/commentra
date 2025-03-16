
package main

import "fmt"
import "bufio"
import "os"

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, k int
	fmt.Fscanf(reader, "%d\n", &n)
	fmt.Fscanf(reader, "%d\n", &k)

	x := n / k
	y := n % k
	var z int
	if y!= 0 {
		z = x + 1 - x
	} else {
		z = x - x
	}
	fmt.Println(z)
}

