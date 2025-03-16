
import random
import sys

# Generates the main Perlin noise map
def generateMain(width, height, octaveCount, persistence, seed):
    base = [[random.random() for y in range(height)] for x in range(width)]
    perlinNoise = [[0.0 for y in range(height)] for x in range(width)]
    noiseLayers = [[[0.0 for y in range(height)] for x in range(width)] for octave in range(octaveCount)]
    random.seed(seed)
    # Populate the base noise map with random values
    for x in range(width):
        for y in range(height):
            base[x][y] = random.random()
    # Generate each noise layer
    for octave in range(octaveCount):
        noiseLayers[octave] = generateMainLayer(base, width, height, octave)
    amplitude = 1.0
    totalAmplitude = 0.0
    # Combine the noise layers with persistence
    for octave in range(octaveCount - 1, -1, -1):
        amplitude *= persistence
        totalAmplitude += amplitude
        for x in range(width):
            for y in range(height):
                perlinNoise[x][y] += noiseLayers[octave][x][y] * amplitude
    # Normalize the Perlin noise
    for x in range(width):
        for y in range(height):
            perlinNoise[x][y] /= totalAmplitude
    return perlinNoise

# Generates a single layer of Perlin noise
def generateMainLayer(base, width, height, octave):
    perlinNoiseLayer = [[0.0 for y in range(height)] for x in range(width)]
    period = 1 << octave
    frequency = 1.0 / period
    # Interpolate between base values to generate the layer
    for x in range(width):
        x0 = (x / period) * period
        x1 = (x0 + period) % width
        horizintalBlend = (x - x0) * frequency
        for y in range(height):
            y0 = (y / period) * period
            y1 = (y0 + period) % height
            verticalBlend = (y - y0) * frequency
            top = interpolate(base[x0][y0], base[x1][y0], horizintalBlend)
            bottom = interpolate(base[x0][y1], base[x1][y1], horizintalBlend)
            perlinNoiseLayer[x][y] = interpolate(top, bottom, verticalBlend)
    return perlinNoiseLayer

# Interpolates between two values using a smooth step
def interpolate(a, b, alpha):
    return a * (1 - alpha) + alpha * b

# Main method to take user input and generate/print Perlin noise
if __name__ == "__main__":
    width = int(sys.stdin.readline())
    height = int(sys.stdin.readline())
    octaveCount = int(sys.stdin.readline())
    persistence = float(sys.stdin.readline())
    seed = int(sys.stdin.readline())
    charset = sys.stdin.readline()
    perlinNoise = generateMain(width, height, octaveCount, persistence, seed)
    chars = list(charset)
    length = len(chars)
    step = 1.0 / length
    # Map the Perlin noise values to characters
    for x in range(width):
        for y in range(height):
            value = step
            noiseValue = perlinNoise[x][y]
            for c in chars:
                if noiseValue <= value:
                    sys.stdout.write(c)
                    break
                value += step
        sys.stdout.write("\n")

