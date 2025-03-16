
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Solves the Chinese Remainder Theorem (CRT)
    public static int solveCRT(List<Integer> remainders, List<Integer> moduli) {
        int product = 1;
        int result = 0;

        // Calculate the product of all moduli
        for (int mod : moduli) {
            product *= mod;
        }

        // Iterate through each modulus and calculate the partial solution
        for (int i = 0; i < moduli.size(); i++) {
            int partialProduct = product / moduli.get(i);
            int inverse = modInverse(partialProduct, moduli.get(i));
            result += remainders.get(i) * partialProduct * inverse;
        }

        // Reduce the result modulo the product of all moduli
        result = result % product;

        // Ensure the result is positive
        if (result < 0) {
            result += product;
        }

        return result;
    }

    // Calculates the modular multiplicative inverse
    private static int modInverse(int a, int m) {
        int m0 = m;
        int x0 = 0;
        int x1 = 1;

        // Base case for the algorithm
        if (m == 1) {
            return 0;
        }

        // Extended Euclidean Algorithm
        while (a > 1) {
            int q = a / m;
            int t = m;
            m = a % m;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        // Make sure x1 is positive
        if (x1 < 0) {
            x1 += m0;
        }

        return x1;
    }

    // Entry point of the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> remainders = new ArrayList<>();
        List<Integer> moduli = new ArrayList<>();

        // Read the remainders and moduli from the user
        for (int i = 0; i < n; i++) {
            int remainder = scanner.nextInt();
            int modulus = scanner.nextInt();
            remainders.add(remainder);
            moduli.add(modulus);
        }

        // Solve the CRT and print the result
        int solution = solveCRT(remainders, moduli);
        System.out.println("Smallest positive solution: " + solution);
        scanner.close();
    }
}