#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("20170610");

	this->noise_s = ofRandom(10);
	this->noise_p = ofRandom(10);

	ofSetColor(12);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();

	float radius, angle_s, angle_p;
	float tmp_noise_s, tmp_noise_p;
	float x, y, z;
	ofVec3f pre_vec;

	tmp_noise_p = this->noise_p;
	tmp_noise_s = this->noise_s;

	for (int s = 0; s <= 180; s += 10) {
		tmp_noise_p = this->noise_p;

		for (int p = 0; p < 360; p += 30) {
			pre_vec = ofVec3f(0, 0, 0);

			for (radius = 100; radius < ofGetWidth() / 2; radius += 10) {

				angle_s = s; //  +90 * ofNoise(tmp_noise_s);
				angle_p = p + 180 * ofNoise(tmp_noise_p);

				x = radius * cos(angle_p * DEG_TO_RAD) * sin(angle_s * DEG_TO_RAD);
				y = radius * sin(angle_p * DEG_TO_RAD) * sin(angle_s * DEG_TO_RAD);
				z = radius * cos(angle_s * DEG_TO_RAD);

				//ofSphere(ofVec3f(x, y, z), 3);

				if (radius > 100) {
					ofLine(ofVec3f(x, y, z), pre_vec);
				}
				pre_vec = ofVec3f(x, y, z);

				tmp_noise_p += 0.01;
			}
		}
	}

	this->noise_s += 0.01;
	this->noise_p += 0.01;

	this->cam.end();
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
