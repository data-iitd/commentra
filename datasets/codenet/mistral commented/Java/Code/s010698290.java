//////////////////////////////////////////////////////
//                                                  //
//  For her who keeps the fire kindling in me...  //
//                                                  //
//////////////////////////////////////////////////////

import java.io.*;
import java.util.*;
import java.lang.Math;
import java.awt.Point;
import java.awt.geom.*;

public class Main {

    public static void main(String args[]) {
        try {
            // Initialize FastReader and BufferedWriter
            FastReader s = new FastReader();
            BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

            // Initialize variables
            int i, j;
            int m, n, t, max, k, x, y, min, correct_ans, num, num_penal;
            long a, b, sum;

            String str;

            // Read input for number of students (n) and number of queries (m)
            n = s.nextInt();
            m = s.nextInt();

            // Initialize arrays for solved students and penalties
            int penal[] = new int[n+1];
            boolean solved[] = new boolean[n+1];
            Arrays.fill(solved, false);

            // Process queries
            for(i=0; i<m; i++){
                // Read query type and student number
                num = s.nextInt();
                str = s.next();

                // If query type is 'A', mark the student as solved
                if(str.charAt(0) == 'A'){
                    solved[num] = true;
                }else
                    // If student is not solved, add penalty
                    if(solved[num] == false)
                        penal[num]++;
            }

            // Initialize variables for correct answers and total penalties
            correct_ans = 0;
            num_penal = 0;

            // Calculate correct answers and total penalties
            for(i=1; i<=n; i++){
                // If student is solved, increment correct answers and penalties
                if(solved[i] == true){
                    correct_ans++;
                    num_penal+=penal[i];
                }

            }

            // Write output to BufferedWriter
            w.write(correct_ans+" "+num_penal+"\n");
            w.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
