import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        String[] m = scanner.nextLine().split(" ");
        Set<String> uniqueElements = new HashSet<>();
        for (String s : m) {
            uniqueElements.add(s);
        }
        boolean possible = true;
        for (String s : uniqueElements) {
            if (countOccurrences(s, m) >= n / 2 + 1) {
                possible = false;
                break;
            }
        }
        System.out.println(possible ? "YES" : "NO");
    }

    private static int countOccurrences(String s, String[] array) {
        int count = 0;
        for (String str : array) {
            if (str.equals(s)) {
                count++;
            }
        }
        return count;
    }
}
