
package main

import (
    "bufio"
    "container/ring"
    "fmt"
    "math"
    "os"
    "sort"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader ( os.Stdin )
    inf = math.Inf ( 1 )
)

func main ( ) {
    s := readString ( )
    if len ( bytes.Count ( []byte ( s ), []byte ( string ( s [ 0 ] ) ) ) == len ( s ) {
        fmt.Println ( 0 )
        return
    }
    a := make ( map [ byte ] int )
    for _, v := range ( s ) {
        a [ v ] ++
    }
    ans := inf
    for _, v := range ( a ) {
        ans = min ( ans, v [ 1 ] )
    }
    ans *= 2
    fmt.Println ( ans )
}

func read ( ) ( []byte, error ) {
    return in.ReadBytes ('' )
}

func readInt ( bytes []byte ) ( int, error ) {
    return strconv.Atoi ( string ( bytes ) )
}

func readString ( ) string {
    s, _ := read ( )
    return string ( s )
}

func readInt64 ( ) ( int64, error ) {
    return strconv.ParseInt ( readString ( ), 10, 64 )
}

func min ( a, b int ) int {
    if a < b {
        return a
    } else {
        return b
    }
}

func max ( a, b int ) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func pow ( a, b int ) int {
    return int ( math.Pow ( float64 ( a ), float64 ( b ) ) )
}

func abs ( a int ) int {
    return int ( math.Abs ( float64 ( a ) ) )
}

func mod ( a, b int ) int {
    return a - b * ( a / b )
}

func lcm ( a, b int ) int {
    return a * b / gcd ( a, b )
}

func gcd ( a, b int ) int {
    if a < b {
        return gcd ( b, a )
    }
    if b == 0 {
        return a
    } else {
        return gcd ( b, a % b )
    }
}

func isPrime ( a int ) bool {
    if a <= 1 {
        return false
    }
    for i := 2; i * i <= a; i++ {
        if a % i == 0 {
            return false
        }
    }
    return true
}

func extGCD ( a, b int ) ( int, int, int ) {
    if b == 0 {
        return a, 1, 0
    }
    x, y, g := extGCD ( b, a % b )
    return g, y, x - a / b * y
}

func modInv ( a, m int ) int {
    x, _, _ := extGCD ( a, m )
    return x % m
}

func modDiv ( a, b, m int ) int {
    a %= m
    return a * modInv ( b, m ) % m
}

func modPow ( a, b, m int ) int {
    c := 1
    for ; b > 0; b >>= 1 {
        if b & 1 {
            c = modDiv ( c * a, 1, m )
        }
        a = modDiv ( a * a, 1, m )
    }
    return c
}

func bit ( x int ) int {
    return int ( math.Log ( float64 ( x ) ) / math.Log ( 2.0 ) )
}

func bitCount ( x int ) int {
    return bit ( x ) - bit ( x & ( x - 1 ) )
}

func preSum ( a []int ) []int {
    pre := make ( []int, len ( a ) )
    pre [ 0 ] = a [ 0 ]
    for i := 1; i < len ( a ); i++ {
        pre [ i ] = pre [ i - 1 ] + a [ i ]
    }
    return pre
}

func preSum2D ( a [] [] int ) [ ] [ ] int {
    pre := make ( [ ] [ ] int, len ( a ) )
    for i := 0; i < len ( a ); i++ {
        pre [ i ] = make ( [ ] int, len ( a [ i ] ) )
    }
    for i := 0; i < len ( a ); i++ {
        pre [ i ] [ 0 ] = a [ i ] [ 0 ]
        for j := 1; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] = pre [ i ] [ j - 1 ] + a [ i ] [ j ]
        }
    }
    return pre
}

func preSum3D ( a [] [] [ ] int ) [ ] [ ] [ ] int {
    pre := make ( [ ] [ ] [ ] int, len ( a ) )
    for i := 0; i < len ( a ); i++ {
        pre [ i ] = make ( [ ] [ ] int, len ( a [ i ] ) )
        for j := 0; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] = make ( [ ] int, len ( a [ i ] [ j ] ) )
        }
    }
    for i := 0; i < len ( a ); i++ {
        for j := 0; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] [ 0 ] = a [ i ] [ j ] [ 0 ]
            for k := 1; k < len ( a [ i ] [ j ] ); k++ {
                pre [ i ] [ j ] [ k ] = pre [ i ] [ j ] [ k - 1 ] + a [ i ] [ j ] [ k ]
            }
        }
    }
    return pre
}

func preMin ( a []int ) []int {
    pre := make ( []int, len ( a ) )
    pre [ 0 ] = a [ 0 ]
    for i := 1; i < len ( a ); i++ {
        pre [ i ] = min ( pre [ i - 1 ], a [ i ] )
    }
    return pre
}

