#include <raylib.h>
#include <stdlib.h>

int main(void)
{
    float width = 800, height = 800, vertShift, horizShift;
    InitWindow(width, height, "Xgraph");
    Font roboto = LoadFont("assets/Roboto-Regular.ttf");
    Vector2 origin, *line;
    int count;

    while (!WindowShouldClose())
    {
        width = GetScreenWidth();
        height = GetScreenHeight();
        origin.x = width/2 - 15;
        origin.y = height/2;
        horizShift = width/2;
        vertShift = height/2;

        line = (Vector2 *)malloc(sizeof(Vector2)*height);
        count = 0;
        for(int i = -vertShift; i < vertShift; i++)
        {
            (line + count)->x = (float) i + vertShift;
            (line + count)->y = (float) -(i * i) + horizShift;
            // (line + count)->y = (float) ((i * i * i) + (i * i) - (21 * i) + 45 + horizShift);
            count++;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawLine(width/2, 0, width/2, height, BLACK);
        DrawLine(0, height/2, width, height/2, BLACK);
        DrawSplineLinear(line, height, 3.0f, BLUE);
        DrawTextEx(roboto, "O", origin, 20, 0, BLACK);

        EndDrawing();
        free(line);
    }

    CloseWindow();

    return 0;
}
