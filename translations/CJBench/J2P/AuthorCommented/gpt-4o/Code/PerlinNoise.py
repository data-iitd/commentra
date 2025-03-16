import random

def generate_main(width, height, octave_count, persistence, seed):
    base = [[random.random() for _ in range(height)] for _ in range(width)]
    perlin_noise = [[0.0 for _ in range(height)] for _ in range(width)]
    noise_layers = []

    random.seed(seed)

    # Calculate octaves with different roughness
    for octave in range(octave_count):
        noise_layers.append(generate_main_layer(base, width, height, octave))

    amplitude = 1.0
    total_amplitude = 0.0

    # Calculate perlin noise by blending each layer together with specific persistence
    for octave in range(octave_count - 1, -1, -1):
        amplitude *= persistence
        total_amplitude += amplitude

        for x in range(width):
            for y in range(height):
                perlin_noise[x][y] += noise_layers[octave][x][y] * amplitude

    # Normalize values so that they stay between 0..1
    for x in range(width):
        for y in range(height):
            perlin_noise[x][y] /= total_amplitude

    return perlin_noise

def generate_main_layer(base, width, height, octave):
    perlin_noise_layer = [[0.0 for _ in range(height)] for _ in range(width)]

    # Calculate period (wavelength) for different shapes
    period = 1 << octave  # 2^k
    frequency = 1.0 / period  # 1/2^k

    for x in range(width):
        # Calculates the horizontal sampling indices
        x0 = (x // period) * period
        x1 = (x0 + period) % width
        horizontal_blend = (x - x0) * frequency

        for y in range(height):
            # Calculates the vertical sampling indices
            y0 = (y // period) * period
            y1 = (y0 + period) % height
            vertical_blend = (y - y0) * frequency

            # Blend top corners
            top = interpolate(base[x0][y0], base[x1][y0], horizontal_blend)

            # Blend bottom corners
            bottom = interpolate(base[x0][y1], base[x1][y1], horizontal_blend)

            # Blend top and bottom interpolation to get the final blend value for this cell
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
    length = len(chars)
    step = 1.0 / length

    # Output based on charset
    for x in range(width):
        for y in range(height):
            value = step
            noise_value = perlin_noise[x][y]

            for c in chars:
                if noise_value <= value:
                    print(c, end='')
                    break
                value += step
        print()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
