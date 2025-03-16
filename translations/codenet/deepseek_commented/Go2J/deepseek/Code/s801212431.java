public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String S = scanner.next();

        // Initialize counters for '0's and '1's
        int l0 = 0, l1 = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '0') {
                l0++;
            } else {
                l1++;
            }
        }
        System.out.println(2 * Math.min(l0, l1));
    }
}
