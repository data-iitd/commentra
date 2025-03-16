

package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

func main() {
 reader := bufio.NewReader ( os.Stdin )
 writer := bufio.NewWriter ( os.Stdout )
 defer writer.Flush ( )

 n, _ := strconv.Atoi ( strings.TrimSpace ( reader.ReadLine ( ) ) )
 arr := make ( []int, n )
 freq := make ( map [ int ] int )
 max := 0

 for i := 0 ; i < n ; i ++ {
 num, _ := strconv.Atoi ( strings.TrimSpace ( reader.ReadLine ( ) ) )
 arr [ i ] = num
 freq [ num ] ++
 if freq [ num ] > max {
 max = freq [ num ]
 }
 }

 for i := 0 ; i < n ; i ++ {
 if freq [ arr [ i ] ] == max {
 fmt.Fprintln ( writer, arr [ i ] )
 break
 }
 }

 fmt.Fprintln ( writer, "