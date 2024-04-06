#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetVerticalSync(false);

	//Set frame rate to 30
	ofSetFrameRate(30);

	// Initalizing Game States
	isPlaying = false;
	instruct = true;
	p1win = false;
	p2win = false;
	fat1 = false;
	fat2 = false;

	//Loading and configuring sound effects 
	punch.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mp3\\punch.mp3");
	punch.setVolume(1);
	punch.setSpeed(1);

	punch2.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mp3\\chair.mp3");
	punch2.setVolume(1);
	punch2.setSpeed(2);


	win1.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mp3\\p1win.mp3");
	win1.setVolume(0.2);
	win1.setSpeed(1);

	win2.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mp3\\p2win.mp3");
	win2.setVolume(0.5);
	win2.setSpeed(0.8);


	start.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mp3\\background.mp3");
	start.setVolume(1);
	start.setSpeed(1);
	start.play();

	game.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\game.mp3");
	game.setVolume(1);
	game.setSpeed(1);

	fatal.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mp3\\fatality.mp3");
	fatal.setVolume(1);
	fatal.setSpeed(1);
	

	//Loading game background images
	
	map.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\map.jpeg");
	map1win.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\fatal screen2.png");
	
	
	// Loading fonts
	intro.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\PlayfairDisplay-Black.ttf", 25);
	p1_win.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mk5style.ttf", 45);
	p2_win.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mk5style.ttf", 45);

	// Videos
	vid1.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mp4\\fatal1.mp4");
	vid1.setFrame(50);
	vid1.setLoopState(OF_LOOP_NONE);
	vid1.setSpeed(1);


	vid2.load("C:\\Users\\abdel\\Desktop\\ECE 270\\of_v0.11.2_vs2017_release\\apps\\myApps\\FinalGame\\bin\\mp4\\fatal2.mp4");
	vid2.setFrame(50);
	vid2.setLoopState(OF_LOOP_NONE);
	vid2.setSpeed(1);

	// Position of Players
	player1.Mariodraw();
	player2.Mariodraw();

	player1.set(0, 800, 100, 100);
	player1.health = 100;

	player2.set(1900, 800, 100, 100);
	player2.health = 100;

	player1.p1.set(50, 800, 90, 90);
	player2.p2.set(1850, 800, 90, 90);


}
//--------------------------------------------------------------
void ofApp::update()
{
	// Check if instructions are not displayed
	if (instruct == false)
	{
		start.stop();
	}

	// Check if game is currently playing
	if (isPlaying == true)
	{
		// Check if game sound is not already playing, then play it
		if (!game.isPlaying())
		{
			game.play();
		}

		// Loop through player1's & player2's fatality count
		for (int i = 0; i < player1.punch_count; i++)
		{
			// Check if player2's health is less than 10 and if punch intersection occurs
			if (player2.health <= 10 && (player1.vx_punches[i].intersects(player2.p2)))
			{
				isPlaying = false;
				game.stop();
				fat1 = true;

			}
		}
		for (int i = 0; i < player2.punch_count; i++)
		{
			// Check if player2's health is less than 10 and if punch intersection occurs
			if (player1.health <= 10 && (player2.vx_punches[i].intersects(player1.p1)))
			{
				isPlaying = false;
				game.stop();
				fat2 = true;

			}
		}

		// Check for key presses for punching
		if (ofGetKeyPressed('f'))
		{
			punch.play();
			// Check punch intersection with player1
			if (player2.p2.intersects(player1.p1))
			{
				player2.health -= 1;
			}
		}

		// Check for key presses for punching
		if (ofGetKeyPressed(','))
		{
			punch2.play();
			// Check punch intersection with player2
			if (player1.p1.intersects(player2.p2))
			{
				player1.health -= 1;
			}
		}

		// Check if player1's health is 0, then player2 wins
		if (player1.health == 0)
		{
			p2win = true;
			isPlaying = false;
			game.stop();
			win2.play();
			fatal.play();
			cout << "\n\nPlayer2 is intersecting with Player1";
		}

		// Check if player2's health is 0, then player1 wins
		if (player2.health == 0)
		{
			p1win = true;
			isPlaying = false;
			game.stop();
			win1.play();
			fatal.play();
			cout << "\n\nPlayer2 is intersecting with Player1";
		}
	}

	if (fat1 == true)
	{
		vid1.play();
		vid1.update();
		if (!vid1.isPlaying())
		{
			vid1.stop();
		}
		if (vid1.getIsMovieDone())
		{
			fat1 = false;
			p1win = true;
			fatal.play();
			win1.play();
		}
	}

	if (fat2 == true)
	{
		vid2.play();
		vid2.update();
		if (!vid2.isPlaying())
		{
			vid2.stop();
		}
		if (vid2.getIsMovieDone())
		{
			fat2 = false;
			p2win = true;
			fatal.play();
			win2.play();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	// State : Fatality videos
	if (fat1 == true) 
	{
		vid1.draw(0, 0);
	}
	if (fat2 == true)
	{
		vid2.draw(0, 0);
	}

	// State: Instruction screen
	if (instruct == 1) {
		ofSetBackgroundColor(0, 0, 0);
		ofSetColor(255, 255, 255);
		intro.drawString("Instructions", ofGetWidth() / 2 - 100, ofGetHeight() / 5);
		intro.drawString("Player 1:\nUse WAD to move and 'F' to punch and 'T' to fatality", 500, 300);
		intro.drawString("Player 2:\nUse arrow keys to move and ',' to punch and 'SPACE BAR' to fatality", 500, 500);
		intro.drawString("Each player has 100 health", 500, 625);
		intro.drawString("You can use your fatality when the player health is low 10 or below", 500, 700);
		intro.drawString("Press 'ENTER' to play", 500, 800);
		intro.drawString("Press 'ESC' to EXIT", 500, 900);
	}

	// State: Player 1 wins
	if (p1win == true) {
		ofSetColor(255, 255, 0);
		p1_win.drawString("PLAYER 1 WINS", 700, 600);
		p1_win.drawString("Press 'ESC' to EXIT", 700, 700);
		map1win.draw(600, 0);
	}

	// State: Player 2 wins
	if (p2win == true) {
		ofSetColor(255, 255, 0);
		p2_win.drawString("PLAYER 2 WINS", 700, 600);
		p2_win.drawString("Press 'ESC' to EXIT", 700, 700);
		map1win.draw(600, 0);
	}

	// State: Game playing variables etc
	if (isPlaying == true) {
		//cout << "\n\nisJumping" << player1.isJumping;
		//cout << "player1.x" << player1.x;
		//cout << "\n\nPlayer1.y" << player1.y;

		map.draw(0, 0);
		player1.Mariodraw();
		player1.drawHealth(player1.health);
		player2.drawHealth(player2.health);

		//ofSetColor(255, 255, 255);
		//ofDrawRectangle(player1.p1);
		//ofSetColor(255, 255, 255);
		//ofDrawRectangle(player2.p2);
		player1.drawPunch(20);
		player2.drawPunch(-20);


		//Making players jump
		player1.Mariodraw();

		if (player1.isJumping > 0 && player1.isJumping > 15)
		{
			player1.y = player1.y - 10;
			player1.isJumping = player1.isJumping - 1;
		}
		 if (player1.isJumping > 0 && player1.isJumping <= 15)
		{
			player1.y = player1.y + 10;
			player1.isJumping = player1.isJumping - 1;
		}

		 player2.Mariodraw();

		 if (player2.isJumping > 0 && player2.isJumping > 15)
		 {
			 player2.y = player2.y - 10;
			 player2.isJumping = player2.isJumping - 1;
		 }
		 if (player2.isJumping > 0 && player2.isJumping <= 15)
		 {
			 player2.y = player2.y + 10;
			 player2.isJumping = player2.isJumping - 1;
		 }

		 //Rectangles Jumping
		 if (player2.isJumping > 0 && player2.isJumping > 15)
		 {
			 player2.p2.y = player2.p2.y - 25;
			 player2.isJumping = player2.isJumping - 1;
		 }
		 if (player2.isJumping > 0 && player2.isJumping <= 15)
		 {
			 player2.p2.y = player2.p2.y + 25;
			 player2.isJumping = player2.isJumping - 1;
		 }

		 if (player1.isJumping > 0 && player1.isJumping > 15)
		 {
			 player1.p1.y = player1.p1.y - 25;
			 player1.isJumping = player1.isJumping - 1;
		 }
		 if (player1.isJumping > 0 && player1.isJumping <= 15)
		 {
			 player1.p1.y = player1.p1.y + 25;
			 player1.isJumping = player1.isJumping - 1;
		 }
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 't')
	{
		player1.punch(); //  Trigger a new laser for player1
	}
	if (key == ' ')
	{
		player2.punch(); //  Trigger a new laser for player1
	}

	if (key == OF_KEY_ESC)
	{
		ofExit(); //  Close the application
	}

	if (instruct) // Check if instruct flag is true
	{
		if (key == OF_KEY_RETURN)
		{
			instruct = false; //  Set instruct flag to false
			isPlaying = true; //  Set isPlaying flag to true
			game.play(); //  Start the game
		}
	}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	int minx = 0; // minimum x position
	int maxX = 1900; // maximum x position
	int recmax = 1850; // maximum x position for rec
	int recmin = 50; //minimum x position

	if (isPlaying==true)
	{
		player1.Mariodraw();
		// Jumping
		if (key == 'w' && player1.y > 790) // Check if player1 is not already jumping, is at the original position, and is above the minimum y position
		{
			//cout << "inside!";
			player1.isJumping = 30;
		}
		if (key == 'w' && player1.p1.y > 790) // Check if player1 is not already jumping, is at the original position, and is above the minimum y position
		{
			//cout << "inside!";
			player1.isJumping = 30;
		}
		// Move player1 left and right
		if (player1.x != (player2.x - 100))
		{
			if (key == 'd' && player1.x < maxX) // Check if player1 is not exceeding the maximum x position
			{
				player1.x = player1.x + 50;
			}
			if (key == 'd' && player1.p1.x < recmax) // Check if rectangle is not exceeding the maximum x position
			{
				player1.p1.x = player1.p1.x + 50;
			}
		}
			if (key == 'a' && player1.p1.x > recmin) // Check if rectangle is not going below the minimum x position
			{
				player1.p1.x = player1.p1.x - 50;
			}
			if (key == 'a' && player1.x > minx) // Check if player1 is not going below the minimum x position
			{
				player1.x = player1.x - 50;
			}

		//Player 2
		player2.Mariodraw();
		// Jumping
		if (key == OF_KEY_UP && player2.y > 790) // Check if player2 is not already jumping, is at the original position, and is above the minimum y position
		{
			//cout << "inside!";
			player2.isJumping = 30;
		}
		if (key == OF_KEY_UP && player2.p2.y > 790) // Check if player2 is not already jumping, is at the original position, and is above the minimum y position
		{
			//cout << "inside!";
			player2.isJumping = 30;
		}
		// Move player2 left and right
		if (key == OF_KEY_RIGHT && player2.x < maxX) // Check if player2 is not exceeding the maximum x position
		{
			player2.x = player2.x + 50;
		}
		if (key == OF_KEY_RIGHT && player2.p2.x < recmax) // Check if Rectangle is not exceeding the maximum x position
		{
			player2.p2.x = player2.p2.x + 50;
		}
		if (player2.x != (player1.x + 100))
		{
			if (key == OF_KEY_LEFT && player2.x > minx) // Check if player2 is not going below the minimum x position
			{
				player2.x = player2.x - 50;
			}
			if (key == OF_KEY_LEFT && player2.x > recmin) // Check if player2 is not going below the minimum x position
			{
				player2.p2.x = player2.p2.x - 50;
			}
		}
	}
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}