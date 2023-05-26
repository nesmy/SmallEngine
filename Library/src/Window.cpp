#include "Window.h"
#include "Log.h"
#include "imgui.h"
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace small {

    
// Vertex shader source code
const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;

    void main()
    {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
)";

// Fragment shader source code
const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;

    void main()
    {
        FragColor = vec4(1.0, 0.5, 0.2, 1.0);
    }
)";
    void framebufferSizeCallback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    Window::Window(int Width,int Height, const char* Name)
    {
        _Width = Width;
        _Height = Height;
        _Name = Name;
    }

    Window::~Window()
    {

    }

    void Window::create()
    {
        // Init GLFW
        if (!glfwInit()) {
            SmallWarn("Failed to initialize GLFW");
            return;
        }

        // Set GLFW widnow options 
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create a GLFW window
        _Window = glfwCreateWindow(_Width, _Height, _Name, nullptr, nullptr);

        if (!_Window)
        {
            SmallWarn("Failed to create GLFW widnow");
            glfwTerminate();
            return;
        }

        // Set the current context to the created window
        glfwMakeContextCurrent(_Window);
        
        //glfwSwapInterval(1);

        // Initialize Glad
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            SmallWarn("Failed to initialize Glad");
            glfwTerminate();
            return;
        }
        // Set the framebuffer size callback function
        glfwSetFramebufferSizeCallback(_Window, framebufferSizeCallback);


        // Initialize ImGui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        // Setup ImGui bindings
        ImGui_ImplGlfw_InitForOpenGL(_Window, true);
        ImGui_ImplOpenGL3_Init("#version 330");

        // Create and compile the shader program
        shaderProgram = shader.createShaderProgram(vertexShaderSource ,fragmentShaderSource);
        // Vertex data
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    // Create a vertex buffer object (VBO)
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Vertex array object (VAO)
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    }

    void Window::render()
    {
        // Clear the color buffer
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);

        // feed inputs to dear imgui, start new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Rendering
        // Use the shader program
        glUseProgram(shaderProgram);

        // Draw the triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // render your GUI
        ImGui::Begin("Demo window");
        ImGui::Button("Hello!");
        ImGui::End();

        // Render dear imgui into screen
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        int display_w, display_h;
        glfwGetFramebufferSize(_Window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
    }

    void Window::destroy()
    {

    }

}