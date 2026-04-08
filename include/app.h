#ifndef APP_H
#define APP_H

#include <raylib.h>

// Structure to hold application state
typedef struct {
    int score;
    int level;
    Vector2 position;
} AppState;

// Function declarations
void InitApp(AppState *state);
void UpdateApp(AppState *state);
void DrawApp(AppState *state);
void UnloadApp(AppState *state);

#endif // APP_H