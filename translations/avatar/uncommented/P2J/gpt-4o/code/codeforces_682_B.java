import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        List<Integer> l = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextInt());
        }
        
        Collections.sort(l);
        int c = 0;
        
        for (int i : l) {
            if (i > c) {
                c++;
            }
        }
        
        System.out.println(c + 1);
        scanner.close();
    }
}

// <END-OF-CODE>
