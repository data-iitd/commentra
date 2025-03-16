import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Define possible input methods: clipboard, file, key
        List<String> inputMethods = Arrays.asList("clipboard", "file", "key");
        // Indicate which input method to use, starting with 'clipboard'
        int usingMethod = 0;
        String inputMethod = inputMethods.get(usingMethod);
        // Define a lambda function to take integer inputs in space-separated format
        Scanner sc = new Scanner(System.in);
        // Define a modulo value
        final int mod = 1000000007;

        // Main function for base case
        void main_b() {
            // Take input string
            String s = sc.nextLine();
            // Initialize pp and na to 0
            int pp = 0;
            int na = 0;
            // Iterate over the string in reverse order
            for (int i = s.length() - 1; i >= 0; i--) {
                char c = s.charAt(i);
                int cc = na + Character.getNumericValue(c);
                na = 0;
                // If the sum is less than or equal to 4, add to pp
                if (cc <= 4) {
                    pp += cc;
                } else {
                    na = 1;
                    // If it's the last digit, add 1 to pp
                    if (i == 0) {
                        pp += 1;
                    }
                    pp += 10 - cc;
                }
            }
            // Print the result
            System.out.println(pp);
        }

        // Main function for general case
        int main() {
            String s = sc.nextLine();
            int pmin = 1000;
            int mmin = 0;
            s = "0" + s;
            // Iterate over the string in reverse order
            for (char c : s.toCharArray()) {
                int v = Character.getNumericValue(c);
                int npmin = Math.min(pmin + 10 - (v + 1), mmin + 10 - v);
                int nmmin = Math.min(pmin + v + 1, mmin + v);
                pmin = npmin;
                mmin = nmmin;
            }
            // Return the minimum of pmin and mmin
            return Math.min(pmin, mmin);
        }

        // Check if the script is running in test mode
        boolean isTest = false;
        // Function to print values if in test mode
        void pa(int v) {
            if (isTest) {
                System.out.println(v);
            }
        }

        // Function to read input from clipboard if running on iOS
        String input_clipboard() {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

        // Main execution block
        if (System.getProperty("os.name").toLowerCase().contains("ios")) {
            if (inputMethod.equals(inputMethods.get(0))) {
                String inputText = input_clipboard();
                Scanner sc2 = new Scanner(inputText);
                sc = sc2;
            } else if (inputMethod.equals(inputMethods.get(1))) {
                sc = new Scanner(new File("inputFile.txt"));
            }
            isTest = true;
        }

        int ret = main();
        if (ret != 0) {
            System.out.println(ret);
        }
    }
}
