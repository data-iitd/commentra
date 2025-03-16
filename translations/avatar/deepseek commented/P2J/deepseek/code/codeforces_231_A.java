public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int c = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            String[] parts = scanner.nextLine().split(" ");
            for (String part : parts) {
                sum += Integer.parseInt(part);
            }
            if (sum > 1) {
                c++;
            }
        }
        System.out.println(c);
    }
}
