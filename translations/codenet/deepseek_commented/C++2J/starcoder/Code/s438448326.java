import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Step 1: Reading Input
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int D = sc.nextInt();
        int E = sc.nextInt();
        int F = sc.nextInt();

        // Step 2: Initializing Variables
        int m1 = 0, m2 = 0;
        float maxD = 0.f;

        // Step 3: Nested Loops to Iterate Over Possible Combinations
        for (int i = 0; 100*A*i <= F; i++)
        {
            int mA = 100 * A*i;
            for (int j = 0; mA+100*B*j <= F; j++)
            {
                int mB = 100 * B*j;
                for (int k = 0; mA+mB+C*k <= F; k++)
                {
                    int mC = C*k;
                    for (int l = 0; mA+mB+mC+D*l <= F; l++)
                    {
                        int mD = D*l;
                        // Step 4: Calculating Density and Updating Results
                        if ((mA + mB)*E / 100 < mD + mC) {
                            break;
                        }
                        float d = (float)(mD + mC) / (float)(mA + mB + mC + mD);
                        if (d > maxD) {
                            m1 = mA + mB + mC + mD;
                            m2 = mC + mD;
                            maxD = d;
                        }
                    }
                }
            }
        }

        // Step 5: Handling Edge Cases
        if (m1 == 0) {
            m1 = 100 * A;
        }

        // Step 6: Output the Results
        System.out.println(m1 + " " + m2);
    }
}
