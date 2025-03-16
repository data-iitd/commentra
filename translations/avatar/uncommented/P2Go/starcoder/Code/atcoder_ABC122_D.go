func ok ( last4 string ) bool {
    for i := 0 ; i < 4 ; i++ {
        t := []byte ( last4 )
        if i >= 1 {
            t [ i ], t [ i - 1 ] = t [ i - 1 ], t [ i ]
        }
        if strings.Count ( string ( t ), "AGC" ) >= 1 {
            return false
        }
    }
    return true
}
func dfs ( cur int, last3 string ) int {
    if last3, ok := memo [ cur ] [ last3 ]; ok {
        return last3
    }
    if cur == n {
        return 1
    }
    ret := 0
    for _, c := range "ACGT" {
        if ok ( last3 + string ( c ) ) {
            ret = ( ret + dfs ( cur + 1, last3 [ 1 : ] + string ( c ) ) ) % mod
        }
    }
    memo [ cur ] [ last3 ] = ret
    return ret
}
var (
    n   int
    mod int = 1e9 + 7
    memo [ 1001 ][ 4 ]string
)
func main ( ) {
    fmt.Scan ( &n )
    fmt.Println ( dfs ( 0, "TTT" ) )
}
