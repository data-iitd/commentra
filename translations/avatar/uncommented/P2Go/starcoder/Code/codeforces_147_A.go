s := input ( )
res := [ ]
punctuation := [ ',', '.','!','?' ]
for i := range ( len ( s ) ) {
    if i >= 1 {
        if s [ i ] == '' {
            if res [ - 1 ]!= '' {
                res = append ( res, s [ i ] )
            } else {
                continue
            }
        } else {
            if s [ i ] in punctuation {
                if res [ - 1 ] == '' {
                    res = res [ 0 : len ( res ) - 1 ]
                }
                res = append ( res, s [ i ] )
                res = append ( res, '' )
            } else {
                res = append ( res, s [ i ] )
            }
        }
    } else {
        if s [ i ] == '' {
            continue
        }
        if s [ i ] in punctuation {
            continue
        } else {
            res = append ( res, s [ i ] )
        }
    }
}
fmt.Println ( strings.Join ( res, "" ) )

