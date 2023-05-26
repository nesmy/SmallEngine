#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

namespace small {
    class Window 
    {
    public:
        Window(int Width, int Height, const char* Name);
        ~Window();
        void create();
        void destroy();
        void render();
        GLFWwindow* _Window;
    private:
        int _Width, _Height;
        const char* _Name;
        Shader shader;
        unsigned int VBO;
        unsigned int VAO;
        unsigned int shaderProgram;
    };
}