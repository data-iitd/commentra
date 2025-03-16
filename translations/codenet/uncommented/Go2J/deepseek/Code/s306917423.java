public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();
        int ans = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
