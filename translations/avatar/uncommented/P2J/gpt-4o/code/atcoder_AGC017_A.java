import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        int P = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        int[] lis = new int[N];
        for (int i = 0; i < N; i++) {
            lis[i] = scanner.nextInt();
        }
        
        int[] ls = new int[N];
        for (int i = 0; i < N; i++) {
            ls[i] = lis[i] % 2;
        }
        
        int one = 0;
        int zero = 0;
        for (int value : ls) {
            if (value == 1) {
                one++;
            } else {
                zero++;
            }
        }
        
        long patternA = 0;
        long patternB = 0;
        
        for (int j = 0; j <= zero; j++) {
            patternB += combi(zero, j);
        }
        
        for (int time = 0; time <= one; time++) {
            if (time % 2 == P) {
                patternA += combi(one, time);
            }
        }
        
        System.out.println(patternA * patternB);
    }
    
    public static long combi(int N, int K) {
        long a = 1;
        for (int i = 0; i < K; i++) {
            a *= (N - i);
        }
        for (int j = 0; j < K; j++) {
            a /= (j + 1);
        }
        return a;
    }
}

// <END-OF-CODE>
