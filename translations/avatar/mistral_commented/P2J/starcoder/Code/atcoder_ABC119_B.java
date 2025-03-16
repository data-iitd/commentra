// Ask the user for the number of inputs
int N = Integer.parseInt(System.console().readLine());

// Create a list 'x' of size 'N' using a list comprehension
List<Double> x = new ArrayList<>();
for (int i = 0; i < N; i++) {
    String s = System.console().readLine();
    s = s.replace("JPY", "* 1.0").replace("BTC", "* 380000.0");
    x.add(Double.parseDouble(s));
}

// Print the sum of all the elements in the list 'x'
System.out.println(x.stream().mapToDouble(Double::doubleValue).sum());

