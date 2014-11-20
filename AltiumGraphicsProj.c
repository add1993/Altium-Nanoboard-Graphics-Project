#include <stdio.h>
#include <graphics.h>
#include "devices.h"
#include <touchscreen.h>
#include <time.h>

graphics_t *graphics;
canvas_t *canvas;
touchscreen_t *touchscreen;
touchscreen_data_t pos, temp_pos;
int pos_x1, pos_y1, pos_x2, pos_y2;

char *str1 = "      DRAWING MODE";

char *cal1 = "Touch screen at marker";
char *cal2 = "Calibration done";
char *op1 = "1.  Circle";
char *op2 = "2.  Rectangle";
char *op3 = "3.  Free Drawing Mode";
char *op4 = "4.  Draw a line";
char *op5 = "5.  Basic Animation 1";
char *op6 = "6.  Basic Animation 2";
char *op7 = "7.  Ball Game Prototype";
char *op8 = "8.  Ball Game Final";
char *back = " GO BACK TO MENU";
char *txt1 = "Give Cordinates";



/*
 * This routine is called from the touchscreen_calibrate routine.
 * It writes instructions on the screen to tell the user what to do
 *
 * x = x-position in touchscreen coordinates
 * y = y-position in touchscreen coordinates
 * width = touchscreen width in touchscreen coordinates, 0 if calibration succeeded
 * height = touchscreen height in touchscreen coordinates, 0 if calibration succeeded
 * vp = void pointer, not used in this case
 */
void Delay (unsigned int Sec)
{
       clock_t ticks1 = clock(), ticks2 = ticks1;
       while ( ( ticks2/CLOCKS_PER_SEC - ticks1/CLOCKS_PER_SEC ) < Sec)
           ticks2 = clock();
}

void loop_delay()
{
    int i;
    for (i = 0; i < 100000; i++);
}

void animation_circle()
{
    int r = 0;
    graphics_fill_canvas(canvas, BLACK);

    for (r = 1; r <= 100; r++) {
        graphics_fill_circle(canvas, 120, 150, r, SILVER);
        loop_delay();
    }
    graphics_fill_canvas(canvas, BLACK);
    touchscreen_get_pos(touchscreen, &temp_pos);
    graphics_draw_string(canvas, 50, 250, back, &bitstreamverasans10, GREEN, FS_NONE);
    while(!(temp_pos.y >= 220 && temp_pos.y <= 280)) {
           touchscreen_get_pos(touchscreen, &temp_pos);
    }

    graphics_fill_canvas(canvas, BLACK);
}

void animation_ball()
{
    int i;
    graphics_fill_canvas(canvas, BLACK);
    int y = 150, inc = 1;
    for (int i = 0; i < 1000; i++) {

        graphics_fill_circle(canvas, 90, y, 50, RED);
        y += inc;
        loop_delay();
        if (y == 240) {
            inc = inc * (-1);
        } else if (y == 140) {
            inc = inc * (-1);
        }
        graphics_fill_canvas(canvas, BLACK);
    }

    touchscreen_get_pos(touchscreen, &temp_pos);
    graphics_draw_string(canvas, 50, 250, back, &bitstreamverasans10, GREEN, FS_NONE);
    while(!(temp_pos.y >= 220 && temp_pos.y <= 280)) {
           touchscreen_get_pos(touchscreen, &temp_pos);
    }

    graphics_fill_canvas(canvas, BLACK);
}

void animation_multiball()
{
    int i, j;
    graphics_fill_canvas(canvas, BLACK);
    int y[] = {150, 180, 200, 220, 225} , inc[] = {1, 1, 1, 1, 1}, x[] = {20, 50, 100, 130, 180}, r[] = {8, 15, 20, 22, 30};
    color_t color[] = {RED, GREEN, BLUE, YELLOW, WHITE};
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 5; j++) {
            graphics_fill_circle(canvas, x[j], y[j], r[j], color[j]);
            y[j] += inc[j];
            loop_delay();
                if (y[j] == 240) {
                inc[j] = inc[j] * (-1);
                } else if (y[j] == 140) {
                    inc[j] = inc[j] * (-1);
                }
        }
        graphics_fill_canvas(canvas, BLACK);
    }

    touchscreen_get_pos(touchscreen, &temp_pos);
    graphics_draw_string(canvas, 50, 250, back, &bitstreamverasans10, GREEN, FS_NONE);
    while(!(temp_pos.y >= 220 && temp_pos.y <= 280)) {
           touchscreen_get_pos(touchscreen, &temp_pos);
    }

    graphics_fill_canvas(canvas, BLACK);
}

