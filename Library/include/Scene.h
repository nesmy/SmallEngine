#include <vector>
#include "Entity.h"
namespace small {
    class Scene {
public:
    // Constructor
    Scene();

    // Destructor
    ~Scene(){
        // Cleanup all entities
        for (auto entity : entities) {
            delete entity;
        }
    }

    // Scene initialization method
    void Initialize();

    // Scene update method
    void Update(float deltaTime);

    // Scene rendering method
    void Render();

    // Create and add a new entity to the scene
    Entity* CreateEntity() {
        Entity* entity = new Entity();
        entities.push_back(entity);
        return entity;
    }
private:
    std::vector<Entity*> entities;  // Container to store entities
};

}