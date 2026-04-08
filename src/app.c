#include "app.h"
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void InitGame(AppState *state);
void UpdateGame(AppState *state);
void DrawGame(AppState *state);
void UnloadGame(AppState *state);

void InitGame(AppState *state) {
    state->scorePlayer1 = 0;
    state->scorePlayer2 = 0;
    state->gameOver = false;

    // Paddle 1 (left)
    state->paddle1.position = (Vector2){20, 250};
    state->paddle1.size = (Vector2){20, 100};
    state->paddle1.speed = 300;

    // Paddle 2 (right)
    state->paddle2.position = (Vector2){760, 250};
    state->paddle2.size = (Vector2){20, 100};
    state->paddle2.speed = 300;

    // Ball
    state->ball.position = (Vector2){400, 300};
    state->ball.velocity = (Vector2){200, 100};
    state->ball.radius = 10;

    srand(time(NULL));
}

void UpdateGame(AppState *state) {
    if (state->gameOver) return;

    // Paddle 1 controls (W/S)
    if (IsKeyDown(KEY_W) && state->paddle1.position.y > 0) {
        state->paddle1.position.y -= state->paddle1.speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_S) && state->paddle1.position.y < 500) {
        state->paddle1.position.y += state->paddle1.speed * GetFrameTime();
    }

    // Paddle 2 controls (Up/Down)
    if (IsKeyDown(KEY_UP) && state->paddle2.position.y > 0) {
        state->paddle2.position.y -= state->paddle2.speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_DOWN) && state->paddle2.position.y < 500) {
        state->paddle2.position.y += state->paddle2.speed * GetFrameTime();
    }

    // Ball movement
    state->ball.position.x += state->ball.velocity.x * GetFrameTime();
    state->ball.position.y += state->ball.velocity.y * GetFrameTime();

    // Ball collision with top/bottom
    if (state->ball.position.y <= 0 || state->ball.position.y >= 590) {
        state->ball.velocity.y = -state->ball.velocity.y;
    }

    // Ball collision with paddles
    Rectangle paddle1Rect = {state->paddle1.position.x, state->paddle1.position.y, state->paddle1.size.x, state->paddle1.size.y};
    Rectangle paddle2Rect = {state->paddle2.position.x, state->paddle2.position.y, state->paddle2.size.x, state->paddle2.size.y};
    if (CheckCollisionCircleRec(state->ball.position, state->ball.radius, paddle1Rect) ||
        CheckCollisionCircleRec(state->ball.position, state->ball.radius, paddle2Rect)) {
        state->ball.velocity.x = -state->ball.velocity.x;
    }

    // Score
    if (state->ball.position.x < 0) {
        state->scorePlayer2++;
        state->ball.position = (Vector2){400, 300};
        state->ball.velocity.x = -state->ball.velocity.x;
    }
    if (state->ball.position.x > 800) {
        state->scorePlayer1++;
        state->ball.position = (Vector2){400, 300};
        state->ball.velocity.x = -state->ball.velocity.x;
    }

    // Game over at 5 points
    if (state->scorePlayer1 >= 5 || state->scorePlayer2 >= 5) {
        state->gameOver = true;
    }
}

void DrawGame(AppState *state) {
    BeginDrawing();
    ClearBackground(BLACK);

    // Draw center line
    for (int i = 0; i < 600; i += 20) {
        DrawLine(400, i, 400, i + 10, WHITE);
    }

    // Draw paddles
    DrawRectangle(state->paddle1.position.x, state->paddle1.position.y, state->paddle1.size.x, state->paddle1.size.y, WHITE);
    DrawRectangle(state->paddle2.position.x, state->paddle2.position.y, state->paddle2.size.x, state->paddle2.size.y, WHITE);

    // Draw ball
    DrawCircle(state->ball.position.x, state->ball.position.y, state->ball.radius, WHITE);

    // Draw scores
    DrawText(TextFormat("%d", state->scorePlayer1), 350, 20, 40, WHITE);
    DrawText(TextFormat("%d", state->scorePlayer2), 430, 20, 40, WHITE);

    if (state->gameOver) {
        DrawText("Game Over!", 300, 250, 50, RED);
        DrawText("Press R to Restart", 280, 320, 25, WHITE);
        if (IsKeyPressed(KEY_R)) {
            InitGame(state);
        }
    }

    EndDrawing();
}

void UnloadGame(AppState *state) {
    // Cleanup if necessary
}

void RunApp() {
    AppState gameState;
    InitGame(&gameState);

    while (!WindowShouldClose()) {
        UpdateGame(&gameState);
        DrawGame(&gameState);
    }

    UnloadGame(&gameState);
}