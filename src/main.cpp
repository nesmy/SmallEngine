#include "Small.h"

class SandBox : public Small::Application
{
public:
    SandBox()
    {
       
    }

    ~SandBox()
    {

    }
};

Small::Application* Small::CreateApplication()
{
    return new SandBox();
}