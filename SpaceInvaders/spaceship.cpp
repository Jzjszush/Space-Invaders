#include "spaceship.hpp"

Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth()-image.width)/2;//sets the x and y position to same place each game
    position.y = GetScreenHeight() -image.height-100;
    lastFireTime = 0.0;
}

Spaceship::~Spaceship(){
    UnloadTexture(image);//gets rid of the image
}
void Spaceship::Draw(){
    DrawTextureV(image,position, WHITE);//draws the spaceship
}

void Spaceship::MoveLeft(){//moves spaceship left 7 pixels
    position.x -= 7;
    if(position.x<25){//makes sure the spaceship stays in the bounds
        position.x=25;
    }
}
void Spaceship::MoveRight(){//moves spaceship right 7 pixels
    position.x += 7;
    if(position.x> GetScreenWidth()-image.width-25){//makes sure the spaceship stays in the bounds
        position.x = GetScreenWidth()- image.width-25;
    }

}

void Spaceship::FireLaser()
{
    if(GetTime()- lastFireTime >= 0.35){
    lasers.push_back(Laser({position.x+image.width/2 - 2,position.y} ,-6));//creates laser object when the user fires and puts it in the center of the ship
    lastFireTime = GetTime();
    }
}

Rectangle Spaceship::getRect()
{
    return{position.x,position.y,float(image.width),float(image.height)};
}

void Spaceship::Reset()
{
    position.x = (GetScreenWidth()-image.width)/2.0f;//sets the x and y position to same place each game
    position.y = GetScreenHeight() -image.height-100;
    lasers.clear();
}
