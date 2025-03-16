import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        List<Integer> lista = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            lista.add(scanner.nextInt());
        }
        
        List<Integer> listb = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            listb.add(scanner.nextInt());
        }
        
        for (int k = 0; k < n; k++) {
            if (lista.contains(k + 1)) {
                System.out.print(1 + " ");
            } else {
                System.out.print(2 + " ");
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
