#include <stdio.h>
#include <stdbool.h>

#define MAX_MOVES 1000

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position positions[MAX_MOVES];
    int size;
} Record;

void initialize_record(Record *record) {
    record->x = 0;
    record->y = 0;
    record->size = 1;
    record->positions[0] = (Position){0, 0};
}

bool is_bug(Record *record) {
    for (int i = 0; i < record->size; i++) {
        for (int j = i + 1; j < record->size; j++) {
            if (record->positions[i].x == record->positions[j].x && record->positions[i].y == record->positions[j].y) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    Record record;
    initialize_record(&record);
    char moves[MAX_MOVES];
    scanf("%s", moves);

    for (int i = 0; moves[i] != '\0'; i++) {
        char move = moves[i];
        int dx = 0, dy = 0;

        switch (move) {
            case 'L': dx = 0; dy = -1; break;
            case 'R': dx = 0; dy = 1; break;
            case 'U': dx = 1; dy = 0; break;
            case 'D': dx = -1; dy = 0; break;
        }

        record.x += dx;
        record.y += dy;
        record.positions[record.size++] = (Position){record.x, record.y};

        if (is_bug(&record)) {
            printf("BUG\n");
            return 0;
        }
    }

    printf("OK\n");
    return 0;
}