void animation_ballgame()
{
    int i, x = 150, y = 150, incx = 1, incy = 1;
    graphics_fill_canvas(canvas, BLACK);

    for (i = 0; i < 1000; i++) {
         graphics_fill_circle(canvas, x, y, 20, RED);
          y += incy;
          x += incx;
          loop_delay();
          if (y == 240) {
             incy = incy * (-1);
          } else if (y== 140) {
             incy = incy * (-1);
          }
          if (x == 220) {
             incx = incx * (-1);
          } else if (x == 50) {
             incx = incx * (-1);
          }
          graphics_fill_canvas(canvas, BLACK);
    }
    touchscreen_get_pos(touchscreen, &temp_pos);
    graphics_draw_string(canvas, 50, 250, back, &bitstreamverasans10, GREEN, FS_NONE);
    while(!(temp_pos.y >= 220 && temp_pos.y <= 280)) {
           touchscreen_get_pos(touchscreen, &temp_pos);
    }

    graphics_fill_canvas(canvas, BLACK);
}

void animation_ballgamefinal()
{
    int i, x = 150, y = 150, incx = 1, incy = 1;
    graphics_fill_canvas(canvas, BLACK);

    for (i = 0; i < 1000; i++) {
         graphics_fill_circle(canvas, x, y, 20, RED);
          y += incy;
          x += incx;
          loop_delay();
          if (y == 300) {
             incy = incy * (-1);
          } else if (y== 100) {
             incy = incy * (-1);
          }
          if (x == 240) {
             incx = incx * (-1);
          } else if (x == 40) {
             incx = incx * (-1);
          }
          touchscreen_get_pos(touchscreen, &temp_pos);
          if (temp_pos.x >= x -20 && temp_pos.x <= x - 20 && temp_pos.y >= y - 20 && temp_pos.y <= y + 20) {
             incy = incy * (-1);
             incx = incx * (-1);
          }
          graphics_fill_canvas(canvas, BLACK);
    }
    touchscreen_get_pos(touchscreen, &temp_pos);
    graphics_draw_string(canvas, 50, 250, back, &bitstreamverasans10, GREEN, FS_NONE);
    while(!(temp_pos.y >= 220 && temp_pos.y <= 280)) {
           touchscreen_get_pos(touchscreen, &temp_pos);
    }

    graphics_fill_canvas(canvas, BLACK);
}

static void draw_mark(int x, int y, int width, int height, void *vp)
{
    char *str;

    int w, h;
    color_t fg_color, bg_color;

    w = graphics_get_width(graphics);
    h = graphics_get_height(graphics);
    fg_color = WHITE;
    bg_color = BLACK;

    //graphics_fill_canvas(canvas, bg_color);

    if (width && height)
    {

        x = x * w / width;
        y = y * h / height;

        graphics_draw_circle(canvas, x, y, 10, fg_color);
        graphics_draw_line(canvas, x - 15, y, x + 15, y, fg_color);
        graphics_draw_line(canvas, x, y - 15, x, y + 15, fg_color);
        str = cal1;
    }
    else
    {
        str = cal2;
    }
    x = (w - graphics_get_stringwidth(canvas, str, &bitstreamverasans10, FS_NONE)) / 2;
    y = (h - graphics_get_fontheight(canvas, &bitstreamverasans10)) / 2;

    graphics_draw_string(canvas, x, y, str, &bitstreamverasans10, WHITE, FS_NONE);
}


