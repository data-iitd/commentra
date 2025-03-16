
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
	var k, t int64
	fmt.Fscanf ( r, "%d", & k )
	t = 0
	for i := int64 ( 1 ) ; i <= k ; i ++ {
		t = ( t % k ) * 10 + 7
		if t % k == 0 {
			fmt.Fprintln ( w, i )
			break
		}
	}
	if i > k {
		fmt.Fprintln ( w, - 1 )
	}
	w.Flush ( )
}

