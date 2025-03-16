package main
import "fmt"
func twos_in_factorial ( n int ) int {
    return n - strings.Count ( fmt.Sprintf ( "%b", n ), "1" )
}
func parity_of_nCr ( n, i int ) bool {
    f := twos_in_factorial
    return f ( n ) - f ( n - i ) - f ( i ) > 0
}
func main ( ) {
    var n int
    fmt.Scan ( &n )
    nums := make ( []int, n )
    for i := range nums {
        fmt.Scan ( &nums[i] )
        nums[i] -= 1
    }
    no_one := false
    if 1 not in nums {
        nums = [ ]
        for _, num := range nums {
            nums = append ( nums, num / 2 )
        }
        no_one = true
    }
    is_odd := false
    for i, num := range nums {
        if!parity_of_nCr ( n - 1, i ) && num & 1 {
            is_odd ^= 1
    }
    if!is_odd {
        fmt.Println ( 0 )
    } else {
        fmt.Println ( 1 << no_one )
}
}
