#ifndef SIGNAL_H
#define SIGNAL_H

#include <string>
#include "Elt.h"

using namespace std;
struct Signal{
	string code;
	string time_emitted;
	vector<c2D::Point2D*> zone;
};

const string MOUSE_HOVER_SIGNAL = "/AX0_H01_001";
/*
const Signal* MOUSE_MOVE_LEFT;
const Signal* MOUSE_MOVE_RIGHT;
const Signal* MOUSE_MOVE_DOWN;
const Signal* MOUSE_MOVE_UP;
const Signal* MOUSE_LEFT_CLICK;
const Signal* MOUSE_RIGHT_CLICK;

const Signal* KEYBOARD_PRESS;
const Signal* KEYBOARD_DOWN;
const Signal* KEYBOARD_UP;

const Signal* MICRO_GET;
const Signal* CAMERA_GET;
*/
#endif
