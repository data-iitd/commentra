public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (s.substring(i + 1).indexOf(c) != -1) {
                System.out.println("no");
                return;
            }
        }

        System.out.println("yes");
    }
}
