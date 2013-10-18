#ifndef __LW_TITLE_TASK_H__
#define __LW_TITLE_TASK_H__

namespace lw {
    class Sprite;
}

class Canvas;

class TitleTask: public lw::Task
{
public:
    TitleTask();
    ~TitleTask();
    
private:
    virtual void vStart();
    virtual void vStop();
    virtual void vUpdate();
    virtual void vDraw();
    
    virtual void vTouchBegan(const lw::Touch &touch);
    virtual void vTouchMoved(const lw::Touch &touch);
    virtual void vTouchEnded(const lw::Touch &touch);
    virtual void vTouchCanceled(const lw::Touch &touch);
    
    Canvas *_pCanvas;
    lw::Sprite *_pSptBg;
};

extern TitleTask gTitleTask;


#endif //__LW_TITLE_TASK_H__