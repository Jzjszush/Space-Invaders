#include <raylib.h>
#include "game.hpp"
#include <string>

std::string FormatWithLeadingZeros(int number, int width){
        std::string numberText = std::to_string(number);
        int leadinZeros = width-numberText.length();
        return numberText = std::string(leadinZeros, '0') + numberText;

}



int main(){
    Color blue = {29,29,40,255}; //creates color of background
    Color yellow = {243,216,63,255};
    int offset = 50;//adds more space to make the user interface pretty
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth+offset,windowHeight+2*offset, "C++ Space Invaders");

    Font font = LoadFontEx("Font/monogram.tff",64,0,0);
    Texture2D spaceshipImage = LoadTexture("Graphics/spaceship.png");
    SetTargetFPS(60);//sets the FPS for the game so cumputer doesn't set it too fast

    Game game;
    
    while(WindowShouldClose() == false){//checks if the escape or close key is pressed


        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(blue);//adds color to background
        DrawRectangleRoundedLines({10,10,780,780},0.18f,20,2,yellow);//creates yellow frame around game
        DrawLineEx({25,730}, {775,730},3,yellow);//horizontel line at bottom
        if(!game.run){
        
            DrawTextEx(font, "GAME OVER", {570,740},34,2,yellow);
        }

        float x = 50.0;
        for(int i = 0; i < game.lives;i++){
            DrawTextureV(spaceshipImage,{x,745},WHITE);
            x+=50;

        }

        //these print the score, highcore, and level to the screen
        DrawTextEx(font,"SCORE:", {60,15},34,2,yellow);
        std:: string scoreText = FormatWithLeadingZeros(game.score,5);
        DrawTextEx(font,scoreText.c_str(),{60,50},34,2,yellow);
        game.Draw();

        DrawTextEx(font, "HIGH-SCORE", {530,15},34,2,yellow);
        std:: string highscoreText = FormatWithLeadingZeros(game.highScore,5);
        DrawTextEx(font,highscoreText.c_str(), {640,50},34,2,yellow);
        if(game.run){
            DrawTextEx(font, "LEVEL ", {550,740},34,2,yellow);
            std:: string levelText = FormatWithLeadingZeros(game.level,5);
            DrawTextEx(font,levelText.c_str(),{670,740},34,2,yellow);
        }
       

        EndDrawing();
       
    }
    CloseWindow();
}