int main( void )
{
    bool valid;

    /* open graphics and touchscreen */
    touchscreen = touchscreen_open(TOUCHSCREEN_0);
    /* touchscreen_open already calls graphics_open, we also have to do it ourself because we need the pointer */
    graphics = graphics_open(GRAPHICS_0);
    canvas = graphics_get_visible_canvas(graphics);

    /* set which callback function is called from the calibrate routine */
    //touchscreen_set_callback(touchscreen, draw_mark, NULL);

    /* calibrate, repeat until calibrate is ready. Funtion returns true if ready */
    //touchscreen_set_rotation(touchscreen, 0);
    //graphics_set_rotation(graphics, 0);
    //while (!touchscreen_calibrate(touchscreen, 240, 320));

    /* set both graphics and touchscreen to the same rotation */
    touchscreen_set_rotation(touchscreen, 0);
    graphics_set_rotation(graphics, 0);

    /* clear screen */
    canvas_destroy(canvas);
    graphics_fill_canvas(canvas, BLACK);
    while (1)
    {
        valid = 0;
        do {
        graphics_draw_string(canvas, 20, 10, str1, &bitstreamverasans10, WHITE, FS_NONE); // Print Drawing Mode

        graphics_draw_string(canvas, 20, 45, op1, &bitstreamverasans10, YELLOW, FS_NONE);   // Print 1. Circle
        graphics_draw_string(canvas, 20, 80, op2, &bitstreamverasans10, YELLOW, FS_NONE);  // Print 2. Rectangle
        graphics_draw_string(canvas, 20, 115, op3, &bitstreamverasans10, YELLOW, FS_NONE);  // Print 3. Free Drawing Mode
        graphics_draw_string(canvas, 20, 150, op4, &bitstreamverasans10, YELLOW, FS_NONE);  // Print 3. Draw line
        graphics_draw_string(canvas, 20, 185, op5, &bitstreamverasans10, YELLOW, FS_NONE);   // Animation 1
        graphics_draw_string(canvas, 20, 220, op6, &bitstreamverasans10, YELLOW, FS_NONE);
        graphics_draw_string(canvas, 20, 255, op7, &bitstreamverasans10, YELLOW, FS_NONE);  // Ball game  Proto
        graphics_draw_string(canvas, 20, 290, op8, &bitstreamverasans10, YELLOW, FS_NONE);  // Ball game Final
        valid = touchscreen_get_pos(touchscreen, &pos);
        } while (valid != 1 && pos.y > 20);

        if(((pos.x) > 20 && (pos.x) < 150) && ((pos.y > 20) && (pos.y < 60))) {
                    graphics_fill_canvas(canvas, BLACK);
                     graphics_fill_circle(canvas, 100, 100, 50, SILVER);
                     graphics_draw_string(canvas, 50, 250, back, &bitstreamverasans10, GREEN, FS_NONE);
                     valid = touchscreen_get_pos(touchscreen, &temp_pos);
                     while(!(temp_pos.y >= 220 && temp_pos.y <= 280)) {
                          touchscreen_get_pos(touchscreen, &temp_pos);
                     }
                     graphics_fill_canvas(canvas, BLACK);
        } else if(((pos.x) > 20 && (pos.x) < 150) && ((pos.y > 65) && (pos.y < 100))) {
                    graphics_fill_canvas(canvas, BLACK);
                    graphics_fill_rect(canvas, 100, 100, 100, 150, FIREBRICK);
                     graphics_draw_string(canvas, 50, 250, back, &bitstreamverasans10, GREEN, FS_NONE);
                     valid = touchscreen_get_pos(touchscreen, &temp_pos);
                     while(!(temp_pos.y >= 220 && temp_pos.y <= 280)) {
                          touchscreen_get_pos(touchscreen, &temp_pos);
                     }
                     graphics_fill_canvas(canvas, BLACK);
        } else if (((pos.x) > 20 && (pos.x) < 150) && ((pos.y > 109) && (pos.y < 130))) {
                  graphics_fill_canvas(canvas, BLACK);
                  graphics_draw_string(canvas, 50, 250, back, &bitstreamverasans10, GREEN, FS_NONE);
                   while(!(temp_pos.y >= 220 && temp_pos.y <= 280)) {
                          valid = touchscreen_get_pos(touchscreen, &temp_pos);
                          if ( valid && temp_pos.pendown)      /* if result is valid and pendown is true, draw pixel at given location */
                          {
                            graphics_draw_pixel(canvas, temp_pos.x, temp_pos.y, WHITE);
                          }
                   }
                    graphics_fill_canvas(canvas, BLACK);
        }  else if (((pos.x) > 20 && (pos.x) < 150) && ((pos.y > 135) && (pos.y < 170))) {
                  graphics_fill_canvas(canvas, BLACK);
                  graphics_draw_string(canvas, 50, 250, back, &bitstreamverasans10, GREEN, FS_NONE);

                  graphics_draw_string(canvas, 20, 150, txt1, &bitstreamverasans10, YELLOW, FS_NONE);
                  Delay(5);
                  graphics_fill_canvas(canvas, BLACK);
                  touchscreen_get_pos(touchscreen, &temp_pos);
                  pos_x1 = temp_pos.x;
                  pos_y1 = temp_pos.y;
                  Delay(3);

                  graphics_draw_string(canvas, 20, 100, txt1, &bitstreamverasans10, YELLOW, FS_NONE);
                  Delay(3);
                  graphics_fill_canvas(canvas, BLACK);
                  touchscreen_get_pos(touchscreen, &temp_pos);
                  pos_x2 = temp_pos.x;
                  pos_y2 = temp_pos.y;

                  graphics_draw_line(canvas, pos_x1, pos_y1, pos_x2+1, pos_y2+1, BLUE);
                   while(!(temp_pos.y >= 220 && temp_pos.y <= 280)) {
                         touchscreen_get_pos(touchscreen, &temp_pos);

                   }
                    graphics_fill_canvas(canvas, BLACK);
        } else if (((pos.x) > 20 && (pos.x) < 150) && ((pos.y > 175) && (pos.y < 200))) {
            animation_circle();
        } else if (((pos.x) > 20 && (pos.x) < 150) && ((pos.y > 205) && (pos.y < 240))) {
            animation_multiball();
        } else if (((pos.x) > 20 && (pos.x) < 150) && ((pos.y > 245) && (pos.y < 260))) {
            animation_ballgame();
        }  else if (((pos.x) > 20 && (pos.x) < 150) && ((pos.y > 280) && (pos.y < 300))) {
            animation_ballgamefinal();
        }

    }
    }

