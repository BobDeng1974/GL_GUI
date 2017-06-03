#version 330

in vec2 _uv;

uniform sampler2D tex;

out vec4 _out;

void main()
{
    _out = texture(tex, _uv);
}

