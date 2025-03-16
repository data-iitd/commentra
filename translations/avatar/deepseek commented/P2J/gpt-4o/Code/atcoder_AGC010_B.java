import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        List<Integer> a = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }
        
        // Check if the sum of the list is divisible by the triangular number (n * (n + 1) / 2)
        if (sum(a) % (n * (n + 1) / 2) != 0) {
            System.out.println("NO");
        } else {
            double k = (double) sum(a) / (n * (n + 1) / 2);
            a.add(a.get(0)); // Append the first element to the end of the list to create a circular list
            
            boolean condition1 = false;
            boolean condition2 = true;
            for (int i = 1; i < a.size(); i++) {
                int j = i - 1;
                double value1 = (k - a.get(i) + a.get(j)) % n;
                condition1 |= (value1 != 0);
                condition2 &= ((k - a.get(i) + a.get(j)) / n >= 0);
            }
            
            if (condition1 || !condition2) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
        
        scanner.close();
    }
    
    private static int sum(List<Integer> list) {
        int total = 0;
        for (int num : list) {
            total += num;
        }
        return total;
    }
}
// <END-OF-CODE>
