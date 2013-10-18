#include "prefix.h"
#include "canvas.h"

Canvas::Canvas(uint x, uint y, uint w, uint h, uint sw, uint sh) {
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    
    _texData = new uint[w*h];
    for (int i = 0; i < w*h; ++i) {
        _texData[i] = 0xff000000;
    }
    
    _pSprite = lw::Sprite::createFromFile("empty.png", "normal");
    
    lw::TextureRes *pTex = _pSprite->getTexture();
    pTex->w = w;
    pTex->h = h;
    pTex->numChannels = 4;
    
    _texId = pTex->glId;
    glBindTexture(GL_TEXTURE_2D, _texId);
	glTexImage2D(
                 GL_TEXTURE_2D, 0,
                 GL_RGBA, w, h, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, _texData );
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    _pSprite->setSize(sw, sh);
}

Canvas::~Canvas() {
    delete _pSprite;
    delete [] _texData;
}

void Canvas::draw() {
    int x = rand() % _w;
    int y = rand() % _h;
    _texData[y*_w+x] = 0x00000000;
    
    glBindTexture(GL_TEXTURE_2D, _texId);
	glTexImage2D(
                 GL_TEXTURE_2D, 0,
                 GL_RGBA, _w, _h, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, _texData);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    _pSprite->draw();
}