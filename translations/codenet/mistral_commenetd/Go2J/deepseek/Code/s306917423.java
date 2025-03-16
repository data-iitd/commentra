public class Main {
    public static void main(String[] args) {
        // Declaring a variable 's' to store the input string
        String s = null;

        // Reading the string input using Scanner
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        s = scanner.nextLine();

        // Declaring a variable 'ans' to store the answer
        int ans = 0;

        // Looping through each character 'c' in the string 's'
        for (char c : s.toCharArray()) {
            // Checking if the current character 'c' is equal to '1'
            if (c == '1') {
                // Incrementing the answer if the character is '1'
                ans++;
            }
        }

        // Printing the answer using System.out.println
        System.out.println(ans);

        // End of the code
    }
}
