def log2(n):
    if n == 1:
        return 0
    else:
        return log2(n // 2) + 1

def miniMax(depth, isMaximizer, index, verbose, scores, height):
    if depth == height:
        return scores[index]

    score1 = miniMax(depth + 1, not isMaximizer, index * 2, verbose, scores, height)
    score2 = miniMax(depth + 1, not isMaximizer, index * 2 + 1, verbose, scores, height)

    if isMaximizer:
        bestScore = max(score1, score2)
    else:
        bestScore = min(score1, score2)

    if verbose:
        print(f"From {score1} and {score2}, {'Maximizer' if isMaximizer else 'Minimizer'} chooses {bestScore}")

    return bestScore

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    numLeafNodes = int(data[0])

    if (numLeafNodes & (numLeafNodes - 1)) != 0:
        print("Error: The number of leaf nodes must be a power of 2.")
        return

    scores = [int(data[i + 1]) for i in range(numLeafNodes)]
    height = log2(numLeafNodes)

    isMaximizer = data[numLeafNodes + 1] == 'True'
    verbose = True

    bestScore = miniMax(0, isMaximizer, 0, verbose, scores, height)

    print(scores)
    print("The best score for", "Maximizer" if isMaximizer else "Minimizer", "is", bestScore)

main()
