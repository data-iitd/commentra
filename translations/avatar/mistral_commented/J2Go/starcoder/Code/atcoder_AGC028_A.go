#######
// Import necessary libraries
#######
import "fmt"
import "math/big"

func main() {
  // Read input values for n and m
  var n, m int
  fmt.Scanf("%d %d", &n, &m)

  // Calculate the greatest common divisor (GCD) of n and m
  gcd := big.Int{}
  gcd.GCD(nil, nil, big.NewInt(int64(n)), big.NewInt(int64(m)))

  // Read input strings s and t
  var s, t string
  fmt.Scanf("%s %s", &s, &t)

  // Perform the required calculation and print the result
  result := -1
  for k := 0; k < gcd.Int64(); k++ {
    if s[k*n/gcd]!= t[k*m/gcd] {
      result = -1
      break
    }
    result = k
  }
  if result == -1 {
    result = n*m/gcd.Int64()
  }

  // Print the result
  fmt.Printf("%d\n", result)
}

