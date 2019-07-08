#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(20);

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
				if (neig != 2 && neig != 3)
					cells[i][j].next = false;
			}
			else {
				if (neig == 3)
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
