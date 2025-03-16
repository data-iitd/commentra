public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String S = scanner.nextLine();
        for (int i = 2; i <= S.length(); i = i + 2) {
            if (S.substring(0, (S.length() - i) / 2).equals(S.substring((S.length() - i) / 2, S.length() - i))) {
                System.out.println(S.length() - i);
                break;
            }
        }
    }
}
