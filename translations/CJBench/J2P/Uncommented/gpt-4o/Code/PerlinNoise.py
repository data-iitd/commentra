import random

def generate_main(width, height, octave_count, persistence, seed):
    base = [[random.random() for _ in range(height)] for _ in range(width)]
    perlin_noise = [[0.0 for _ in range(height)] for _ in range(width)]
    noise_layers = [generate_main_layer(base, width, height, octave) for octave in range(octave_count)]
    
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
    perlin_noise_layer = [[0.0 for _ in range(height)] for _ in range(width)]
    period = 1 << octave
    frequency = 1.0 / period
    
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
    
    random.seed(seed)
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
                    print(c, end='')
                    break
                value += step
        print()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
