#include "Food.hpp"

Food :: Food() {
    foodController();
}

void Food :: setFoodX(int food_X) {
    this->foodX = food_X;
}

int Food :: getFoodX() {
    return this->foodX;
}

void Food :: setFoodY(int food_Y) {
    this->foodY = food_Y;
}

int Food :: getFoodY() {
    return this->foodY;
}

void Food :: setCollider(bool collider) {
    this->onScreen = collider;
}

bool Food :: getCollider() {
    return this->onScreen;
}

void Food :: foodController() {

    srand(time(NULL));

	if(!this->getCollider()) {
		int foodPostionX = (rand() % 38) + 1;
		int foodPostionY = (rand() % 38) + 1;

        this->setFoodX(foodPostionX);
        this->setFoodY(foodPostionY);

		this->setCollider(true);
	}
}