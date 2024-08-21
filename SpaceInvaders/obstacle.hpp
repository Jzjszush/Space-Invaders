#pragma once
#include <vector>
#include "block.hpp"

//instead of using a sprite for the obstacle, we will use a grid to
//be able to show damage done 
class Obstacle{
    public:
        Obstacle(Vector2 position);
        void Draw();
        Vector2 position;;
        std::vector<Block> blocks;//this will be the grid for the obstacle
        static std:: vector<std::vector<int>> grid;//creates a vector of vectors (like 2d array)

    private:
};