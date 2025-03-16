
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader ( os.Stdin )
	w = bufio.NewWriter ( os.Stdout )
)

func main ( ) {
	var t int
	fmt.Fscanf ( r, "%d\n", & t )
	for ; t > 0 ; t -- {
		var n int
		fmt.Fscanf ( r, "%d\n", & n )
		s := ( 1 + n ) * n / 2
		t := 1
		for ; t <= n ; t *= 2 {
			s -= 2 * t
		}
		fmt.Fprintf ( w, "%d\n", s )
	}
	w.Flush ( )
}

