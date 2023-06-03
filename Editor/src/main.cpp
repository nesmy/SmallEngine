#include "Small.h"

class ExampleLayer : public Small::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {

    }

    void OnUpdate() override
    {
        SE_INFO("ExampleLayer::Update");
    }

    void OnEvent(Small::Event& event) override
    {
        SE_TRACE("{0}", event);
    }
};

class SandBox : public Small::Application
{
public:
    SandBox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Small::ImGuiLayer());
    }

    ~SandBox()
    {

    }
};

Small::Application* Small::CreateApplication()
{
    return new SandBox();
}