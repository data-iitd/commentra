// Importing the math/big module and defining a function lcm to calculate the least common multiple of two numbers a and b.
import "math/big"
func lcm(a, b *big.Int) *big.Int {
    // Calculate the greatest common divisor of a and b using the GCD function.
    g := new(big.Int)
    g.GCD(nil, nil, a, b)
    // Return the product of a and b divided by their greatest common divisor.
    return new(big.Int).Mul(a, b).Div(new(big.Int).Mul(a, b), g)
}

// Setting the value of MOD to 10^9 + 7.
const MOD = 1000000007

// Reading the input N and storing the list A of N integers.
var N int
var A []int
fmt.Scanf("%d", &N)
for i := 0; i < N; i++ {
    var a int
    fmt.Scanf("%d", &a)
    A = append(A, a)
}

// Initializing the variable _lcm to 1.
var _lcm big.Int
_lcm.SetInt64(1)

// Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
for _, a := range A {
    // Update the value of _lcm using the lcm function.
    _lcm.Set(lcm(_lcm.SetInt64(int64(a)), _lcm))
}

// Calculating the answer ans using the formula _lcm * sum ( [ pow ( s, MOD - 2, MOD ) for s in A ] ) % MOD.
var ans big.Int
ans.Set(new(big.Int).Mul(_lcm, big.NewInt(0).SetInt64(int64(len(A)))))
for _, s := range A {
    ans.Mul(ans, big.NewInt(0).SetInt64(int64(s))).Mod(ans, big.NewInt(0).SetInt64(int64(MOD)))
}
ans.Mul(ans, _lcm).Mod(ans, big.NewInt(0).SetInt64(int64(MOD)))

// Printing the final answer.
fmt.Println(ans.Int64() % MOD)

