#pragma once

#include "Core.h"

#include "Small/Window.h"
#include "Small/LayerStack.h"
#include "Small/Events/Event.h"
#include "Small/Events/ApplicationEvent.h"

namespace Small {
    
    class SMALL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window;}

        inline static Application& Get() { return *s_Instance;}
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    private:
        static Application* s_Instance;
    };

    // to be defined in client
    Application* CreateApplication();
}