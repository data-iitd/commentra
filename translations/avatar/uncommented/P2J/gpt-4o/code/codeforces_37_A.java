import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());
        int[] l = new int[n];
        String[] input = scanner.nextLine().split(" ");
        
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(input[i]);
        }
        
        int high = 1;
        int tower = n;
        int maximum = 1;
        
        Arrays.sort(l);
        
        for (int i = 1; i < n; i++) {
            if (l[i] == l[i - 1]) {
                tower--;
                high++;
            } else {
                if (high > maximum) {
                    maximum = high;
                }
                high = 1;
            }
        }
        
        if (high > maximum) {
            maximum = high;
        }
        
        System.out.println(maximum + " " + tower);
        
        scanner.close();
    }
}
// <END-OF-CODE>
