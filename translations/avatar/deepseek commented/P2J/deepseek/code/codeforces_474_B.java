import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> L = new ArrayList<>();

        // Take the first input from the user
        String[] firstInput = scanner.nextLine().split(" ");
        int r = 1;

        // Process the first input
        for (String k : firstInput) {
            L.add(r, k);
            r++;
        }

        // Take the second input from the user
        String[] secondInput = scanner.nextLine().split(" ");

        // Process the second input
        for (String j : secondInput) {
            int index = Integer.parseInt(j) - 1;
            System.out.println(L.get(index));
        }
    }
}
