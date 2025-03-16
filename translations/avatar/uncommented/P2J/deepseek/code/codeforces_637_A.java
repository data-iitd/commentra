import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] s = scanner.nextLine().split(" ");
        Map<String, Integer> w = new HashMap<>();
        for (String word : s) {
            w.put(word, w.getOrDefault(word, 0) + 1);
        }
        String[] reversedS = new StringBuilder(scanner.nextLine()).reverse().toString().split(" ");
        int c = -1, a = 0;
        for (String i : w.keySet()) {
            if (w.get(i) == Collections.max(w.values())) {
                if (getIndex(reversedS, i) > c) {
                    a = i;
                    c = getIndex(reversedS, i);
                }
            }
        }
        System.out.println(a);
    }

    private static int getIndex(String[] array, String value) {
        for (int i = 0; i < array.length; i++) {
            if (array[i].equals(value)) {
                return i;
            }
        }
        return -1;
    }
}
