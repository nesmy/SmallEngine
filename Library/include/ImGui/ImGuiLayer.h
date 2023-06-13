#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Small {

    class SMALL_API ImGuiLayer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);
    private:
        float m_Time = 0.0f;
    };
}