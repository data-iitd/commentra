
package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
func main ( ) {
    reader := bufio.NewReader ( os.Stdin )
    N, M := readTwoInt64s ( reader )
    edge := make ( [] [] int64, N )
    for i := 0; i < M; i++ {
        X, Y, Z := readThreeInt64s ( reader )
        edge [ X - 1 ] = append ( edge [ X - 1 ], Y - 1 )
        edge [ Y - 1 ] = append ( edge [ Y - 1 ], X - 1 )
    }
    used := make ( [] bool, N )
    ans := 0
    for i := 0; i < N; i++ {
        if! used [ i ] {
            ans ++
            queue := make ( [] int64, 0 )
            queue = append ( queue, i )
            for len ( queue ) > 0 {
                node := queue [ 0 ]
                queue = queue [ 1 : ]
                if! used [ node ] {
                    used [ node ] = true
                    for _, nextnode := range edge [ node ] {
                        if! used [ nextnode ] {
                            queue = append ( queue, nextnode )
                        }
                    }
                }
            }
        }
    }
    fmt.Println ( ans )
}
func readInt ( bytes [] byte, from int, val * int ) int {
    i := from
    sign := 1
    if bytes [ i ] == '-' {
        i ++
        sign = - 1
    }
    for i < len ( bytes ) && bytes [ i ] >= '0' && bytes [ i ] <= '9' {
        * val = * val * 10 + int ( bytes [ i ] - '0' )
        i ++
    }
    * val *= sign
    return i
}
func readInt64 ( bytes [] byte, from int, val * int64 ) int {
    i := from
    var sign int64 = 1
    if bytes [ i ] == '-' {
        i ++
        sign = - 1
    }
    for i < len ( bytes ) && bytes [ i ] >= '0' && bytes [ i ] <= '9' {
        * val = * val * 10 + int64 ( bytes [ i ] - '0' )
        i ++
    }
    * val *= sign
    return i
}
func readTwoInt64s ( reader * bufio.Reader ) ( int64, int64 ) {
    res := make ( [] int64, 2 )
    x := 0
    bytes, _ := reader.ReadBytes ('' )
    x = readInt64 ( bytes, 0, & res [ 0 ] )
    x = readInt64 ( bytes, x + 1, & res [ 1 ] )
    return res [ 0 ], res [ 1 ]
}
func readThreeInt64s ( reader * bufio.Reader ) ( int64, int64, int64 ) {
    res := make ( [] int64, 3 )
    x := 0
    bytes, _ := reader.ReadBytes ('' )
    x = readInt64 ( bytes, 0, & res [ 0 ] )
    x = readInt64 ( bytes, x + 1, & res [ 1 ] )
    x = readInt64 ( bytes, x + 1, & res [ 2 ] )
    return res [ 0 ], res [ 1 ], res [ 2 ]
}
func readString ( reader * bufio.Reader ) string {
    s, _ := reader.ReadString ( '\n' )
    for i := 0; i < len ( s ); i++ {
        if s [ i ] == '\n' || s [ i ] =='' {
            return s [ : i ]
        }
    }
    return s
}
func readNum ( reader * bufio.Reader ) ( a int ) {
    bs, _ := reader.ReadBytes ( '\n' )
    x := 0
    for i := 0; i < len ( bs ); i++ {
        if bs [ i ] >= '0' && bs [ i ] <= '9' {
            x = x * 10 + int ( bs [ i ] - '0' )
        } else if bs [ i ] == - 1 {
            return
        }
    }
    return x
}
func readTwoNums ( reader * bufio.Reader ) ( a int, b int ) {
    res := readNNums ( reader, 2 )
    a, b = res [ 0 ], res [ 1 ]
    return
}
func readThreeNums ( reader * bufio.Reader ) ( a int, b int, c int ) {
    res := readNNums ( reader, 3 )
    a, b, c = res [ 0 ], res [ 1 ], res [ 2 ]
    return
}
func readNNums ( reader * bufio.Reader, n int ) [] int {
    res := make ( [] int, n )
    x := 0
    bs, _ := reader.ReadBytes ( '\n' )
    for i := 0; i < n; i++ {
        for x < len ( bs ) && ( bs [ x ] < '0' || bs [ x ] > '9' ) && bs [ x ]!= '-' {
            x ++
        }
        x = readInt ( bs, x, & res [ i ] )
    }
    return res
}
func readUint64 ( bytes [] byte, from int, val * uint64 ) int {
    i := from
    var sign uint64 = 1
    if bytes [ i ] == '-' {
        i ++
        sign = uint64 ( - 1 )
    }
    for i < len ( bytes ) && bytes [ i ] >= '0' && bytes [ i ] <= '9' {
        * val = * val * 10 + uint64 ( bytes [ i ] - '0' )
        i ++
    }
    * val *= sign
    return i
}
func main1 ( ) {
    reader := bufio.NewReader ( os.Stdin )
    N, M := readTwoInt64s ( reader )
    edge := make ( [] [] int64, N )
    for i := 0; i < M; i++ {
        X, Y, Z := readThreeInt64s ( reader )
        edge [ X - 1 ] = append ( edge [ X - 1 ], Y - 1 )
        edge [ Y - 1 ] = append ( edge [ Y - 1 ], X - 1 )
    }
    used := make ( [] bool, N )
    ans := 0
    for i := 0; i < N; i++ {
        if! used [ i ] {
            ans ++
            queue := make ( [] int64, 0 )
            queue = append ( queue, i )
            for len ( queue ) > 0 {
                node := queue [ 0 ]
                queue = queue [ 1 : ]
                if! used [ node ] {
                    used [ node ] = true
                    for _, nextnode := range edge [ node ] {
                        if! used [ nextnode ] {
                            queue = append ( queue, nextnode )
                        }
                    }
                }
            }
        }
    }
    fmt.Println ( ans )
}
