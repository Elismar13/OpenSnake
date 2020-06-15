#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include <time.h>


class Food {
    private:
        int  foodX, foodY;
        bool onScreen;


    public: 
        Food();

        void setFoodX(int food_X);

        int getFoodX();

        void setFoodY(int food_Y);

        int getFoodY();        

        void setCollider(bool collider);

        bool getCollider();

        void foodController();
};

#endif