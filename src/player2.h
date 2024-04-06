#pragma once

#include "ofMain.h"
#define N_MAX 60

class Player2 {
public:

    // Constructor
    Player2();

    // Methods
    void set(int x_in, int y_in, int width_in, int height_in);
    void punch();
    void drawHealth(int health);
    void Mariodraw();
    void drawPunch(int x_shift);

    // Member Variables
    int x;
    int y;
    int width;
    int height;
    int punch_count;
    int health;
    ofRectangle vx_punches[N_MAX];
    ofRectangle p2; //Rectangle of Player 2
    int isJumping;

    //Movement Flags(bools)

    bool movee;
    bool jumpe;
    bool starte;
    bool punchee;
    bool b;

    //Images
    ofImage player2_start;
    ofImage player2_move;
    ofImage player2_jump;
    ofImage player2_punch;
};