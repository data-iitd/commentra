
public class Main {

    public static void main(String[] args) {

        // Read the integer K from the standard input
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();

        // Read a string S from the standard input
        String S = scanner.next();

        // Check if the length of the string S is less than or equal to K
        if (S.length() <= K) {

            // If the condition is true, return the string S
            System.out.println(S);

        } else {

            // If the condition is false, return a slice of the string S
            // from the beginning to the index K, followed by three dots '...'
            System.out.println(S.substring(0, K) + "...");

        }

    }

}