func preMax ( a []int ) []int {
    pre := make ( []int, len ( a ) )
    pre [ 0 ] = a [ 0 ]
    for i := 1; i < len ( a ); i++ {
        pre [ i ] = max ( pre [ i - 1 ], a [ i ] )
    }
    return pre
}

func preMin2D ( a [] [] int ) [ ] [ ] int {
    pre := make ( [ ] [ ] int, len ( a ) )
    for i := 0; i < len ( a ); i++ {
        pre [ i ] = make ( [ ] int, len ( a [ i ] ) )
    }
    pre [ 0 ] [ 0 ] = a [ 0 ] [ 0 ]
    for i := 1; i < len ( a ); i++ {
        pre [ i ] [ 0 ] = min ( pre [ i - 1 ] [ 0 ], a [ i ] [ 0 ] )
    }
    for j := 1; j < len ( a [ 0 ] ); j++ {
        pre [ 0 ] [ j ] = min ( pre [ 0 ] [ j - 1 ], a [ 0 ] [ j ] )
    }
    for i := 1; i < len ( a ); i++ {
        for j := 1; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] = min ( pre [ i - 1 ] [ j ], pre [ i ] [ j - 1 ] )
        }
    }
    return pre
}

func preMax2D ( a [] [] int ) [ ] [ ] int {
    pre := make ( [ ] [ ] int, len ( a ) )
    for i := 0; i < len ( a ); i++ {
        pre [ i ] = make ( [ ] int, len ( a [ i ] ) )
    }
    pre [ 0 ] [ 0 ] = a [ 0 ] [ 0 ]
    for i := 1; i < len ( a ); i++ {
        pre [ i ] [ 0 ] = max ( pre [ i - 1 ] [ 0 ], a [ i ] [ 0 ] )
    }
    for j := 1; j < len ( a [ 0 ] ); j++ {
        pre [ 0 ] [ j ] = max ( pre [ 0 ] [ j - 1 ], a [ 0 ] [ j ] )
    }
    for i := 1; i < len ( a ); i++ {
        for j := 1; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] = max ( pre [ i - 1 ] [ j ], pre [ i ] [ j - 1 ] )
        }
    }
    return pre
}

func preSum2D ( a [] [] int ) [ ] [ ] int {
    pre := make ( [ ] [ ] int, len ( a ) )
    for i := 0; i < len ( a ); i++ {
        pre [ i ] = make ( [ ] int, len ( a [ i ] ) )
    }
    pre [ 0 ] [ 0 ] = a [ 0 ] [ 0 ]
    for i := 1; i < len ( a ); i++ {
        pre [ i ] [ 0 ] = pre [ i - 1 ] [ 0 ] + a [ i ] [ 0 ]
    }
    for j := 1; j < len ( a [ 0 ] ); j++ {
        pre [ 0 ] [ j ] = pre [ 0 ] [ j - 1 ] + a [ 0 ] [ j ]
    }
    for i := 1; i < len ( a ); i++ {
        for j := 1; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] = pre [ i - 1 ] [ j ] + pre [ i ] [ j - 1 ] - pre [ i - 1 ] [ j - 1 ] + a [ i ] [ j ]
        }
    }
    return pre
}

func preSum3D ( a [] [] [ ] int ) [ ] [ ] [ ] int {
    pre := make ( [ ] [ ] [ ] int, len ( a ) )
    for i := 0; i < len ( a ); i++ {
        pre [ i ] = make ( [ ] [ ] int, len ( a [ i ] ) )
        for j := 0; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] = make ( [ ] int, len ( a [ i ] [ j ] ) )
        }
    }
    pre [ 0 ] [ 0 ] [ 0 ] = a [ 0 ] [ 0 ] [ 0 ]
    for i := 1; i < len ( a ); i++ {
        pre [ i ] [ 0 ] [ 0 ] = pre [ i - 1 ] [ 0 ] [ 0 ] + a [ i ] [ 0 ] [ 0 ]
    }
    for j := 1; j < len ( a [ 0 ] ); j++ {
        pre [ 0 ] [ j ] [ 0 ] = pre [ 0 ] [ j - 1 ] [ 0 ] + a [ 0 ] [ j ] [ 0 ]
    }
    for k := 1; k < len ( a [ 0 ] [ 0 ] ); k++ {
        pre [ 0 ] [ 0 ] [ k ] = pre [ 0 ] [ 0 ] [ k - 1 ] + a [ 0 ] [ 0 ] [ k ]
    }
    for i := 1; i < len ( a ); i++ {
        for j := 1; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] [ 0 ] = pre [ i - 1 ] [ j ] [ 0 ] + pre [ i ] [ j - 1 ] [ 0 ] - pre [ i - 1 ] [ j - 1 ] [ 0 ] + a [ i ] [ j ] [ 0 ]
        }
    }
    for i := 1; i < len ( a ); i++ {
        for j := 1; j < len ( a [ i ] ); j++ {
            for k := 1; k < len ( a [ i ] [ j ] ); k++ {
                pre [ i ] [ j ] [ k ] = pre [ i - 1 ] [ j ] [ k ] + pre [ i ] [ j - 1 ] [ k ] + pre [ i ] [ j ] [ k - 1 ] - pre [ i - 1 ] [ j - 1 ] [ k ] - pre [ i ] [ j - 1 ] [ k - 1 ] - pre [ i - 1 ] [ j ] [ k - 1 ] + pre [ i - 1 ] [ j - 1 ] [ k - 1 ] + a [ i ] [ j ] [ k ]
            }
        }
    }
    return pre
}

