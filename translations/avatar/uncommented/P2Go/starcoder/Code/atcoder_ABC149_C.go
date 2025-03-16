package main
import "fmt"
func main() {
	var X int
	fmt.Scan( &X )
	prime := make( []bool, 100010 )
	for i := 0 ; i < 100010 ; i++ {
		prime[ i ] = true
	}
	prime[ 0 ] = false
	prime[ 1 ] = false
	for i := 4 ; i < 100010 ; i += 2 {
		prime[ i ] = false
	}
	i := 3
	for i * i <= 100008 {
		if prime[ i ] {
			for j := i + i ; j < 100008 ; j += i {
				prime[ j ] = false
		}
	}
	for i := X ; i < 100008 ; i++ {
		if prime[ i ] {
			fmt.Println( i )
			break
		}
	}
}
