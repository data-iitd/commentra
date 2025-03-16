
package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
type pair struct {
    first, second int
}
func bfs ( v int, N int, G [] [] int, E map [pair] int ) int {
    visited := make ( [] bool, N )
    queue := make ( [] int, 0 )
    K := - 1
    node2color := make ( [] int, N )
    queue = append ( queue, v )
    visited [ v ] = true
    for len ( queue ) > 0 {
        q := queue [ 0 ]
        queue = queue [ 1 : ]
        color := 0
        for _, nex := range G [ q ] {
            if visited [ nex ] {
                continue
            }
            visited [ nex ] = true
            color += 1
            if color == node2color [ q ] {
                color += 1
            }
            node2color [ nex ] = color
            E [ pair { min ( q, nex ), max ( q, nex ) } ] = color
            queue = append ( queue, nex )
        }
        K = max ( K, color )
    }
    return K
}
func main ( ) {
    reader := bufio.NewReader ( os.Stdin )
    N, _ := strconv.Atoi ( strings.TrimSpace ( readLine ( reader ) )
    G := make ( [] [] int, N )
    E := make ( map [pair] int )
    for i := 0; i < N - 1; i++ {
        a, _ := strconv.Atoi ( strings.TrimSpace ( readLine ( reader ) ) )
        b, _ := strconv.Atoi ( strings.TrimSpace ( readLine ( reader ) ) )
        a -= 1
        b -= 1
        G [ a ] = append ( G [ a ], b )
        G [ b ] = append ( G [ b ], a )
        E [ pair { min ( a, b ), max ( a, b ) } ] = 0
    }
    K := bfs ( 0, N, G, E )
    fmt.Println ( K )
    for _, value := range E {
        fmt.Println ( value )
    }
}
func readLine ( reader * bufio.Reader ) string {
    str, _, err := reader.ReadLine ( )
    if err == nil {
        return string ( str )
    }
    return ""
}
func max ( a int, b int ) int {
    if a > b {
        return a
    }
    return b
}
