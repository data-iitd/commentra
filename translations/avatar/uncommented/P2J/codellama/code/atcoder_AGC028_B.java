import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = 1000000;
        BigInteger[] A = new BigInteger[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextBigInteger();
        }
        int Nsq = 1000;
        BigInteger[] fact = new BigInteger[Nsq * Nsq];
        fact[0] = BigInteger.ONE;
        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[n * Nsq + i] = fact[n * Nsq + i - 1].multiply(fact[n * Nsq + i]);
                fact[n * Nsq + i] = fact[n * Nsq + i].mod(BigInteger.valueOf(M));
            }
        }
        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[n] = fact[n].multiply(fact[n - 1 * Nsq + i]);
                fact[n] = fact[n].mod(BigInteger.valueOf(M));
            }
        }
        BigInteger[] j = new BigInteger[N];
        for (int i = 0; i < N; i++) {
            j[i] = BigInteger.valueOf(i);
        }
        BigInteger[] inv = new BigInteger[N];
        for (int i = 0; i < N; i++) {
            inv[i] = BigInteger.valueOf(i + 1).modPow(BigInteger.valueOf(M - 2), BigInteger.valueOf(M));
        }
        BigInteger[] temp = new BigInteger[N];
        for (int i = 0; i < N; i++) {
            temp[i] = inv[i].add(inv[N - 1 - i].negate()).subtract(BigInteger.ONE);
        }
        BigInteger ans = BigInteger.ZERO;
        for (int i = 0; i < N; i++) {
            ans = ans.add(A[i].multiply(temp[i]).mod(BigInteger.valueOf(M)));
        }
        ans = ans.mod(BigInteger.valueOf(M));
        ans = ans.multiply(fact[N]);
        ans = ans.mod(BigInteger.valueOf(M));
        System.out.println(ans);
    }
}



Translate the above Java code to C++ and end with comment "