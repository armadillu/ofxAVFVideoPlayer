#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    for(int i=0; i<N_VIDEO_PLAYERS; i++) {
        videoPlayers.push_back(new ofxAVFVideoPlayer());
        //videoPlayers[i]->loadMovie("/Users/oriol/Programming/svn.uri.cat/OF_Projects/of_v0080_osx/apps/tests/largeContext/bin/data/movie" + ofToString(i) + ".mov");
		videoPlayers[i]->loadMovie("/Users/oriol/Programming/svn.uri.cat/LP_Projects/of_v080_osx_win/apps/TOR_SyncTests/sharedAssets/tennisLong.mov");
		videoPlayers[i]->play();
    }
    
    
    ofSetVerticalSync(true);
    

}

//--------------------------------------------------------------
void testApp::update(){
    int i=0;
    for(auto p : videoPlayers) {
        p->update();
        if(true || p->isLoaded()) {
//            if(ofGetElapsedTimef() > i++ * 0.5)
//                p->play();
        }
    }
        
    //cout << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
void testApp::draw(){
    int i=0;
    for(auto p : videoPlayers) {
        // draw video
        ofSetColor(ofColor::white);
        ofFill();
		float s = 0.5;
		int row = i % 2;
		int col = i / 2;
		int xx = row * 1920 * s;
		int yy = col * 1080 * s;
		p->draw(xx,yy, p->getWidth() *s, p->getHeight() *s);
        i++;
    }

	string out = "";
	out += "speed: " + ofToString(videoPlayers[0]->getSpeed()) + "\n";
	out += "pos: " + ofToString(videoPlayers[0]->getPosition()) + "\n";
	ofDrawBitmapStringHighlight(out, 20, 20);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	switch (key) {

		case ' ':
			for(auto p : videoPlayers) {
				p->setPaused(!p->isPaused());
			}
			break;

		case OF_KEY_UP:
			for(auto p : videoPlayers) {
				p->setSpeed(p->getSpeed() + 0.02);
				cout << "speed: " << p->getSpeed() << endl;
			}
			break;

		case OF_KEY_DOWN:
			for(auto p : videoPlayers) {
				p->setSpeed(p->getSpeed() - 0.02);
				cout << "speed: " << p->getSpeed() << endl;
			}
			break;

		case OF_KEY_RIGHT:
			for(auto p : videoPlayers) {
				p->setPosition(p->getPosition() + 0.1);
				cout << "pos: " << p->getPosition()<< endl;
			}
			break;

		case OF_KEY_LEFT:
			for(auto p : videoPlayers) {
				p->setPosition(p->getPosition() - 0.1);
				cout << "pos: " << p->getPosition()<< endl;
			}
			break;

		default:
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}