public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline left-over
        String a = scanner.nextLine();
        String b = scanner.nextLine();
        String c = scanner.nextLine();
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (a.charAt(i) == b.charAt(i) && b.charAt(i) == c.charAt(i)) {
                // Do nothing
            } else if (a.charAt(i) == b.charAt(i) || b.charAt(i) == c.charAt(i) || a.charAt(i) == c.charAt(i)) {
                ans++;
            } else {
                ans += 2;
            }
        }
        
        System.out.println(ans);
    }
}
