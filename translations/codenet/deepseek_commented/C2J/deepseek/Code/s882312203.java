public class NoDuplicateCharacters {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.next();

        for (int j = 0; j < s.length(); j++) {
            for (int i = 0; i < s.length(); i++) {
                if ((i != j) && (s.charAt(i) == s.charAt(j))) {
                    System.out.println("no");
                    return;
                }
            }
        }

        System.out.println("yes");
    }
}
