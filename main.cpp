#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    int windowWidth{1920};
    int windowHeight{1080};
    InitWindow(windowWidth, windowHeight, "RPG Open World");
    // Worid
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    // player
    Character player;
    player.SetScreenPos(windowWidth, windowHeight);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        // Draw World
        mapPos =  Vector2Scale(player.GetWorldPosition(), -1);
        DrawTextureEx(map, mapPos, 0, 4, WHITE);
        player.Tick(GetFrameTime());
        EndDrawing();
    }
}