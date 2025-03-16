n := 0
number := []int{}
h1 := 0
h2 := 0
x := 0
for i := 0 ; i < len ( number ) ; i ++ {
    if number [ i ]!= 4 && number [ i ]!= 7 {
        fmt.Println ( "NO" )
        x += 1
        break
    }
    if i < n / 2 {
        h1 += number [ i ]
    } else {
        h2 += number [ i ]
    }
}
if!x {
    if h1 == h2 {
        fmt.Println ( "YES" )
    } else {
        fmt.Println ( "NO" )
    }
}

