
import java.math.BigInteger;
import java.util.Scanner;
public final class KaratsubaMultiplication {
    private KaratsubaMultiplication() {
    }
    public static BigInteger karatsuba(BigInteger x, BigInteger y) {
        if (x.bitLength() <= 4 || y.bitLength() <= 4) {
            return x.multiply(y);
        }
        int n = Math.max(x.bitLength(), y.bitLength());
        int m = n / 2;
        BigInteger high1 = x.shiftRight(m); 
        BigInteger low1 = x.subtract(high1.shiftLeft(m)); 
        BigInteger high2 = y.shiftRight(m); 
        BigInteger low2 = y.subtract(high2.shiftLeft(m)); 
        BigInteger z0 = karatsuba(low1, low2); 
        BigInteger z1 = karatsuba(low1.add(high1), low2.add(high2)); 
        BigInteger z2 = karatsuba(high1, high2); 
        return z2.shiftLeft(2 * m) 
                .add(z1.subtract(z2).subtract(z0).shiftLeft(m)) 
                .add(z0); 
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            BigInteger num1 = new BigInteger(scanner.nextLine().trim());
            BigInteger num2 = new BigInteger(scanner.nextLine().trim());
            BigInteger result = karatsuba(num1, num2);
            System.out.println("The product of the two numbers is:");
            System.out.println(result);
        } catch (NumberFormatException e) {
            System.err.println("Invalid input. Please enter valid large numbers.");
        } finally {
            scanner.close();
        }
    }
}
