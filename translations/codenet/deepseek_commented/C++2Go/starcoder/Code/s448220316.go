<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Include headers for input/output operations.

func read() int {
	var (
		i   int
		err error
		b   byte
	)
	for {
		b, err = os.Stdin.ReadByte()
		if err!= nil {
			panic(err)
		}
		if b >= '0' && b <= '9' {
			break
		}
	}
	i = int(b - '0')
	for {
		b, err = os.Stdin.ReadByte()
		if err!= nil {
			panic(err)
		}
		if b < '0' || b > '9' {
			break
		}
		i = i*10 + int(b-'0')
	}
	return i
	// Return the integer value, considering its sign.
}

// Read function to efficiently read integers.

func write(x int) {
	if x < 0 {
<<<<<<< HEAD
		fmt.Printf("-")
		x = -x
=======
		x = -x
		fmt.Print("-")
>>>>>>> 98c87cb78a (data updated)
	}
	// Handle negative numbers by converting them to positive.
	if x >= 10 {
		write(x / 10)
	}
	// Recursively write the digits of the number.
<<<<<<< HEAD
	fmt.Printf("%d", x%10)
=======
	fmt.Print(x % 10)
>>>>>>> 98c87cb78a (data updated)
	// Write the last digit.
}

// Write function to efficiently write integers.

func writeln(x int) {
	write(x)
<<<<<<< HEAD
	fmt.Printf("\n")
=======
	fmt.Println("")
>>>>>>> 98c87cb78a (data updated)
	// Write the integer and then print a newline.
}

// Writeln function to write integers and print a newline.

func main() {
	var (
		n, m, l, r, vi int
<<<<<<< HEAD
		fa              [100005]int
		v               [200005]int
=======
>>>>>>> 98c87cb78a (data updated)
	)
	n = read()
	m = read()
	// Read the number of nodes and operations.
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	// Initialize the union-find structure with each node as its own parent.
	for i := 1; i <= m; i++ {
		l = read()
		r = read()
		vi = read()
		// Read the left node, right node, and value increment for each operation.
		li := get(l)
		ri := get(r)
		// Find the roots of l and r.
		if li!= ri {
			v[ri] = vi - v[r] + v[l]
			// Update the value of ri based on the values of l and r.
			fa[ri] = li
			// Set the parent of ri to li.
		} else {
			if v[r]-v[l]!= vi {
<<<<<<< HEAD
				fmt.Printf("No\n")
=======
				fmt.Println("No")
>>>>>>> 98c87cb78a (data updated)
				return
				// If the values are inconsistent, print "No" and exit.
			}
		}
	}
<<<<<<< HEAD
	fmt.Printf("Yes\n")
=======
	fmt.Println("Yes")
>>>>>>> 98c87cb78a (data updated)
	// If all operations are consistent, print "Yes".
}

// Main function to execute the union-find structure and value updates.

