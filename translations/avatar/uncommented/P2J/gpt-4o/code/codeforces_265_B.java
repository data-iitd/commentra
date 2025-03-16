import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        List<Integer> l = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            l.add(Integer.parseInt(scanner.nextLine()));
        }
        
        long ans = n - 1;
        int last = 0;
        
        for (int i : l) {
            ans += Math.abs(last - i) + 1;
            last = i;
        }
        
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
