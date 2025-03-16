
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int MX = 10000;
        int[] sieve = new int[MX];
        int[] primes = new int[0];
        for (int i = 2; i < MX; i++) {
            if (sieve[i] != 0) {
                continue;
            }
            primes = append(primes, i);
            for (int j = i + i; j < MX; j += i) {
                sieve[j] = i;
            }
        }

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            ans++;
            for (int j = 0; j < primes.length; j++) {
                if (x > primes[j] && x % primes[j] == 0) {
                    ans--;
                    break;
                }
            }
        }
        System.out.println(ans);
    }

    public static int[] append(int[] arr, int x) {
        int[] newArr = new int[arr.length + 1];
        for (int i = 0; i < arr.length; i++) {
            newArr[i] = arr[i];
        }
        newArr[arr.length] = x;
        return newArr;
    }
}

