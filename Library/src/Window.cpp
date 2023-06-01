#include "Window.h"
#include "Log.h"
#include "imgui.h"
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace small {

    void framebufferSizeCallback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
    {
        /*
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);

        if (Window::firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        camera.ProcessMouseMovement(xoffset, yoffset);
        */
    }

    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
    {
        //camera.ProcessMouseScroll(static_cast<float>(yoffset));
    }

    void processInput(GLFWwindow *window)
    {
        /*
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS):
        camera.ProcessKeyboard(RIGHT, deltaTime);
        */
    }

    Window::Window(int Width,int Height, const char* Name)
    {
        _Width = Width;
        _Height = Height;
        _Name = Name;
        camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
       // Shader ourShader;

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

        #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif

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
        glfwSetFramebufferSizeCallback(_Window, framebufferSizeCallback);
        glfwSetCursorPosCallback(_Window, mouse_callback);
        glfwSetScrollCallback(_Window, scroll_callback);
        
        //glfwSwapInterval(1);

        // Initialize Glad
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            SmallWarn("Failed to initialize Glad");
            glfwTerminate();
            return;
        }
        // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
        //stbi_set_flip_vertically_on_load(true);


        // Initialize ImGui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        // Setup ImGui bindings
        ImGui_ImplGlfw_InitForOpenGL(_Window, true);
        ImGui_ImplOpenGL3_Init("#version 330");

       
    

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

        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(_Window);
        // don't forget to enable shader before setting uniforms
        ourShader.use();

        // Rendering
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)_Width / (float)_Height, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
        ourShader.setMat4("model", model);
        ourModel.Draw(ourShader);
    
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
