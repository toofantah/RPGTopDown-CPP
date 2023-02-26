#include "raylib.h"
#include "raymath.h"

int main()
{
    int windowWidth{1920};
    int windowHeight{1080};
    InitWindow(windowWidth, windowHeight, "RPG Open World");

    //Worid
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0,0.0};
    float speed{4.0};

    Texture2D player = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 playerPos{
        (float)windowWidth/2 - 4.0f * (0.5f * (float)player.width/6.0f),
        (float)windowHeight/2 - 4.0f * (0.5f * (float)player.height/6.0f),
    };
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        // float dT = GetFrameTime();
        //inputs
        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x-= 1.0;
        if(IsKeyDown(KEY_D)) direction.x+= 1.0;
        if(IsKeyDown(KEY_W)) direction.y-= 1.0;
        if(IsKeyDown(KEY_S)) direction.y+= 1.0;

        if(Vector2Length(direction) != 0)
          mapPos = Vector2Subtract(mapPos,Vector2Scale(Vector2Normalize(direction), speed));
        //Draw World
        DrawTextureEx(map,mapPos,0,4,WHITE);
        //Draw player
        Rectangle source {0.f,0.f, (float)player.width / 6.f, (float)player.height};
        Rectangle dest {playerPos.x, playerPos.y, 4.0f * (float) player.width / 6.f, 4.f * (float)player.height};
        DrawTexturePro(player, source, dest, Vector2{}, 0.0f, WHITE);

        EndDrawing();
    }
    
}