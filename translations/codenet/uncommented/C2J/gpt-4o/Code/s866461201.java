import java.util.Scanner;

public class HeightFrequencyDistribution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        int[] fd = new int[6];
        double height;

        n = scanner.nextInt();
        while (n-- > 0) {
            height = scanner.nextDouble();
            if (height >= 185.0) fd[5]++;
            else if (height >= 180.0) fd[4]++;
            else if (height >= 175.0) fd[3]++;
            else if (height >= 170.0) fd[2]++;
            else if (height >= 165.0) fd[1]++;
            else fd[0]++;
        }

        for (int i = 0; i < 6; i++) {
            System.out.print((i + 1) + ":");
            for (int j = 0; j < fd[i]; j++) {
                System.out.print('*');
            }
            System.out.println();
        }
        scanner.close();
    }
}
// <END-OF-CODE>
