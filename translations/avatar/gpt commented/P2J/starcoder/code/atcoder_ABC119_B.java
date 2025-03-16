// Read the number of currency inputs from the user
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Create a list of converted currency values
// For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
List<Float> x = new ArrayList<Float>();
for (int i = 0; i < N; i++) {
    String s = sc.next();
    s = s.replace("JPY", "* 1.0");
    s = s.replace("BTC", "* 380000.0");
    x.add(Float.parseFloat(s));
}

// Calculate and print the total sum of the converted currency values
System.out.println(x.stream().mapToDouble(Float::doubleValue).sum());

