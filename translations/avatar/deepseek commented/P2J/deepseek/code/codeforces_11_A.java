import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        List<Integer> x = new ArrayList<>();
        int m = 0;
        int q = 0;
        
        scanner.nextLine(); // Consume newline left-over
        String[] xStr = scanner.nextLine().split(" ");
        
        for (String str : xStr) {
            x.add(Integer.parseInt(str));
        }
        
        for (int a = 0; a < x.size() - 1; a++) {
            if (x.get(a) >= x.get(a + 1)) {
                q = (int) Math.ceil((double) (x.get(a) - x.get(a + 1)) / d);
                m += q;
                x.set(a + 1, x.get(a + 1) + q * d);
            }
        }
        
        System.out.println(m);
    }
}
