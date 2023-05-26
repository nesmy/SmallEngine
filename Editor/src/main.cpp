#include "small.h"
#include <iostream>
using namespace small;

int main()
{
    SmallInfo("Load Editor");
    
    Window window = Window(800, 600, "Test");

    window.create();

    while (!glfwWindowShouldClose(window._Window))
    {
        SmallInfo("1");
        // Process events
        glfwPollEvents();

        SmallInfo("2");
        // Start ImGui frame
        SmallInfo("IMGUI");
        glfwPollEvents();
       // Create a window called "My First Tool", with a menu bar.
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.render();
        

        SmallInfo("3");
        //swap buffers
        glfwSwapBuffers(window._Window);
    }

    //clean up and exit
    glfwTerminate();

    SmallInfo("end prog");
    return 0;
}