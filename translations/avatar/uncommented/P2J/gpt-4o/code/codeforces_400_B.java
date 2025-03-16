import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        Set<Integer> c = new HashSet<>();
        
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            int gIndex = s.indexOf('G');
            int sIndex = s.indexOf('S');
            c.add(sIndex - gIndex);
        }
        
        boolean hasNegative = c.stream().anyMatch(a -> a < 0);
        System.out.println(hasNegative ? -1 : c.size());
        
        scanner.close();
    }
}
// <END-OF-CODE>
