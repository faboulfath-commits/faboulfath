#ifndef APP_H
#define APP_H

#include <raylib.h>

// Structure for Paddle
typedef struct Paddle {
    Vector2 position;
    Vector2 size;
    float speed;
} Paddle;

// Structure for Ball
typedef struct Ball {
    Vector2 position;
    Vector2 velocity;
    float radius;
} Ball;

// Structure to hold application state
typedef struct {
    int scorePlayer1;
    int scorePlayer2;
    Paddle paddle1;
    Paddle paddle2;
    Ball ball;
    bool gameOver;
} AppState;

// Function declarations
void InitApp(AppState *state);
void UpdateApp(AppState *state);
void DrawApp(AppState *state);
void UnloadApp(AppState *state);
void RunApp();

#endif // APP_H