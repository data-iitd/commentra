public class HeightHistogram {
    public static void main(String[] args) {
        // Declare variables
        int n, fd[] = new int[6]; // n: number of heights, fd: array to store counts
        double height; // height: variable to store each height input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the number of heights
        n = scanner.nextInt();
        
        // Loop to read each height and categorize it
        while(n-- > 0){
            height = scanner.nextDouble();
            if(height >= 185.0) fd[5]++;
            else if(height >= 180.0) fd[4]++;
            else if(height >= 175.0) fd[3]++;
            else if(height >= 170.0) fd[2]++;
            else if(height >= 165.0) fd[1]++;
            else fd[0]++;
        }

        // Loop to print the histogram
        for(int i = 0; i < 6; i++){
            System.out.print((i + 1) + ":");
            for(int j = 0; j < fd[i]; j++)
                System.out.print('*');
            System.out.println();
        }
    }
}
