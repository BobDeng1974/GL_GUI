#include "OrthoMatrix.h"

glm::mat3 OrthoMatrix::projection;

void OrthoMatrix::set(float width, float height)
{
    projection = glm::mat3(
                                    glm::vec3(1.0f / width, 0, 0),
                                    glm::vec3(0, 1.0f / height, 0),
                                    glm::vec3(-1, -1, 1)
                                );
}

