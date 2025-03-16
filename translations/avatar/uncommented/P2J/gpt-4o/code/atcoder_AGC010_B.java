import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        List<Integer> a = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }
        
        int sumA = 0;
        for (int num : a) {
            sumA += num;
        }
        
        if (sumA % (n * (n + 1) / 2) != 0) {
            System.out.println("NO");
        } else {
            double k = (double) sumA / (n * (n + 1) / 2);
            a.add(a.get(0)); // Add the first element to the end
            
            double sum1 = 0;
            double sum2 = 0;
            for (int i = 1; i < a.size(); i++) {
                int iVal = a.get(i);
                int jVal = a.get(i - 1);
                sum1 += (k - iVal + jVal) % n;
                sum2 += (k - iVal + jVal) / n >= 0 ? 1 : 0;
            }
            
            if (sum1 != 0 || sum2 != n) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
