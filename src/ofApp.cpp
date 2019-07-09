#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(15);

	for (int i = 0; i < w/resol; i++) {
		for (int j = 0; j < h/resol; j++) {
			float rand = ofRandom(100);
			cells[i][j].state = rand < 30 ? true : false;
		}
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < w / resol; i++) {
		for (int j = 0; j < h / resol; j++) {
			int neig = countNei(i, j);
			if (cells[i][j].state) {
				if (!contains(false, neig))
					cells[i][j].next = false;
			}
			else {
				if (contains(true, neig))
					cells[i][j].next = true;
			}
		}
	}


	for (int i = 0; i < w / resol; i++) {
		for (int j = 0; j < h / resol; j++) {
			cells[i][j].state = cells[i][j].next;
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(52);
	for (int i = 0; i < w / resol; i++) {
		for (int j = 0; j < h / resol; j++) {
			float x = i*resol, y = j*resol, width = resol, height = resol;
			if (!cells[i][j].state) {
				ofSetColor(255);
				ofFill();
			}
			else ofNoFill();
			ofDrawRectangle(x, y, width, height);
		}
	}
}

int ofApp::countNei(int x, int y) {
	int sum = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int wt = w / resol, ht = h / resol;
			int xpos = (x + i + wt) % wt;
			int ypos = (y + j + ht) % ht;
			sum += cells[xpos][ypos].state;
		}
	}
	
	return sum - cells[x][y].state;
}

bool ofApp::contains(bool b, int c) {
	if (b) {
		for (int i = 0; i < sizeof(birth) / sizeof(*birth); i++) {
			if (birth[i] == c) return true;
		}
	}
	else {
		for (int i = 0; i < sizeof(live) / sizeof(*live); i++) {
			if (live[i] == c) return true;
		}
	}
	return false;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	cells[x / resol][y / resol].state = true;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	cells[x / resol][y / resol].state = true;
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
