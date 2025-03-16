#######
# Code
#######

# Define input variables
D, G = map(int, scanf("%d %d\n", &D, &G));

// Initialize list of problems with their respective capacities
int PC[D][2];

// Initialize variables for current iteration
int ans = 1000000000;

// Loop through all possible combinations of problems
for (int i = 0; i < (1 << D); i++) {
    // Initialize variables for current combination
    int score = 0;
    int problem = 0;

    // Calculate score for current combination
    for (int j = 0; j < D; j++) {
        // If problem j is included in current combination
        if (i & (1 << j)) {
            // Add score for problem j to the total score
            score += 100 * (j + 1) * PC[j][0] + PC[j][1];
            // Add capacity of problem j to the total problem
            problem += PC[j][0];
        }
    }

    // If score for current combination is greater than goal G, skip to next combination
    if (score > G) {
        continue;
    }

    // Calculate remaining capacity to be covered
    int left = G - score;

    // Loop through all problems and check if they can be included in the solution
    for (int j = 0; j < D; j++) {
        // If problem j is already included in current combination, skip it
        if (i & (1 << j)) {
            continue;
        }

        // Check if including problem j can cover the remaining capacity
        if (left > 100 * (j + 1) * PC[j][0] + PC[j][1]) {
            continue;
        } else {
            // Calculate the number of instances of problem j that can be included
            int tmp = (left + (100 * (j + 1) - 1) / (100 * (j + 1)));
            // Update the answer if including more instances of problem j results in a better solution
            ans = min(ans, problem + min(tmp, PC[j][0]));
        }
    }
}

// Print the answer
printf("%d\n", ans);

