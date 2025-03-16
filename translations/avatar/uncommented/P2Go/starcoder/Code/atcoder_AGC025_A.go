n := input ( )
a := [ "10", "100", "1000", "10000", "100000" ]
new := sum ( list ( map ( func ( x string ) int { return int ( x ) }, n ) ) )
if n in a {
    fmt.Println ( 10 )
} else {
    fmt.Println ( new )
}

