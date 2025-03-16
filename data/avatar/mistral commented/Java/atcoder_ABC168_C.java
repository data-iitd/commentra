import java.util.*;          // Importing the utility class Scanner from java.util package
import java.math.BigDecimal; // Importing the BigDecimal class from java.math package

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console

        int A = sc.nextInt();             // Reading the first integer value A from the console
        int B = sc.nextInt();             // Reading the second integer value B from the console
        int H = sc.nextInt();             // Reading the integer value H from the console
        int M = sc.nextInt();             // Reading the integer value M from the console

        // Creating BigDecimal objects for the input values
        BigDecimal AA = new BigDecimal(A);
        BigDecimal BB = new BigDecimal(B);
        BigDecimal HH = new BigDecimal(H);
        BigDecimal MM = new BigDecimal(M);

        // Declaring and initializing variables for intermediate calculations
        BigDecimal ans2;
        BigDecimal kaku;
        BigDecimal mkaku;
        BigDecimal hkaku;
        BigDecimal AA2;
        BigDecimal BB2;
        BigDecimal CC;
        BigDecimal DD;
        double dkaku;
        double dans2;

        // Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
        mkaku = MM.multiply(BigDecimal.valueOf(6));
        hkaku = HH.multiply(BigDecimal.valueOf(30)).add(MM.divide(BigDecimal.valueOf(2)));

        // Calculating kaku (difference between mkaku and hkaku)
        kaku = mkaku.subtract(hkaku);

        // Calculating the absolute value of kaku in radians
        dkaku = Math.abs(Math.toRadians(kaku.doubleValue()));

        // Calculating the squared values of A and B
        AA2 = AA.multiply(AA);
        BB2 = BB.multiply(BB);

        // Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
        CC = AA2.add(BB2);
        DD = BigDecimal.valueOf(Math.cos(dkaku)).multiply(AA).multiply(BB);

        // Calculating the answer (square root of the difference between CC and DD)
        ans2 = CC.subtract(DD);
        dans2 = ans2.doubleValue();
        ans = Math.sqrt(dans2);

        // Printing the answer
        System.out.println(ans);
    }
}
