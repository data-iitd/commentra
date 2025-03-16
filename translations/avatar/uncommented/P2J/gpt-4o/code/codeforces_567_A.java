import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int inp = Integer.parseInt(scanner.nextLine());
        List<Integer> lista = new ArrayList<>();
        
        String[] input = scanner.nextLine().split(" ");
        for (String x : input) {
            lista.add(Integer.parseInt(x));
        }
        
        for (int i = 0; i < lista.size(); i++) {
            if (i == 0) {
                System.out.print((lista.get(i + 1) - lista.get(i)) + " ");
                System.out.print((lista.get(lista.size() - 1) - lista.get(i)) + "\n");
                continue;
            } else if (i == lista.size() - 1) {
                System.out.print((lista.get(lista.size() - 1) - lista.get(lista.size() - 2)) + " ");
                System.out.print((lista.get(lista.size() - 1) - lista.get(0)) + "\n");
                continue;
            } else if (lista.get(i) - lista.get(i - 1) > lista.get(i + 1) - lista.get(i)) {
                System.out.print((lista.get(i + 1) - lista.get(i)) + " ");
            } else {
                System.out.print((lista.get(i) - lista.get(i - 1)) + " ");
            }
            if (lista.get(lista.size() - 1) - lista.get(i) > lista.get(i) - lista.get(0)) {
                System.out.print((lista.get(lista.size() - 1) - lista.get(i)) + "\n");
            } else {
                System.out.print((lista.get(i) - lista.get(0)) + "\n");
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
