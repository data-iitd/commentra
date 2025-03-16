n := 0
l := make ( []int, 0, 100 )
for i := 0 ; i < 100 ; i++ {
    n = int ( input ( ) )
    l = append ( l, n )
}
ans := n - 1
last := 0
for i := 0 ; i < len ( l ) ; i++ {
    ans += abs ( last - l[i] ) + 1
    last = l[i]
}
fmt.Println ( ans )

