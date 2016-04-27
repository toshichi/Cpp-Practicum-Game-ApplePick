#include "apple.h"
bear::bear(int x, int y, IMAGE* ibear, IMAGE* ibearx, IMAGE* bg) {
	this->x = x;
	this->y = y;
	this->w = ibear->getwidth();
	this->h = ibear->getheight();
	this->ibear = ibear;
	this->ibearx = ibearx;
	this->main_bg = bg;
	show();
}
bool bear::ifCaught(man man0) {
	if (man0.getY() < y + h && man0.getY() + man0.getH() > y) return true;
	else return false;
}
void bear::move(int top, int bottom) {
	hide();
	if (isMovingUp) {
		if (y > top) {
			y -= 1;
		}
		else {
			isMovingUp = false;
			y += 1;
		}
	}
	else {
		if (y + h < bottom) {
			y += 1;
		}
		else {
			isMovingUp = true;
			y -= 1;
		}
	}
	show();
}
void bear::show() {
	transimg(x, y, ibear, ibearx);
}
void bear::hide() {
	repaintBlock(x, y, x + w, y + h, main_bg);
}