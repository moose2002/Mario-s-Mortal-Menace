#include "player2.h"

//--------------------------------------------------------------
Player2::Player2() {
    set(x, y, width, height);

    player2_start.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\Bowser start.png");
    player2_move.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\Bowser start.png");
    player2_jump.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\Bowser start.png");
    player2_punch.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\Bowser Punch.png");

    movee = false;
    jumpe = false;
    starte = false;
    punchee = false;
}

//--------------------------------------------------------------
void Player2::set(int x_in, int y_in, int width_in, int height_in)
{
    isJumping = -1;
    x = x_in;
    y = y_in;
    width = width_in;
    height = height_in;
}
//--------------------------------------------------------------
void Player2::punch()
{
    ofRectangle bullet;
    bullet.set(0, 850, 1900, 20);
    for (int i = punch_count; i >= 0; i--)
    {
        vx_punches[i + 1] = vx_punches[i];
    }
    vx_punches[0] = bullet;
    punch_count++;
}
//--------------------------------------------------------------
void Player2::drawPunch(int x_shift)
{
    for (int i = 0; i < punch_count; i++)
    {
        vx_punches[i].x += x_shift;
        if (vx_punches[i].x < 1500)
        {
            punch_count--;
        }
        //ofFill();
        //ofSetColor(255, 255, 255);
        //ofDrawRectangle(vx_punches[i]);
    }
}
//--------------------------------------------------------------
void Player2::drawHealth(int health)
{
    ofPushStyle();
    ofFill();
    ofSetColor(255, 0, 0); // red
    ofDrawRectangle(x, y - 50, width * (health / 100.0), 10);
    ofPopStyle();
}
//--------------------------------------------------------------
void Player2::Mariodraw()
{

    if (ofGetKeyPressed(OF_KEY_LEFT)) // Check if 'left' key is pressed
    {
        starte = false;
        movee = true;
        jumpe = false;
        punchee = false;
        player2_move.draw(x, y);
    }
    else if (ofGetKeyPressed(',')) // Check if ',' key is pressed
    {
        starte = false;
        movee = false;
        jumpe = false;
        punchee = true;
        player2_punch.draw(x, y);
    }
    else if (ofGetKeyPressed(OF_KEY_RIGHT)) // Check if 'right' key is pressed
    {
        starte = false;
        movee = true;
        jumpe = false;
        punchee = false;
        player2_move.draw(x, y);
    }
    else if (ofGetKeyPressed(OF_KEY_UP) && !jumpe) // Check if 'up' key is pressed and jumping flag is false
    {
        starte = false;
        movee = false;
        jumpe = true;
        punchee = false;
        player2_jump.draw(x, y);
    }
    else // If no key is pressed, draw the starting image
    {
        starte = true;
        movee = false;
        jumpe = false;
        punchee = false;
        player2_start.draw(x, y);
    }
}