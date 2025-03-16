public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        int n = 0;
        for (char c : s.toCharArray()) {
            if (c == 'o') {
                n++;
            }
        }

        System.out.println(700 + n * 100);
    }
}
