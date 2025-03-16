import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        int a, t = 0, h = 0, lt, lh, tt, hh, l;
        Scanner scanner = new Scanner(System.in);
        
        a = scanner.nextInt();
        String taro, hana;

        // Loop through the number of games
        for (int i = 0; i < a; ++i) {
            // Read the names of Taro and Hana
            taro = scanner.next();
            hana = scanner.next();
            
            // Get the lengths of the names
            lt = taro.length();
            lh = hana.length();
            
            // Determine the maximum length of the names
            if (lt > lh) {
                l = lt;
            } else {
                l = lh;
            }
            
            // Initialize score counters for this round
            tt = 0;
            hh = 0;

            // Compare the names and update the scores
            if (taro.compareTo(hana) > 0) {
                t += 3;
            } else if (hana.compareTo(taro) > 0) {
                h += 3;
            } else if (hana.equals(taro)) {
                h += 1;
                t += 1;
            }
        }
        
        // Output the final scores
        System.out.println(t + " " + h);
        
        scanner.close();
    }
}

// <END-OF-CODE>
