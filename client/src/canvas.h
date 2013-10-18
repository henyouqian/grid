#ifndef __GRID_CANVAS_H__
#define __GRID_CANVAS_H__

class Canvas {
public:
    Canvas(uint x, uint y, uint w, uint h, uint sw, uint sh);
    ~Canvas();
    
    void draw();
    
private:
    uint _x, _y, _w, _h;
    lw::Sprite *_pSprite;
    GLuint _texId;
    uint *_texData;
};

#endif