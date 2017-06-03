#ifndef LABEL_H
#define LABEL_H

#include <string>

#include "Math2d.h"
#include "Texture.h"

class LabelBase
{
protected:
    glm::vec2 coords, size;
    LabelBase(const glm::vec2& _coords, const glm::vec2& _size);

public:
    const glm::vec2& getCoords() const { return this->coords; }
    const glm::vec2& getSize() const { return this->size; }
};

template<typename T> class Label {};

template<>
class Label<Texture> : public LabelBase
{
private:
    Texture texture;

public:
    Label(const glm::vec2& coords, const glm::vec2& size, const char* texture_path);
    
    const Texture& getTexture() const { return this->texture; }
};

template<>
class Label<std::string> : public LabelBase
{
private:
    std::string text;

public:
    Label(const glm::vec2& coords, const glm::vec2& size, const char* str);

    void setText(const char* str);
    const std::string& getText() const { return this->text; }
};

#endif
