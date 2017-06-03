#version 330

in vec2 vertex;

uniform mat3 mat;

out vec2 _uv;

void main()
{
    vec2 v = ((vertex + vec2(1)) * 0.5);
    gl_Position = vec4(mat * vec3(v, 1), 1);
    _uv = v;
}

