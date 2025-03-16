n := int ( input ( ) )
import "fmt"
import "math"
import "sort"
import "strconv"
import "strings"

func main ( ) {
    orig := make ( [] [] int )
    for i := 0 ; i < n ; i++ {
        orig = append ( orig, make ( [] int ) )
        for j := 0 ; j < n ; j++ {
            orig [ i ] = append ( orig [ i ], j + 1 )
        }
    }
    p := strings.Split ( strings.TrimSpace ( input ( ) ), " " )
    q := strings.Split ( strings.TrimSpace ( input ( ) ), " " )
    p = make ( [] int, len ( p ) )
    q = make ( [] int, len ( q ) )
    for i := 0 ; i < len ( p ) ; i++ {
        p [ i ], _ = strconv.Atoi ( p [ i ] )
    }
    for i := 0 ; i < len ( q ) ; i++ {
        q [ i ], _ = strconv.Atoi ( q [ i ] )
    }
    pn := sort.Search ( len ( orig ), func ( i int ) bool {
        return reflect.DeepEqual ( orig [ i ], p )
    } )
    qn := sort.Search ( len ( orig ), func ( i int ) bool {
        return reflect.DeepEqual ( orig [ i ], q )
    } )
    fmt.Println ( int ( math.Abs ( float64 ( pn - qn ) ) ) )
}

