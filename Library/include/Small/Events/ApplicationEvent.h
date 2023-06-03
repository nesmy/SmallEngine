#pragma once

#include "Event.h"

namespace Small {

    class SMALL_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        inline unsigned int GetWidth() const { return m_Width;}
        inline unsigned int GetHeight()const { return m_Height;}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << "," << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
    private:
        unsigned int m_Width, m_Height;
    };

    class SMALL_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
    };

    class SMALL_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate)
    };

    class SMALL_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
    };
}