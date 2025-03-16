import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;
        while (counter < a.size()) {
            counterTurns++;
            for (int i = 0; i < a.size(); i++) {
                if (a.get(i) != -1 && a.get(i) <= counter) {
                    counter++;
                    a.set(i, -1);
                }
            }
            // Reverse the list
            List<Integer> reversed = new ArrayList<>();
            for (int i = a.size() - 1; i >= 0; i--) {
                if (a.get(i) != -1) {
                    reversed.add(a.get(i));
                }
            }
            a = reversed;
        }
        System.out.println(counterTurns);
    }
}
