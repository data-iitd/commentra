public class Main {
    public static int min(int... nums) {
        int min = nums[0];
        for (int v : nums) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        System.out.println(min(n * a, b));
    }
}
