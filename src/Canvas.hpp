#ifndef CANVAS_HPP
#define CANVAS_HPP

#define RESOLUCTION_X 600
#define RESOLUCTION_Y 640
#define GAME_FPS 10

void renderScene(void);

void reshapeWindow(int widht, int height);

void gridInit();

void frameTime(int time);

void canvasInit(int argc, char *argv[]);


#endif