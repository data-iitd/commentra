
import java.util.Scanner;

public class s648501684{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long q = scanner.nextLong();
        
        int[] arr = new int[(int)n+1];
        for(long i=0; i<=n; i++) {
            arr[(int)i] = 0;
        }
        
        for(long i=0; i<q; i++) {
            long temp = scanner.nextLong();
            arr[(int)temp] += 1;
        }
        
        for(long i=1; i<=n; i++) {
            if(arr[(int)i]>(q-k)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
