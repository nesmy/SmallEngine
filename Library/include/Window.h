#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Render/Shader.h"
#include "Camera.h"
#include "Render/Model.h"
//#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

namespace small {
    class Window 
    {
    public:
        Window(int Width, int Height, const char* Name = "SmallEngine");
        ~Window();
        void create();
        void destroy();
        void render();
        GLFWwindow* _Window;
        bool firstMouse = true;
        int _Width, _Height;
        const char* _Name;
        Camera camera;
        float lastX = _Width / 2.0f;
        float lastY = _Height / 2.0f;
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;

    private:

         // build and compile shaders
        // -------------------------
        Shader ourShader = Shader("vertex.vs", "fragment.fs");

        // load models
        // -----------
        Model ourModel = Model("car.obj");

    };
}
