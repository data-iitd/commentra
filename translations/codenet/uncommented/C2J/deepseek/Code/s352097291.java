public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String c = scanner.next();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < c.length(); i++) {
            if (c.charAt(i) != 'B') {
                ans.append(c.charAt(i));
            } else {
                if (ans.length() > 0) {
                    ans.deleteCharAt(ans.length() - 1);
                }
            }
        }
        System.out.println(ans.toString());
    }
}
