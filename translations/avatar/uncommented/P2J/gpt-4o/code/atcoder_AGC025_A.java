import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();
        List<String> a = Arrays.asList("10", "100", "1000", "10000", "100000");
        
        int newSum = 0;
        for (char c : n.toCharArray()) {
            newSum += Character.getNumericValue(c);
        }
        
        if (a.contains(n)) {
            System.out.println(10);
        } else {
            System.out.println(newSum);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
