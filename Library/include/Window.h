#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include "Render/Shader.h"
#include "Camera.h"
//#include "Render/Model.h"
//#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "imgui.h"

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
        //Shader ourShader = Shader("vertex.vs", "fragment.fs");

        // load models
        // -----------
        //Model ourModel = Model("car.obj");
        // Our state
        bool show_demo_window = true;
        bool show_another_window = false;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    };
}
