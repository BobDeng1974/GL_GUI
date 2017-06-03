#ifndef ORTHO_MATRIX_H
#define ORTHO_MATRIX_H

#include "Math2d.h"

/*

Orthographic matrix for screen projection.
Layout of the screen:

  (0,1)       (1,1)
     O----------O
     |          |
     |          |
     |          |
     |          |
     O----------O
  (0,0)        (1,0)
*/

namespace OrthoMatrix
{
    extern glm::mat3 projection;

    void set(float width, float height);
};

#endif
