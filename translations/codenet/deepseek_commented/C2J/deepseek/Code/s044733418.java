public class SortArray {
    public static void main(String[] args) {
        int[] array = new int[10];
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt();
        }
        java.util.Arrays.sort(array);
        for (int i = 0; i < 3; i++) {
            System.out.println(array[i]);
        }
    }
}
