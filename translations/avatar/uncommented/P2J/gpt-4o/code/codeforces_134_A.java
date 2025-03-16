import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        int[] w = new int[n];
        String[] input = scanner.nextLine().split(" ");
        
        int x = 0;
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(input[i]);
            x += w[i];
        }
        
        List<Integer> d = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if ((x - w[i]) / (n - 1) == w[i]) {
                d.add(i + 1);
            }
        }
        
        System.out.println(d.size());
        for (int i = 0; i < d.size(); i++) {
            System.out.print(d.get(i));
            if (i < d.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
        
        scanner.close();
    }
}
// <END-OF-CODE>
