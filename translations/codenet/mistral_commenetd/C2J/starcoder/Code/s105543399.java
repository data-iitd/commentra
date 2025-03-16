import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in); // We create a new Scanner object to read from the standard input
    long n = in.nextLong(); // We read the first number 'n' from the standard input
    long a, m, M, c, b, i; // We declare variables of type long for numbers that can be very large
    long c = 0; // We initialize the variable 'c' to zero
    long m = 100000000; // We initialize'm' to a very large negative number
    long M =-100000000; // We initialize 'M' to a very large positive number

    for(i=1; i<=n; i++){ // We start a for loop that iterates 'n' times
      a = in.nextLong(); // We read the current number 'a' from the standard input

      if(a>M) { // If the current number 'a' is greater than the current maximum number 'M', we update 'M' with 'a'
        M = a;
      }

      if(a < m){ // If the current number 'a' is smaller than the current minimum number'm', we update'm' with 'a'
        m = a;
      }

      c = c+a; // We add the current number 'a' to the variable 'c'
    }

    System.out.printf("%lld %lld %lld\n",m,M,c); // We print the minimum number'm', the maximum number 'M', and the sum 'c' to the standard output
  }
}
