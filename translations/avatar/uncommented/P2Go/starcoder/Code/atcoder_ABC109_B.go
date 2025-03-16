n := 0
s := make ( map [ string ] int )
l := make ( []string, n )
f := "Yes"
i := -1
for v := range l {
    s [ v ] += 1
    if s [ v ] >= 2 {
        f = "No"
    }
    if i!= -1 && l [ i ] [ -1 ]!= v [ 0 ] {
        f = "No"
    }
    i++
}
fmt.Println ( f )

