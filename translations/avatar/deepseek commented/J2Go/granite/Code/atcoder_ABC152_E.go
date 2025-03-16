

package main 

import ( 
    "bufio" 
    "fmt" 
    "math/big" 
    "os" 
    "strconv" 
    "strings" 
) 

func main ( ) { 
    reader := bufio.NewReader ( os.Stdin ) 
    var N int 
    var err error 
    if N, err = strconv.Atoi ( strings.TrimSpace ( reader.ReadLine ( ) ) ; err!= nil { 
        panic ( err ) 
    } 
    A := make ( []int, N ) 
    for i := 0 ; i < N ; i ++ { 
        if A [ i ], err = strconv.Atoi ( strings.TrimSpace ( reader.ReadLine ( ) ) ; err!= nil { 
            panic ( err ) 
        } 
    } 
    reader.ReadLine ( ) 
    lcm := big.NewInt ( 1 ) 
    for _, a := range A { 
        lcm.Div ( lcm, big.NewInt ( int64 ( a ) ) ) 
        lcm.Mul ( lcm, big.NewInt ( int64 ( a ) ) ) 
    } 
    mod := int64 ( 1e9 + 7 ) 
    modLcm := lcm.Mod ( lcm, big.NewInt ( mod ) ). Int64 ( ) 
    ans := int64 ( 0 ) 
    for _, a := range A { 
        ans = ( ans + modDiv ( modLcm, int64 ( a ), mod ) ) % mod 
    } 
    fmt.Println ( ans ) 
    // 