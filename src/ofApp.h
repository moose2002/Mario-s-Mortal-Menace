#pragma once

#include "ofMain.h"
#include "Player1.h"
#include "player2.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		bool instruct;
		bool isPlaying;
		bool p1win, p2win;
		bool fat1;
		bool fat2;
		ofTrueTypeFont intro, p1_win, p2_win;
		ofImage map;
		ofImage map1win;
		ofImage map2win;
		
		
		//Musics sounds
		ofSoundPlayer punch;
		ofSoundPlayer punch2;
		ofSoundPlayer game;
		ofSoundPlayer win1;
		ofSoundPlayer win2;
		ofSoundPlayer start;
		ofSoundPlayer fatal;


		
		ofVideoPlayer vid1;
		ofVideoPlayer vid2;

		
private:
	Player1 player1;
	Player2 player2;
};
