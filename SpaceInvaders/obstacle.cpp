#include "obstacle.hpp"
std:: vector<std::vector<int>> Obstacle:: grid = {// for the obstacle, 1's will notate filled space while 0's are ntohing
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}
    };
Obstacle::Obstacle(Vector2 position)
{
    this -> position = position;

    

    for(unsigned int row = 0; row < grid.size(); row++){
        for(unsigned int column = 0; column < grid[0].size(); column++){
            if(grid[row][column] == 1){
                float pos_x = position.x + column*3;//calculates position of block baes on column
                float pos_y = position.y + row*3;// and row of the grid (multiplied by three because each block is 3 pixels)
                Block block = Block{{pos_x,pos_y}};
                blocks.push_back(block);
            }
        }
    }
}

void Obstacle::Draw(){
    for(auto& block: blocks){
        block.Draw();
    }
}