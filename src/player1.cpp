#include "Player1.h"

//--------------------------------------------------------------
Player1::Player1()
{
    set(x, y, width, height);

    player1_start.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\initialmario.png");
    player1_move.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mario run.png");
    player1_jump.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\jump.png");
    player1_punch.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mariopunch.png");



     movee=false;
     jumpe=false;
     starte=false;
     punchee = false;
     b = false;
}
//--------------------------------------------------------------
void Player1::punch()
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
void Player1::drawPunch(int x_shift)
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
void Player1::set(int x_in, int y_in, int width_in, int height_in)
{
    isJumping = -1;
    x = x_in;
    y = y_in;
    width = width_in;
    height = height_in;
}
//--------------------------------------------------------------
void Player1::drawHealth(int health)
{
    ofPushStyle();
    ofFill();
    ofSetColor(0, 255, 0); // Green
    ofDrawRectangle(x, y - 50, width * (health / 100.0), 10);

    ofPopStyle();
}
//--------------------------------------------------------------
void Player1::Mariodraw()
{
        
    if (ofGetKeyPressed('d')) // Check if 'd' key is pressed
    {
        starte = false;
        movee = true;
        jumpe = false;
        punchee = false;
        player1_move.draw(x, y);
    }
    else if (ofGetKeyPressed('f')) // Check if 'f' key is pressed
    {
        starte = false;
        movee = false;
        jumpe = false;
        punchee = true;
        player1_punch.draw(x, y);
    }
    else if (ofGetKeyPressed('a')) // Check if 'a' key is pressed
    {
        starte = false;
        movee = true;
        jumpe = false;
        punchee = false;
        player1_move.draw(x, y);
    }
    else if (ofGetKeyPressed('w') && !jumpe) // Check if 'w' key is pressed and jumping flag is false
    {
        starte = false;
        movee = false;
        jumpe = true;
        punchee = false;
        player1_jump.draw(x, y);
    }
    else // If no key is pressed, draw the starting image
    {
        starte = true;
        movee = false;
        jumpe = false;
        punchee = false;
        player1_start.draw(x, y);
    }
}


