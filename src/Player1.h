#pragma once

#include "ofMain.h"

#define N_MAX 2

class Player1 {
public:
    // Constructor
    Player1();

    // Methods
    void set(int x_in, int y_in, int width_in, int height_in);
    void drawHealth(int health);
    void Mariodraw();
    void punch();
    void drawPunch(int x_shift);

    // Member Variables
    int health;
    int punch_count;
    ofRectangle vx_punches[N_MAX];
    ofRectangle p1;
    int x;
    int y;
    int width;
    int height;
    int isJumping;

    // Movement Bools
    bool movee;
    bool jumpe;
    bool starte;
    bool punchee;
    bool b;

    //Images
    ofImage player1_start;
    ofImage player1_move;
    ofImage player1_jump;
    ofImage player1_punch;

   
};