func preSum3D2 ( a [] [] [ ] int ) [ ] [ ] [ ] int {
    pre := make ( [ ] [ ] [ ] int, len ( a ) )
    for i := 0; i < len ( a ); i++ {
        pre [ i ] = make ( [ ] [ ] int, len ( a [ i ] ) )
        for j := 0; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] = make ( [ ] int, len ( a [ i ] [ j ] ) )
        }
    }
    for i := 0; i < len ( a ); i++ {
        for j := 0; j < len ( a [ i ] ); j++ {
            for k := 0; k < len ( a [ i ] [ j ] ); k++ {
                pre [ i ] [ j ] [ k ] = a [ i ] [ j ] [ k ] + ( pre [ i - 1 ] [ j ] [ k ] if i > 0 else 0 ) + ( pre [ i ] [ j - 1 ] [ k ] if j > 0 else 0 ) + ( pre [ i ] [ j ] [ k - 1 ] if k > 0 else 0 ) - ( pre [ i - 1 ] [ j - 1 ] [ k ] if i > 0 && j > 0 else 0 ) - ( pre [ i ] [ j - 1 ] [ k - 1 ] if j > 0 && k > 0 else 0 ) - ( pre [ i - 1 ] [ j ] [ k - 1 ] if i > 0 && k > 0 else 0 ) + ( pre [ i - 1 ] [ j - 1 ] [ k - 1 ] if i > 0 && j > 0 && k > 0 else 0 )
            }
        }
    }
    return pre
}

func preSum3D3 ( a [] [] [ ] int ) [ ] [ ] [ ] int {
    pre := make ( [ ] [ ] [ ] int, len ( a ) )
    for i := 0; i < len ( a ); i++ {
        pre [ i ] = make ( [ ] [ ] int, len ( a [ i ] ) )
        for j := 0; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] = make ( [ ] int, len ( a [ i ] [ j ] ) )
        }
    }
    for k := 0; k < len ( a [ 0 ] [ 0 ] ); k++ {
        for i := 0; i < len ( a ); i++ {
            for j := 0; j < len ( a [ i ] ); j++ {
                pre [ i ] [ j ] [ k ] = a [ i ] [ j ] [ k ] + ( pre [ i - 1 ] [ j ] [ k ] if i > 0 else 0 ) + ( pre [ i ] [ j - 1 ] [ k ] if j > 0 else 0 ) + ( pre [ i ] [ j ] [ k - 1 ] if k > 0 else 0 ) - ( pre [ i - 1 ] [ j - 1 ] [ k ] if i > 0 && j > 0 else 0 ) - ( pre [ i ] [ j - 1 ] [ k - 1 ] if j > 0 && k > 0 else 0 ) - ( pre [ i - 1 ] [ j ] [ k - 1 ] if i > 0 && k > 0 else 0 ) + ( pre [ i - 1 ] [ j - 1 ] [ k - 1 ] if i > 0 && j > 0 && k > 0 else 0 )
            }
        }
    }
    return pre
}

func preSum3D4 ( a [] [] [ ] int ) [ ] [ ] [ ] int {
    pre := make ( [ ] [ ] [ ] int, len ( a ) )
    for i := 0; i < len ( a ); i++ {
        pre [ i ] = make ( [ ] [ ] int, len ( a [ i ] ) )
        for j := 0; j < len ( a [ i ] ); j++ {
            pre [ i ] [ j ] = make ( [ ] int, len ( a [ i ] [ j ] ) )
        }
    }
    for k := 0; k < len ( a [ 0 ] [ 0 ] ); k++ {
        for i := 0; i < len ( a ); i++ {
            for j := 0; j < len ( a [ i ] ); j++ {
     