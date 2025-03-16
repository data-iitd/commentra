import random
import sys

def generate_main(width, height, octave_count, persistence, seed):
    base = [[0.0 for _ in range(height)] for _ in range(width)]
    perlin_noise = [[0.0 for _ in range(height)] for _ in range(width)]
    noise_layers = [None] * octave_count
    random.seed(seed)
    # Populate the base noise map with random values
    for x in range(width):
        for y in range(height):
            base[x][y] = random.random()
    # Generate each noise layer
    for octave in range(octave_count):
        noise_layers[octave] = generate_main_layer(base, width, height, octave)
    amplitude = 1.0
    total_amplitude = 0.0
    # Combine the noise layers with persistence
    for octave in range(octave_count - 1, -1, -1):
        amplitude *= persistence
        total_amplitude += amplitude
        for x in range(width):
            for y in range(height):
                perlin_noise[x][y] += noise_layers[octave][x][y] * amplitude
    # Normalize the Perlin noise
    for x in range(width):
        for y in range(height):
            perlin_noise[x][y] /= total_amplitude
    return perlin_noise

def generate_main_layer(base, width, height, octave):
    perlin_noise_layer = [[0.0 for _ in range(height)] for _ in range(width)]
    period = 1 << octave
    frequency = 1.0 / period
    # Interpolate between base values to generate the layer
    for x in range(width):
        x0 = (x // period) * period
        x1 = (x0 + period) % width
        horizontal_blend = (x - x0) * frequency
        for y in range(height):
            y0 = (y // period) * period
            y1 = (y0 + period) % height
            vertical_blend = (y - y0) * frequency
            top = interpolate(base[x0][y0], base[x1][y0], horizontal_blend)
            bottom = interpolate(base[x0][y1], base[x1][y1], horizontal_blend)
            perlin_noise_layer[x][y] = interpolate(top, bottom, vertical_blend)
    return perlin_noise_layer

def interpolate(a, b, alpha):
    return a * (1 - alpha) + alpha * b

def main():
    width = int(input())
    height = int(input())
    octave_count = int(input())
    persistence = float(input())
    seed = int(input())
    charset = input()
    perlin_noise = generate_main(width, height, octave_count, persistence, seed)
    chars = list(charset)
    step = 1.0 / len(chars)
    # Map the Perlin noise values to characters
    for x in range(width):
        for y in range(height):
            value = 0.0
            noise_value = perlin_noise[x][y]
            for i, c in enumerate(chars):
                if noise_value <= value + step * (i + 1):
                    sys.stdout.write(c)
                    break
                value += step
        sys.stdout.write('\n')

if __name__ == "__main__":
    main()
