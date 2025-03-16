import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        
        int max = 0, cnt = 0;
        for (char sc : str.toCharArray()) {
            if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
                cnt++;
            } else {
                cnt = 0;
            }
            max = Math.max(max, cnt);
        }
        
        System.out.println(max);
        scanner.close();
    }
}

// <END-OF-CODE>
