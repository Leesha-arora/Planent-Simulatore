#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12

// Queue for zodiac cycle
typedef struct {
    char signs[MAX][20];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;

    char zodiac[MAX][20] = {
        "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo",
        "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"
    };

    for(int i = 0; i < MAX; i++)
        strcpy(q->signs[i], zodiac[i]);

    q->front = 0;
    q->rear = MAX - 1;
}

char* movePlanet(Queue *q, int steps) {
    for(int i = 0; i < steps; i++) {
        char first[20];
        strcpy(first, q->signs[q->front]);

        for(int j = 0; j < MAX - 1; j++)
            strcpy(q->signs[j], q->signs[j+1]);

        strcpy(q->signs[q->rear], first);
    }

    return q->signs[q->front];
}

int main() {
    Queue zodiacQueue;
    initQueue(&zodiacQueue);

    int steps;
    printf("Enter number of steps to move planet: ");
    scanf("%d", &steps);

    char* result = movePlanet(&zodiacQueue, steps);
    printf("Planet moved to: %s\n", result);

    return 0;
}
