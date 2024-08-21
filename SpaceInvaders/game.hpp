#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mysetryship.hpp"
class Game{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
        void CheckForCollisions();
        bool run;
        int lives;
        int score;
        int highScore;
        int level;
    private:
        void DeleteInactiveLasers();
        std:: vector<Obstacle> CreateObstacles();//will return a vector of obstacles
        std:: vector<Alien> CreateAliens();//will return a vector of aliens 
        void MoveAliens();
        void MoveDownAliens(int distance);
        void AlienShootLaser();
        void GameOver();
        void Reset();
        void InitGame();
        void CheckForHighScore();
        void saveHighScoreToFile(int highscore);
        int loadHighscoreFromFile();
        Spaceship spaceship;
        std::vector<Obstacle> obstacles;
        std::vector<Alien> aliens;
        int aliensDirection;
        std:: vector<Laser> alienLasers;
        constexpr static float alienLaserShootInterval = 0.35;
        float timeLastAlienFired;
        MysteryShip mysteryship;
        float mysteryShipSpawnInterval;
        float timeLastSpawn;
       


};