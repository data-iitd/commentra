public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        long sum = 0;
        long wa = 0;
        long min = 1123456789;
        int ans = 0;
        int shou = 0;
        
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
            sum += A[i];
            wa += i + 1;
        }
        
        if (sum % wa != 0) {
            ans = 0;
        } else {
            shou = (int) (sum / wa);
            int[] sa = new int[N];
            for (int i = 0; i < N; i++) {
                sa[i] = A[(i + 1) % N] - A[i] - shou;
            }
            
            for (int i = 0; i < N - 1; i++) {
                if (sa[i] <= 0 && sa[i] % N == 0) {
                    ans = 1;
                } else {
                    ans = 0;
                    break;
                }
            }
        }
        
        if (ans == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
