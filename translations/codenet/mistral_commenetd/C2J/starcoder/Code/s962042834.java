
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b, n, x, y;
		int[][] suu = new int[17][17];
		int[][] kouji = new int[17][17];

		System.out.print("Enter the dimensions of the grid (width and height): ");
		a = sc.nextInt();
		b = sc.nextInt();

		while (a!= 0 && b!= 0) {
			System.out.print("Enter the number of obstacles in the grid: ");
			n = sc.nextInt();

			for (int i = 1; i <= a; i++) {
				for (int j = 1; j <= b; j++) {
					kouji[i][j] = 0;
				}
			}

			for (int i = 0; i < n; i++) {
				x = sc.nextInt();
				y = sc.nextInt();
				kouji[x][y] = 1;
			}

			for (int i = 1; i <= a; i++) {
				for (int j = 1; j <= b; j++) {
					if (kouji[i][j] == 1) {
						suu[i][j] = 0;
					} else {
						if (i == 1 && j == 1) {
							suu[i][j] = 1;
						} else {
							if (i == 1) {
								suu[i][j] = suu[i][j - 1];
							} else if (j == 1) {
								suu[i][j] = suu[i - 1][j];
							} else {
								suu[i][j] = suu[i][j - 1] + suu[i - 1][j];
							}
						}
					}
				}
			}

			System.out.println("The number of unique paths in the grid is: " + suu[a][b]);

			System.out.print("Enter the dimensions of the next grid (width and height): ");
			a = sc.nextInt();
			b = sc.nextInt();
		}
	}
}

