public class Main {
    public static void main(String[] args) {
        // Read an integer input K from the user
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();
        
        // Read a string input S from the user
        String S = scanner.next();
        
        // Check if the length of the string S is less than or equal to K
        if (S.length() <= K) {
            // If true, return the original string S
            System.out.println(S);
        } else {
            // If the length of S is greater than K, return the first K characters followed by '...'
            System.out.println(S.substring(0, K) + "...");
        }
    }
}
