public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the value of n from the standard input

        int ac_count = 0; // Initialize an integer variable to count AC submissions
        int wa_count = 0; // Initialize an integer variable to count WA submissions
        int tle_count = 0; // Initialize an integer variable to count TLE submissions
        int re_count = 0; // Initialize an integer variable to count RE submissions

        // Loop through each test case
        for (int i = 0; i < n; ++i){
            String s = scanner.next(); // Read the result from the standard input
            if (s.equals("AC")){ // Check if the result is AC
                ac_count += 1; // Increment the AC count
            } else if (s.equals("WA")){ // Check if the result is WA
                wa_count += 1; // Increment the WA count
            } else if (s.equals("TLE")){ // Check if the result is TLE
                tle_count += 1; // Increment the TLE count
            } else if (s.equals("RE")){ // Check if the result is RE
                re_count += 1; // Increment the RE count
            }
        }

        // Print the counts of each result type
        System.out.println("AC x " + ac_count);
        System.out.println("WA x " + wa_count);
        System.out.println("TLE x " + tle_count);
        System.out.println("RE x " + re_count);
    }
}
