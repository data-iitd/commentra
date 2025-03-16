// Read the number of problems (D) and the maximum score (G) from input
var D, G int
fmt.Scanf("%d %d", &D, &G)

// Read the problem data, each containing the number of problems and the score for that problem
PC := make([][2]int, D)
for i := 0; i < D; i++ {
    fmt.Scanf("%d %d", &PC[i][0], &PC[i][1])
}

// Initialize the answer to a large number (infinity)
ans := 1000000000

// Iterate through all possible combinations of problems (2^D combinations)
for i := 0; i < 1 << D; i++ {
    score := 0  // Initialize the current score
    problem := 0  // Initialize the count of problems solved

    // Calculate the score and number of problems solved for the current combination
    for j := 0; j < D; j++ {
        if i & (1 << j)!= 0 {  // Check if the j-th problem is included in the combination
            score += 100 * (j + 1) * PC[j][0] + PC[j][1]  // Update score based on the problem's data
            problem += PC[j][0]  // Update the number of problems solved

    // If the current score exceeds the maximum score (G), skip to the next combination
    if score > G {
        continue

    // Calculate the remaining score that can be achieved
    left := G - score

    // Check for each problem that is not included in the current combination
    for j := 0; j < D; j++ {
        if i & (1 << j)!= 0 {  // Skip if the problem is already included
            continue

        // If the remaining score is greater than the score that can be achieved with this problem, skip
        if left > 100 * (j + 1) * PC[j][0] + PC[j][1] {
            continue
        } else {
            // Calculate the minimum number of additional problems needed to reach the remaining score
            tmp := (left + (100 * (j + 1)) - 1) / (100 * (j + 1))
            // Update the answer with the minimum number of problems solved
            ans = min(ans, problem + min(tmp, PC[j][0]))

// Print the minimum number of problems solved to achieve the maximum score
fmt.Println(ans)

