#pragma once 

#include "Event.h"


namespace Small {

    class SMALL_API MouseMovedEvent : public Event
    {
        public:
            MouseMovedEvent(float x, float y)
                : m_MouseX(x), m_MouseY(y) {}

            inline float GetX() const { return m_MouseX;}
            inline float GetY() const { return m_MouseY;}

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseMoved)
            //static EventType GetStaticType() { return EventType::MouseMoved;}\
            virtual EventType GetEventType() const override { return GetStaticType();}\
            virtual const char* GetName() const override { return "MouseMoved";}
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        private:
            float m_MouseX, m_MouseY;
    };

    class SMALL_API MouseScrolledEvent : public Event
    {
        public:
            MouseScrolledEvent(float xOffset, float yOffset)
                : m_XOffset(xOffset), m_YOffset(yOffset) {}

            inline float GetXOffset() const { return m_XOffset;}
            inline float GetYOffset() const { return m_YOffset;}

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseScrolled)
            //static EventType GetStaticType() { return EventType::MouseMoved;}\
            virtual EventType GetEventType() const override { return GetStaticType();}\
            virtual const char* GetName() const override { return "MouseMoved";}
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        private:
            float m_XOffset, m_YOffset;
    };

    class SMALL_API MouseButtonEvent : public Event
    {
        public:
            inline int GetMouseButton() const { return m_Button;}

            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
        protected:
            MouseButtonEvent(int button)
                : m_Button(button) {}

            int m_Button;
    };

    class SMALL_API MouseButtonPressedEvent : public MouseButtonEvent
    {
        public:
            MouseButtonPressedEvent(int button)
                : MouseButtonEvent(button) {}
            
            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "MouseButtonPressedEvent: " << m_Button;
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseButtonPressed)
            //static EventType GetStaticType() { return EventType::MouseButtonPressed;}\
            virtual EventType GetEventType() const override { return GetStaticType();}\
            virtual const char* GetName() const override { return "MouseButtonPressed";}
    };

    class SMALL_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
        public:
            MouseButtonReleasedEvent(int button)
                : MouseButtonEvent(button) {}

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "MouseButtonReleasedEvent: " << m_Button;
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseButtonReleased)
            //static EventType GetStaticType() { return EventType::MouseButtonReleased;}\
            virtual EventType GetEventType() const override { return GetStaticType();}\
            virtual const char* GetName() const override { return "MouseButtonReleased";}
    };
}
