
package main
import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)
func solve ( N int, x [] int, y [] int ) {
    indices := make ( [] int, N )
    for i := 0 ; i < N ; i ++ {
        indices [ i ] = i
    }
    permutations := make ( [][] int, 0 )
    for i := 0 ; i < N ; i ++ {
        for j := i + 1 ; j <= N ; j ++ {
            permutations = append ( permutations, indices [ i : j ] )
        }
    }
    distances := make ( [] float64, 0 )
    for _, permutation := range permutations {
        total_distance := 0.0
        for i := 0 ; i < N - 1 ; i ++ {
            f, t := permutation [ i ], permutation [ i + 1 ]
            distance := ( ( float64 ( x [ t ] ) - float64 ( x [ f ] ) ) ** 2 + ( ( float64 ( y [ t ] ) ) - ( float64 ( y [ f ] ) ) ** 2 ) ** 0.5
            total_distance += distance
        }
        distances = append ( distances, total_distance )
    }
    result := 0.0
    for _, distance := range distances {
        result += distance
    }
    result /= float64 ( len ( distances ) )
    fmt.Println ( result )
}
func main ( ) {
    reader := bufio.NewReader ( os.Stdin )
    N, _ := strconv.Atoi ( strings.TrimSpace ( readLine ( reader ) )
    x := make ( [] int, N )
    y := make ( [] int, N )
    for i := 0 ; i < N ; i ++ {
        x [ i ], _ = strconv.Atoi ( strings.TrimSpace ( readLine ( reader ) )
        y [ i ], _ = strconv.Atoi ( strings.TrimSpace ( readLine ( reader ) )
    }
    solve ( N, x, y )
}
func readLine ( reader * bufio.Reader ) string {
    str, _ := reader.ReadString ( '\n' )
    return strings.TrimSpace ( str )
}
