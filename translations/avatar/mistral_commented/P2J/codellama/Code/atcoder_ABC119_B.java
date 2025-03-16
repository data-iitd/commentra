// Ask the user for the number of inputs
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Create a list 'x' of size 'N' using a for loop
double[] x = new double[N];
for (int i = 0; i < N; i++) {
    x[i] = sc.nextDouble();
}

// Print the sum of all the elements in the list 'x'
System.out.println(Arrays.stream(x).sum());

