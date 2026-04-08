#include <stdio.h>
#include <raylib.h>
#include "app.h"

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pong Game");

    SetTargetFPS(60); // Set the game to run at 60 frames-per-second

    RunApp();

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}