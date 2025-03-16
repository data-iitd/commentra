// Read the number of currency inputs from the user
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Create a list of converted currency values
// For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
double[] x = new double[N];
for (int i = 0; i < N; i++) {
    x[i] = Double.parseDouble(sc.next().replace("JPY", "* 1.0").replace("BTC", "* 380000.0"));
}

// Calculate and print the total sum of the converted currency values
double sum = 0;
for (int i = 0; i < N; i++) {
    sum += x[i];
}
System.out.println(sum);

