#include "prefix.h"
#include "titleTask.h"
#include "canvas.h"

#include <math.h>


TitleTask gTitleTask;


TitleTask::TitleTask() {
    lwinfo("TitleTask::TitleTask()");
}


TitleTask::~TitleTask() {
    
}

void TitleTask::vStart() {
    glClearColor(0.31f, 0.69f, 0.61f, 1.0f);
    _pCanvas = new Canvas(0, 0, 128/2, 192/2, 640, 960);
    _pSptBg = lw::Sprite::createFromFile("bg.jpg", "normal");
    _pSptBg->setSize(640, 960);
}

void TitleTask::vStop() {
    delete _pCanvas;
    delete _pSptBg;
}


void TitleTask::vUpdate() {
    
}


void TitleTask::vDraw() {
    _pSptBg->draw();
    _pCanvas->draw();
}

void TitleTask::vTouchBegan(const lw::Touch &touch) {
    lwinfo("vTouchBegan");
}

void TitleTask::vTouchMoved(const lw::Touch &touch) {
    lwinfo("vTouchMoved");
}

void TitleTask::vTouchEnded(const lw::Touch &touch)  {
    lwinfo("vTouchEnded");
}

void TitleTask::vTouchCanceled(const lw::Touch &touch)  {
   lwinfo("vTouchCanceled");
}







