#pragma once

extern Small::Application* Small::CreateApplication();

int main(int argc, char** argv)
{
    Small::Log::Init();
    SE_CORE_WARN("Log Init");
    SE_INFO("Client Log");
    auto app = Small::CreateApplication();
    app->Run();
    delete app;
}