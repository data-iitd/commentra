package main
import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)
func solve ( N int , x []int , y []int ) {
    indices := make ( []int , N )
    for i := 0 ; i < N ; i++ {
        indices [ i ] = i
    }
    permutations := make ( [][]int , 0 )
    for i := 0 ; i < N ; i++ {
        for j := 0 ; j < N ; j++ {
            for k := 0 ; k < N ; k++ {
                permutations = append ( permutations , []int { i , j , k } )
            }
        }
    }
    distances := make ( []float64 , 0 )
    for _, permutation := range permutations {
        total_distance := 0.0
        for i := 0 ; i < N - 1 ; i++ {
            f , t := permutation [ i ] , permutation [ i + 1 ]
            distance := math.Sqrt ( float64 ( ( x [ t ] - x [ f ] ) * ( x [ t ] - x [ f ] ) + ( y [ t ] - y [ f ] ) * ( y [ t ] - y [ f ] ) ) )
            total_distance += distance
        }
        distances = append ( distances , total_distance )
    }
    result := 0.0
    for _, distance := range distances {
        result += distance
    }
    result /= float64 ( len ( distances ) )
    fmt.Println ( result )
    return
}
func main ( ) {
    tokens := make ( []string , 0 )
    for _, line := range strings.Split ( os.Args [ 1 ] , "\n" ) {
        for _, word := range strings.Split ( line , " " ) {
            tokens = append ( tokens , word )
        }
    }
    N , _ := strconv.Atoi ( tokens [ 0 ] )
    x := make ( []int , N )
    y := make ( []int , N )
    for i := 1 ; i <= N ; i++ {
        x [ i - 1 ] , _ = strconv.Atoi ( tokens [ i ] )
        y [ i - 1 ] , _ = strconv.Atoi ( tokens [ i + N ] )
    }
    solve ( N , x , y )
}
// 