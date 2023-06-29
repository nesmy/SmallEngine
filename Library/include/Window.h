#pragma once

#include "pch.h"

#include <GLFW/glfw3.h>

namespace Small {

    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Small Engine",
                    unsigned int width = 1280,
                    unsigned int height = 720)
            : Title(title), Width(width), Height(height)
            {

            }
    };

    class Window {
        public:
        Window();
        ~Window();

        void Update();
        void Render();

        private:
        GLFWwindow* window;
    };

    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}