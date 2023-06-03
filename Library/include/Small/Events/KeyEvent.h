#pragma once

#include "Event.h"

namespace Small {

    class SMALL_API KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode;}
    }
}