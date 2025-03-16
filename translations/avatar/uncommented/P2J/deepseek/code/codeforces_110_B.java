public class LuckyString {
    public static void main(String[] args) {
        String LUCKY = "abcd";
        int n = Integer.parseInt(System.console().readLine());
        String s = "";
        for (int i = 0; i < n; i++) {
            s += LUCKY.charAt(i % 4);
        }
        System.out.println(s);
    }
}
