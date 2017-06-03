#include "ImageRenderer.h"

void ImageRenderer::load()
{
    ShaderSource source = ShaderSource("/Users/Jas/Documents/Libraries/GL_GUI/src/Shaders/image.vert", "/Users/Jas/Documents/Libraries/GL_GUI/src/Shaders/image.frag");
    this->source(source);
    this->bindAttributeLocation(0, "vertex");
    this->link(source);
    this->mat = this->getUniform("mat");
    this->tex = this->getUniform("tex");
}

void ImageRenderer::render(const Label<Texture>& label)
{
    this->bind();
    glm::mat3 matrix = glm::scale(glm::translate(OrthoMatrix::projection, label.getCoords()), label.getSize());
    Quad::bind();
    label.getTexture().bind(this->tex, 0);
    glUniformMatrix3fv(this->mat, 1, GL_FALSE, &matrix[0][0]);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void ImageRenderer::destroy()
{
    Shader::destroy();
}

