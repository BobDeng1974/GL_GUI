#include "Label.h"

LabelBase::LabelBase(const glm::vec2& _coords, const glm::vec2& _size) {
    this->coords = _coords;
    this->size = _size;
}

Label<Texture>::Label(const glm::vec2& coords, const glm::vec2& size, const char* texture_path) : LabelBase(coords, size)
{
    this->texture.load(texture_path);
}

Label<std::string>::Label(const glm::vec2& coords, const glm::vec2& size, const char* str) : LabelBase(coords, size)
{
    this->text = str;
}

