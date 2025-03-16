import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static String s() {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first line (not used)
        String[] input = scanner.nextLine().split(" ");
        int[] a = new int[input.length];
        
        for (int i = 0; i < input.length; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        
        Arrays.sort(a);
        
        for (int i = 1; i < a.length; i++) {
            if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
                return "YES";
            }
        }
        return "NO";
    }

    public static void main(String[] args) {
        System.out.println(s());
    }
}

// <END-OF-CODE>
