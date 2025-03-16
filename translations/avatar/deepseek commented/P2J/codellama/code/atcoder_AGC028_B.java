
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int M = 1000000;
        int Nsq = 1000;
        BigInteger[][] fact = new BigInteger[Nsq][Nsq];
        for (int i = 0; i < Nsq; i++) {
            for (int j = 0; j < Nsq; j++) {
                fact[i][j] = BigInteger.valueOf(i * j);
            }
        }
        for (int i = 1; i < Nsq; i++) {
            for (int j = 0; j < Nsq; j++) {
                fact[i][j] = fact[i][j].multiply(fact[i - 1][j]);
            }
        }
        for (int i = 1; i < Nsq; i++) {
            for (int j = 0; j < Nsq; j++) {
                fact[i][j] = fact[i][j].multiply(fact[i - 1][Nsq - 1]);
            }
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
            ans = ans.add(A[i].multiply(temp[i]));
        }
        ans = ans.mod(BigInteger.valueOf(M));
        for (int i = 0; i < Nsq; i++) {
            for (int j = 0; j < Nsq; j++) {
                fact[i][j] = fact[i][j].multiply(fact[i - 1][j]);
            }
        }
        for (int i = 1; i < Nsq; i++) {
            for (int j = 0; j < Nsq; j++) {
                fact[i][j] = fact[i][j].multiply(fact[i - 1][Nsq - 1]);
            }
        }
        ans = ans.multiply(fact[Nsq - 1][Nsq - 1]);
        ans = ans.mod(BigInteger.valueOf(M));
        System.out.println(ans);
    }
}

