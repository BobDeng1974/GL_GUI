#ifndef IMAGE_RENDERER_H
#define IMAGE_RENDERER_H

#include "Quad.h"
#include "Label.h"
#include "Shader.h"
#include "OrthoMatrix.h"

class ImageRenderer : public Shader
{
private:
    GLuint tex, mat;

public:
    ImageRenderer(){}
    void load();
    void render(const Label<Texture>& label);
    void destroy();
};

#endif
