#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main() {
    const int width = 20;
    const int height = 10;
    int birdY = height / 2;
    int score = 0;
    int pipeX = width-1;
    int pipeY = rand() % (height-2) + 1;
    bool isAlive = true;

    while (isAlive) {
        system("cls");

        for(int y=0; y<height; y++){
            for(int x=0; x<width; x++){
                if (x==0 && y==birdY) cout << "O";
                else if (x==pipeX && (y<pipeY || y>pipeY+2)) cout << "|";
                else cout << ".";
            }
            cout << "\n";
        }

        cout << "Score: " << score << "\n";

        if (_kbhit()) {
            char ch = _getch();
            if (ch==' ') birdY--;
        }

        birdY++;

        if (birdY<0 || birdY>=height) isAlive=false;

        if (pipeX==0) {
            if (birdY<pipeY || birdY>pipeY+2) isAlive=false;
            else score++;
            pipeX = width-1;
            pipeY = rand() % (height-2) + 1;
        } else pipeX--;

        Sleep(200);
    }

    cout << "Game Over! Final score: " << score << endl;
    return 0;
}
