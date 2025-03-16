public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String str1 = scanner.next();
        String str2 = scanner.next();

        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();

        java.util.Arrays.sort(arr1);
        java.util.Arrays.sort(arr2);

        int loop = arr1.length > arr2.length ? arr2.length : arr1.length;
        boolean flag = false;

        for (int i = 0; loop > i; i++) {
            char ch1 = arr1[i];
            char ch2 = arr2[i];

            if (ch1 == ch2) {
                if (loop == i + 1 && arr1.length < arr2.length) {
                    flag = true;
                    break;
                } else {
                    continue;
                }
            } else {
                if (ch2 > ch1) {
                    flag = true;
                    break;
                } else {
                    break;
                }
            }
        }

        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
