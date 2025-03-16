import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        System.out.println(countOccurrences(s, "ABC"));
    }

    private static int countOccurrences(String s, String sub) {
        int count = 0;
        int index = 0;
        while ((index = s.indexOf(sub, index)) != -1) {
            count++;
            index += sub.length();
        }
        return count;
    }
}

// <END-OF-CODE>
