#define _USE_MATH_DEFINES

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cmath>

//screen
const int screenWidth = 40;
const int screenHeight = 40;
char screen[screenWidth][screenHeight];

//fov
const double fov = 2 * M_PI / 3; //120 degrees
const double halfFov = fov / 2;
const double degPerColumn = fov / screenWidth;
const float degreesPerColumn = screenWidth / fov;

//degree constants
const double deg45 = M_PI / 4;
const double deg90 = M_PI / 2;
const double deg180 = M_PI;
const double deg270 = 3 * M_PI / 2;
const double deg360 = M_PI * 2;

//block constant
const int blockSize = 64;

//load level; remember second number is x while first is y
char level[9][9] = {
    {'#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ','#','#','#',' ','#'},
    {'#',' ',' ',' ','#',' ',' ',' ','#'},
    {'#',' ','#','#','#',' ','#',' ','#'},
    {'#',' ',' ',' ',' ',' ','#',' ','#'},
    {'#',' ','#','#','#','#','#',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#'},
};
int mapColumns = sizeof(level[0]);
int mapRows = sizeof(level);

/*void renderFrame(char screen[screenWidth][screenHeight], int playerX, int playerY, double view) {
    for (int i = 0; i < screenWidth; i++) {
        double rayDegree = view - (halfFov)+degPerColumn * i;

        if (rayDegree > deg360) {
            rayDegree -= deg360;
        }
        
        //std::cout << "rayDegree: " << rayDegree * 57.2958 << std::endl;

        double distanceFromCellX = playerX % 64;
        double distanceFromCellY = playerY % 64;

        //std::cout << "distanceFromCellX: " << distanceFromCellX << std::endl;
        //std::cout << "distanceFromCellY: " << distanceFromCellY << std::endl;

        if (rayDegree < deg180) {
            distanceFromCellY = 64 - distanceFromCellY;
        }
        if (rayDegree < deg90 or rayDegree > deg270) {
            distanceFromCellX = 64 - distanceFromCellX;
        }


        //Find first intersection x
        double xLen = playerX + sin(rayDegree) * distanceFromCellY;
        bool wallFound = false;

        int lenToWallX = xLen;
        int j = 0;
        while (!wallFound) {
            if (level[int(xLen / 64) + j][int(playerX / 64)] == '#') {
                wallFound = true;
            }
            lenToWallX += 64;
            j++;
        }
        //std::cout << "lenToWallX: " << lenToWallX << std::endl << std::endl;

        //Find first intersection y
        double yLen = playerY + sin(rayDegree) * distanceFromCellX;
        wallFound = false;

        int lenToWallY = yLen;
        j = 0;
        while (!wallFound) {
            if (level[int(yLen / 64) + j][int(playerY / 64)] == '#') {
                wallFound = true;
            }
            lenToWallY += 64;
            j++;
        }
        //std::cout << "lenToWallY: " << lenToWallY << std::endl << std::endl;

        if (lenToWallX > lenToWallY) {
            double columnSize = double(screenHeight) / lenToWallY * 50;
            double margin = (double(screenHeight) - columnSize) / 2;
            for (int k = margin; k < columnSize + margin; k++) {
                screen[k][i] = '#';
            }
        }
        else {
            //std::cout << "x" << std::endl;
            double columnSize = double(screenHeight) / lenToWallX * 50;
            double margin = (double(screenHeight) - columnSize) / 2;
            for (int k = margin; k < columnSize + margin; k++) {
                screen[k][i] = '#';
            }
        }

    }
}*/

void renderFrame(char screen[screenWidth][screenHeight], int playerX, int playerY, double view) {
    //loops through each column of the display to calculate the view from that angle
    for (int currentView = view - (degreesPerColumn * halfFov); currentView < view + (degreesPerColumn * halfFov); currentView += degreesPerColumn) {

    }
}

void printScreen(char screen[screenWidth][screenHeight]) {
    for (int i = 0; i < screenWidth; i++) {
        for (int j = 0; j < screenHeight; j++) {
            std::cout << screen[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    //init screen
    for (int i = 0; i < screenWidth; i++) {
        for (int j = 0; j < screenHeight; j++) {
            screen[i][j] = '-';
        }
    }

    //player variables 
    double playerX = 200;
    double playerY = 210;
    double view = deg45;

    float moveX = 0;
    float moveY = 0;
    float moveView = 0.01;

    //std::cout << "here" << std::endl;

    while (true) {
        system("CLS");

        renderFrame(screen, playerX, playerY, view);

        printScreen(screen);

        view += moveView;
    }

    return 0;
}
