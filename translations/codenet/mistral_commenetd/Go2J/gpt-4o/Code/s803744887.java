import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // This is the main function where the program starts execution
    public static void main(String[] args) {
        // Constants are variables whose values cannot be changed during runtime.
        // Here we define a constant named MX with a value of 10000.
        final int MX = 10000;

        // We create two lists, one named 'sieve' and another named 'primes'.
        // The 'sieve' list is of size MX and is initialized with zeros.
        // The 'primes' list is initialized as an empty list.
        int[] sieve = new int[MX];
        List<Integer> primes = new ArrayList<>();

        // We initialize a for loop that starts from 2 and goes up to MX-1.
        // The reason for starting from 2 is that we are only interested in prime numbers.
        for (int i = 2; i < MX; i++) {
            if (sieve[i] != 0) {
                continue;
            }
            // If 'sieve[i]' is zero, then 'i' is a prime number.
            // We append this prime number to the 'primes' list.
            primes.add(i);

            // Now we check all multiples of 'i' starting from 'i+i' (which is the next multiple of 'i').
            // We mark all these multiples as 'composite' by setting their corresponding 'sieve' elements to 'i'.
            for (int j = i + i; j < MX; j += i) {
                sieve[j] = i;
            }
        }

        // We read an integer 'n' from the standard input using 'Scanner'.
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // We initialize a variable 'ans' with a value of 0.
        // This variable will store the count of numbers that are not composite.
        int ans = 0;

        // We read 'n' integers from the standard input using 'Scanner'.
        for (int i = 0; i < n; i++) {
            // We read an integer 'x' from the standard input.
            int x = scanner.nextInt();

            // We increment the 'ans' variable as 'x' is not composite at this point.
            ans++;

            // We check all prime numbers in the 'primes' list to see if 'x' is divisible by any of them.
            // If 'x' is divisible by any prime number, then it is composite and we decrement the 'ans' variable.
            for (int j = 0; j < primes.size(); j++) {
                if (x > primes.get(j) && x % primes.get(j) == 0) {
                    ans--;
                    break;
                }
            }
        }

        // We print the final answer using 'System.out.println'.
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
