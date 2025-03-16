import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        String[] m = scanner.nextLine().split(" ");

        boolean possible = true;
        Set<String> uniqueChars = new HashSet<>();
        for (String s : m) {
            uniqueChars.add(s);
        }

        for (String i : uniqueChars) {
            if (countOccurrences(m, i) >= n / 2 + 1) {
                possible = false;
                break;
            }
        }

        System.out.println(possible ? "YES" : "NO");
    }

    private static int countOccurrences(String[] array, String value) {
        int count = 0;
        for (String s : array) {
            if (s.equals(value)) {
                count++;
            }
        }
        return count;
    }
}
