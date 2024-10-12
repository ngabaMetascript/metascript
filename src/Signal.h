#ifndef SIGNAL_H
#define SIGNAL_H

#include <string>

struct Signal{
	string code;
	string time_emitted;
	vector<Point*> zone;
}

const Signal MOUSE_HOVER;
const Signal MOUSE_MOVE_LEFT;
const Signal MOUSE_MOVE_RIGHT;
const Signal MOUSE_MOVE_DOWN;
const Signal MOUSE_MOVE_UP;
const Signal MOUSE_LEFT_CLICK;
const Signal MOUSE_RIGHT_CLICK;

const Signal KEYBOARD_PRESS;
const Signal KEYBOARD_DOWN;
const Signal KEYBOARD_UP;

const Signal MICRO_GET;
const Signal CAMERA_GET;

#endif
