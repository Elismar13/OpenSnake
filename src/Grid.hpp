#ifndef GAME_HPP
#define GAME_HPP

class Grid {
    private:
        int gridX, gridY;

    public:
        //Grid();

        void initGrid(int x, int y);

        void gridUnit(int x, int y, bool isBorder);

        void drawGrid();
};

#endif


