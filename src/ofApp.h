#pragma once

#include "ofMain.h"

const int h = 600;
const int w = 900;
const int resol = 10;

struct Cell {
	bool state;
	bool next;

};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		Cell cells[w/resol][h/resol];

	private:	
		int countNei(int x, int y);
};
