import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> L = new ArrayList<>();
        int r = 1;
        String[] inputs = scanner.nextLine().split(" ");
        for (String k : inputs) {
            int count = Integer.parseInt(k);
            for (int i = 0; i < count; i++) {
                L.add(r);
            }
            r++;
        }
        String[] queryInputs = scanner.nextLine().split(" ");
        for (String j : queryInputs) {
            int index = Integer.parseInt(j) - 1;
            System.out.println(L.get(index));
        }
    }
}
