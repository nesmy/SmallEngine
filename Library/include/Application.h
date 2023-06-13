#pragma once

#include "Core.h"

#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "ImGui/ImGuiLayer.h"

namespace Small {
    
    class SMALL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        inline Window& GetWindow() { return *m_Window;}

        inline static Application& Get() { return *s_Instance;}
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        ImGuiLayer ImGui;
    private:
        static Application* s_Instance;
    };

    // to be defined in client
    Application* CreateApplication();
}