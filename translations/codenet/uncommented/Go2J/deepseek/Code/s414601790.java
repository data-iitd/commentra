public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();

        int max = 0;
        int cnt = 0;
        for (char r : s.toCharArray()) {
            if (r == 'I') {
                cnt++;
            } else {
                cnt--;
            }

            if (cnt > max) {
                max = cnt;
            }
        }

        System.out.println(max);
    }
}
