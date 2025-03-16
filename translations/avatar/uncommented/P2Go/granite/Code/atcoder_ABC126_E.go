
package main
import (
    "bufio"
    "container/list"
    "fmt"
    "os"
    "strconv"
    "strings"
)
var (
    in  = bufio.NewReader( os.Stdin )
    inf = int64( 1e18 )
)
func main() {
    n, m := readInt2()
    g := make( [][]int, n )
    for i := 0; i < m; i++ {
        x, y, z := readInt3()
        x--
        y--
        g[x] = append( g[x], y )
        g[y] = append( g[y], x )
    }
    used := make( []bool, n )
    ans := 0
    for i := 0; i < n; i++ {
        if!used[i] {
            ans++
            q := list.New()
            q.PushBack( i )
            for q.Len() > 0 {
                v := q.Front().Value.( int )
                q.Remove( q.Front() )
                if used[v] {
                    continue
                }
                used[v] = true
                for _, nv := range g[v] {
                    if!used[nv] {
                        q.PushBack( nv )
                    }
                }
            }
        }
    }
    fmt.Println( ans )
}
func readString() string {
    s, _ := in.ReadString( '\n' )
    return s[:len( s )-1]
}
func readInt() int {
    i, _ := strconv.Atoi( readString() )
    return i
}
func readInt2() ( int, int ) {
    a := strings.Split( readString(), " " )
    x, _ := strconv.Atoi( a[0] )
    y, _ := strconv.Atoi( a[1] )
    return x, y
}
func readInt3() ( int, int, int ) {
    a := strings.Split( readString(), " " )
    x, _ := strconv.Atoi( a[0] )
    y, _ := strconv.Atoi( a[1] )
    z, _ := strconv.Atoi( a[2] )
    return x, y, z
}
func readInt6() int64 {
    i, _ := strconv.ParseInt( readString(), 10, 64 )
    return i
}
func readInt62() ( int64, int64 ) {
    a := strings.Split( readString(), " " )
    x, _ := strconv.ParseInt( a[0], 10, 64 )
    y, _ := strconv.ParseInt( a[1], 10, 64 )
    return x, y
}
func readInt63() ( int64, int64, int64 ) {
    a := strings.Split( readString(), " " )
    x, _ := strconv.ParseInt( a[0], 10, 64 )
    y, _ := strconv.ParseInt( a[1], 10, 64 )
    z, _ := strconv.ParseInt( a[2], 10, 64 )
    return x, y, z
}
func min( a, b int ) int {
    if a < b {
        return a
    }
    return b
}
func max( a, b int ) int {
    if a > b {
        return a
    }
    return b
}
func pow( a, b int ) int {
    return int( float64( a ) * float64( b ) )
}
func abs( a int ) int {
    return int( math.Abs( float64( a ) ) )
}
func mod( a, b int ) int {
    return a - b * ( a / b )
}
func lcm( a, b int ) int {
    return a * b / gcd( a, b )
}
func gcd( a, b int ) int {
    if a == 0 || b == 0 {
        return max( a, b )
    }
    for b > 0 {
        a, b = b, a%b
    }
    return a
}
func isPrime( a int ) bool {
    if a <= 1 {
        return false
    }
    for i := 2; i*i <= a; i++ {
        if a%i == 0 {
            return false
        }
    }
    return true
}
func extGCD( a, b int ) ( int, int, int ) {
    if b == 0 {
        return a, 1, 0
    }
    x, y, g := extGCD( b, a%b )
    return x, y - ( a / b ) * y, g
}
func modInv( a, m int ) int {
    x, _, _ := extGCD( a, m )
    return x % m
}
func modDiv( a, b, m int ) int {
    a %= m
    b %= m
    return ( a * modInv( b, m ) ) % m
}
func modPow( a, b, m int ) int {
    c := 1
    for b > 0 {
        if b%2 == 1 {
            c = modDiv( c, a, m )
        }
        a = modDiv( a, a, m )
        b /= 2
    }
    return c
}
func isOk( x, y, tx, ty int ) bool {
    return tx <= x && x <= ty && tx <= y && y <= ty
}
func euclideanDist( x1, y1, x2, y2 int ) int {
    return abs( x1 - x2 ) + abs( y1 - y2 )
}
func manhattanDist( x1, y1, x2, y2 int ) int {
    return abs( x1 - x2 ) + abs( y1 - y2 )
}
func main() {
    n, m := readInt2()
    g := make( [][]int, n )
    for i := 0; i < m; i++ {
        x, y, z := readInt3()
        x--
        y--
        g[x] = append( g[x], y )
        g[y] = append( g[y], x )
    }
    used := make( []bool, n )
    ans := 0
    for i := 0; i < n; i++ {
        if!used[i] {
            ans++
            q := list.New()
            q.PushBack( i )
            for q.Len() > 0 {
                v := q.Front().Value.( int )
                q.Remove( q.Front() )
                if used[v] {
                    continue
                }
                used[v] = true
                for _, nv := range g[v] {
                    if!used[nv] {
                        q.PushBack( nv )
                    }
                }
            }
        }
    }
    fmt.Println( ans )
}
func readString() string {
    s, _ := in.ReadString( '\n' )
    return s[:len( s )-1]
}
func readInt() int {
    i, _ := strconv.Atoi( readString() )
    return i
}
func readInt2() ( int, int ) {
    a := strings.Split( readString(), " " )
    x, _ := strconv.Atoi( a[0] )
    y, _ := strconv.Atoi( a[1] )
    return x, y
}
func readInt3() ( int, int, int ) {
    a := strings.Split( readString(), " " )
    x, _ := strconv.Atoi( a[0] )
    y, _ := strconv.Atoi( a[1] )
    z, _ := strconv.Atoi( a[2] )
    return x, y, z
}
func readInt6() int64 {
    i, _ := strconv.ParseInt( readString(), 10, 64 )
    return i
}
func readInt62() ( int64, int64 ) {
    a := strings.Split( readString(), " " )
    x, _ := strconv.ParseInt( a[0], 10, 64 )
    y, _ := strconv.ParseInt( a[1], 10, 64 )
    return x, y
}
func readInt63() ( int64, int64, int64 ) {
    a := strings.Split( readString(), " " )
    x, _ := strconv.ParseInt( a[0], 10, 64 )
    y, _ := strconv.ParseInt( a[1], 10, 64 )
    z, _ := strconv.ParseInt( a[2], 10, 64 )
    return x, y, z
}
func min( a, b int ) int {
    if a < b {
        return a
    }
    return b
}
func max( a, b int ) int {
    if a > b {
        return a
    }
    return b
}
func pow( a, b int ) int {
    return int( float64( a ) * float64( b ) )
}
func abs( a int ) int {
    return int( math.Abs( float64( a ) ) )
}
func mod( a, b int ) int {
    return a - b * ( a / b )
}
func lcm( a, b int ) int {
    return a * b / gcd( a, b )
}
func gcd( a, b int ) int {
    if a == 0 || b == 0 {
        return max( a, b )
    }
    for i := 2; i*i <= a; i++ {
        if a%i == 0 {
            return false
        }
    }
    return true
}
func isPrime( a int ) bool {
    if a <= 1 {
        return false
    }
    for i := 2; i*i <= a; i++ {
        if a%i == 0 {
            return false
        }
    }
    return true
}
func extGCD( a, b int ) ( int, int, int ) {
    if b == 0 {
        return a, 1, 0
    }
    x, y, g := extGCD( b, a%b )
    return x, y - ( a / b ) * y, g
}
func modInv( a, m int ) int {
    x, _, _ := extGCD( a, m )
    return x % m
}
func modDiv( a, b, m int ) int {
    a %= m
    b %= m
    return ( a * modInv( b, m ) ) % m
}
func modPow( a, b, m int ) int {
    c := 1
    for b > 0 {
        if b%2 == 1 {
            c = modDiv( c, a, m )
        }
        a = modDiv( a, a, m )
        b /= 2
    }
    return c
}
func isOk( x, y, tx, ty int ) bool {
    return tx <= x && x <= ty && tx <= y && y <= ty
}
func euclideanDist( x1, y1, x2, y2 int ) int {
    return abs( x1 - x2 ) + abs( y1 - y2 )
}
func manhattanDist( x1, y1, x2, y2 int ) int {
    return abs( x1 - x2 ) + abs( y1 - y2 )
}
