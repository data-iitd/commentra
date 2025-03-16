// Importing the Math class.
import java.math.BigInteger;

// Reading the input N and storing the list A of N integers.
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
BigInteger[] A = new BigInteger[N];
for (int i = 0; i < N; i++) {
    A[i] = sc.nextBigInteger();
}

// Initializing the variable _lcm to 1.
BigInteger _lcm = BigInteger.ONE;

// Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
for (BigInteger a : A) {
    // Update the value of _lcm using the lcm function.
    _lcm = _lcm.multiply(a).divide(a.gcd(_lcm));
}

// Calculating the answer ans using the formula _lcm * sum ( [ pow ( s, MOD - 2, MOD ) for s in A ] ) % MOD.
BigInteger ans = _lcm.multiply(BigInteger.valueOf(Arrays.stream(A).map(s -> s.pow(MOD - 2).remainder(MOD)).sum())).remainder(MOD);

// Printing the final answer.
System.out.println(ans);

