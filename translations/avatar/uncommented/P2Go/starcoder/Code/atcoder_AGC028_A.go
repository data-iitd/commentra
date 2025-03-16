package main
import "fmt"
import "math"
func main() {
	var N, M int
	var S, T string
	fmt.Scan( &N, &M, &S, &T )
	list_S := []byte( S )
	list_T := []byte( T )
	Number_i := make( []int, N )
	for i := 0; i < N; i++ {
		Number_i[ i ] = i
	}
	Number_iMN := make( []int, N )
	for i := 0; i < N; i++ {
		Number_iMN[ i ] = int( float64( i ) * float64( M ) / float64( N ) )
	}
	Number_j := make( []int, M )
	for j := 0; j < M; j++ {
		Number_j[ j ] = j
	}
	Kaburi_j := make( []int, 0 )
	for _, j := range Number_j {
		if _, ok := map[ int ]bool{ j: true }[ int( float64( j ) * float64( N ) / float64( M ) ) ]; ok {
			Kaburi_j = append( Kaburi_j, j )
		}
	}
	Kaburi_i := make( []int, len( Kaburi_j ) )
	for i, j := range Kaburi_j {
		Kaburi_i[ i ] = int( float64( j ) * float64( N ) / float64( M ) )
	}
	counter := 0
	Flag := 0
	Kaburi_Size := len( Kaburi_i )
	for counter <= Kaburi_Size - 1 {
		if list_S[ Kaburi_i[ counter ] ]!= list_T[ Kaburi_j[ counter ] ] {
			Flag = 1
			break
		}
		counter++
	}
	if Flag == 1 {
		fmt.Println( -1 )
	} else {
		fmt.Println( int( float64( N ) * float64( M ) / float64( math.GCD( N, M ) ) ) )
	}
}
