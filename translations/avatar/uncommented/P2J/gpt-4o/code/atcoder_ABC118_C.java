import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        int[] A = Arrays.stream(scanner.nextLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();
        
        int gcd = A[0];
        for (int i = 1; i < A.length; i++) {
            gcd = gcd(gcd, A[i]);
        }
        
        System.out.println(gcd);
    }
    
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
// <END-OF-CODE>
