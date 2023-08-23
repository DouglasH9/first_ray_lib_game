#include <iostream>

#include "raylib.h"

int main() {
    //window dims
    int width{1000};
    int height{800};
    InitWindow(width, height, "Axe Game");

    //circle dims
    int circleX{500};
    int circleY{400};
    int circle_radius{25};
    //circle edges
    int l_circle_x{circleX - circle_radius};
    int r_circle_x{circleX + circle_radius};
    int t_circle_y{circleY - circle_radius};
    int b_circle_y{circleY + circle_radius};

    //axe dims
    int axe_x{300};
    int axe_y{0};
    int axe_length{50};
    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int t_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{10};

    SetTargetFPS(60);

    bool collided_with_axe =
            (b_axe_y >= t_circle_y) &&
            (t_axe_y <= b_circle_y) &&
            (l_axe_x <= r_circle_x) &&
            (r_axe_x >= l_circle_x);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);

        if (collided_with_axe) {
            DrawText("GAME OVER", 500, 400, 18, RED);
        } else {
            //update edges
            l_circle_x = circleX - circle_radius;
            r_circle_x = circleX + circle_radius;
            t_circle_y = circleY - circle_radius;
            b_circle_y = circleY + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            t_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            //update collided with axe
            collided_with_axe =
                    (b_axe_y >= t_circle_y) &&
                    (t_axe_y <= b_circle_y) &&
                    (l_axe_x <= r_circle_x) &&
                    (r_axe_x >= l_circle_x);

            DrawCircle(circleX, circleY, circle_radius, ORANGE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, PURPLE);

            axe_y += direction;
            if (axe_y > 750 || axe_y < 0) {
                direction = -direction;
            }

            //button map
            if (IsKeyDown(KEY_S) && circleY < height)
                circleY += 10;
            if (IsKeyDown(KEY_W) && circleY > 50)
                circleY -= 10;
            if (IsKeyDown(KEY_D) && circleX < width)
                circleX += 10;
            if (IsKeyDown(KEY_A) && circleX > 50)
                circleX -= 10;

        }

        EndDrawing();
    }

    return 0;
}
