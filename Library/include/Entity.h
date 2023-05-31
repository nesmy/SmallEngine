#include <iostream>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>
namespace small
{
    // Component base class
    class Component 
    {
    public:
        virtual ~Component() {}
    };

    // Entity class
    class Entity
    {
    public:
        template<typename T>
        T* AddComponent(T* component)
        {
            component[std::type_index(typeid(T))] = component;
            return component;
        }

        template<typename T>
        T* GetComponent() {
        auto it = components.find(std::type_index(typeid(T)));
        if (it != components.end()) {
            return dynamic_cast<T*>(it->second);
        }
        return nullptr;
        }

    private:
        std::unordered_map<std::type_index, Component*> components;
    };
    
} // namespace small

