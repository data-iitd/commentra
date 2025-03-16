public class Main {
    public static void main(String[] args) {
        // Constants are variables whose values cannot be changed during runtime.
        // Here we define a constant named MX with a value of 10000.
        final int MX = 10000;

        // We create two arrays, one named 'sieve' and another named 'primes'.
        // The 'sieve' array is of size MX and is initialized with zeros.
        // The 'primes' array is of size 0 initially but will grow dynamically.
        int[] sieve = new int[MX];
        int[] primes = new int[0];

        // We initialize a for loop that starts from 2 and goes up to MX-1.
        // The reason for starting from 2 is that we are only interested in prime numbers.
        // If 'sieve[i]' is already non-zero, then 'i' is not a prime number and we move on to the next iteration.
        for (int i = 2; i < MX; i++) {
            if (sieve[i] != 0) {
                continue;
            }
            // If 'sieve[i]' is zero, then 'i' is a prime number.
            // We append this prime number to the 'primes' array.
            primes = appendToArray(primes, i);

            // Now we check all multiples of 'i' starting from 'i+i' (which is the next multiple of 'i').
            // We mark all these multiples as 'composite' by setting their corresponding 'sieve' elements to 'i'.
            for (int j = i + i; j < MX; j += i) {
                sieve[j] = i;
            }
        }

        // We read an integer 'n' from the standard input using Scanner class.
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // We initialize a variable 'ans' with a value of 0.
        // This variable will store the count of numbers that are not composite.
        int ans = 0;

        // We read 'n' integers from the standard input using Scanner class.
        for (int i = 0; i < n; i++) {
            // We read an integer 'x' from the standard input.
            int x = scanner.nextInt();

            // We increment the 'ans' variable as 'x' is not composite at this point.
            ans++;

            // We check all prime numbers in the 'primes' array to see if 'x' is divisible by any of them.
            // If 'x' is divisible by any prime number, then it is composite and we decrement the 'ans' variable.
            for (int j = 0; j < primes.length; j++) {
                if (x > primes[j] && x % primes[j] == 0) {
                    ans--;
                    break;
                }
            }
        }

        // We print the final answer using System.out.println function.
        System.out.println(ans);
    }

    // Helper method to append an element to an array
    public static int[] appendToArray(int[] array, int element) {
        int[] newArray = new int[array.length + 1];
        System.arraycopy(array, 0, newArray, 0, array.length);
        newArray[array.length] = element;
        return newArray;
    }
}
