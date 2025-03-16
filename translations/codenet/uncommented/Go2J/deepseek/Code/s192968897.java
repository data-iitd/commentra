public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.next();
        int l = s.length();
        String ans = "AC";
        if (s.charAt(0) != 'A') {
            ans = "WA";
        }
        int cnt = 0;
        for (int i = 1; i < l; i++) {
            if (Character.isUpperCase(s.charAt(i))) {
                if (i == 1 || i == l - 1 || s.charAt(i) != 'C') {
                    ans = "WA";
                }
                cnt++;
            }
        }
        if (cnt != 1) {
            ans = "WA";
        }
        System.out.println(ans);
    }
}
