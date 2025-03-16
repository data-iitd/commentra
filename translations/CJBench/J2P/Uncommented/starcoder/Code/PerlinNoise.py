
import random
import sys

def generate_main(width, height, octave_count, persistence, seed):
    base = [[random.random() for y in range(height)] for x in range(width)]
    perlin_noise = [[0.0 for y in range(height)] for x in range(width)]
    noise_layers = []
    for octave in range(octave_count):
        noise_layers.append(generate_main_layer(base, width, height, octave))
    amplitude = 1.0
    total_amplitude = 0.0
    for octave in range(octave_count - 1, -1, -1):
        amplitude *= persistence
        total_amplitude += amplitude
        for x in range(width):
            for y in range(height):
                perlin_noise[x][y] += noise_layers[octave][x][y] * amplitude
    for x in range(width):
        for y in range(height):
            perlin_noise[x][y] /= total_amplitude
    return perlin_noise

def generate_main_layer(base, width, height, octave):
    perlin_noise_layer = [[0.0 for y in range(height)] for x in range(width)]
    period = 1 << octave
    frequency = 1.0 / period
    for x in range(width):
        x0 = (x / period) * period
        x1 = (x0 + period) % width
        horizintal_blend = (x - x0) * frequency
        for y in range(height):
            y0 = (y / period) * period
            y1 = (y0 + period) % height
            vertical_blend = (y - y0) * frequency
            top = interpolate(base[x0][y0], base[x1][y0], horizintal_blend)
            bottom = interpolate(base[x0][y1], base[x1][y1], horizintal_blend)
            perlin_noise_layer[x][y] = interpolate(top, bottom, vertical_blend)
    return perlin_noise_layer

def interpolate(a, b, alpha):
    return a * (1 - alpha) + alpha * b

def main():
    width = int(sys.stdin.readline())
    height = int(sys.stdin.readline())
    octave_count = int(sys.stdin.readline())
    persistence = float(sys.stdin.readline())
    seed = int(sys.stdin.readline())
    charset = sys.stdin.readline()
    perlin_noise = generate_main(width, height, octave_count, persistence, seed)
    chars = list(charset)
    length = len(chars)
    step = 1.0 / length
    for x in range(width):
        for y in range(height):
            value = step
            noise_value = perlin_noise[x][y]
            for c in chars:
                if noise_value <= value:
                    sys.stdout.write(c)
                    break
                value += step
        sys.stdout.write('\n')

if __name__ == '__main__':
    main()

# 