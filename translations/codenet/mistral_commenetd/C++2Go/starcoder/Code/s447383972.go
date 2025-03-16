
// Including necessary header files
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"fmt"
	"os"
	"sort"
)

// Macros for iteration
const N = 200010

// Function prototypes and necessary definitions
func read() (a int) {
	fmt.Fscanf(os.Stdin, "%d", &a)
	return
}

func write(a int) {
	fmt.Fprintln(os.Stdout, a)
}

func writeln(a int) {
	fmt.Fprintln(os.Stdout, a)
}

func main() {

	// Reading input
	var n int
	n = read()

	// Reading array 'a'
	var a [N]int
	for i := 1; i <= n; i++ {
		a[i] = read()
	}

	// Sorting array 'a' in ascending order
	sort.Ints(a[:n+1])

	// Finding duplicate elements and storing them in 'q'
	var q [N]int
	var tot int
	for i := 1; i <= n; i++ {
		if a[i] == a[i+1] {
			q[tot] = a[i]
			tot++
			i++
		}
	}

	// Outputting the result
	write(q[tot]*q[tot-1])

	// End of main function
}

