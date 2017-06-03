#include <stdio.h>

#include "Quad.h"
#include "Window.h"
#include "OrthoMatrix.h"
#include "ImageRenderer.h"

int main(int argc, char** argv)
{
    puts("Init");
    
    Window window = Window("Window", 1024, 768);
    KeyboardState keyboard = window.getKeyboardState();

    OrthoMatrix::set(1024, 768);
    Quad::init();
    ImageRenderer renderer;
    renderer.load();

    Label<Texture> image = Label<Texture>(glm::vec2(0, 0), glm::vec2(128, 128), "/Users/Jas/Documents/Libraries/GL_GUI/src/test/hi.tga");

    bool running = true;
    SDL_Event event;

    while(running)
    {
        while(window.poll(event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }

        renderer.render(image);
        if(keyboard[SDL_SCANCODE_ESCAPE]) running = false;
        window.swap_buffers();
    }

    renderer.destroy();
    Quad::destroy();

    puts("Terminate");
    return 0;
}
