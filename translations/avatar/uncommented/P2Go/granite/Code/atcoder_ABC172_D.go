
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
	var N int
	fmt.Fscanf ( r, "%d\n", & N )
	var ans int
	for i := 1 ; i <= N ; i ++ {
		ans += i * ( N / i ) * ( N / i + 1 ) / 2
	}
	fmt.Fprintf ( w, "%d\n", ans )
	w.Flush ( )
}

