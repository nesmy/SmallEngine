#include "Scene.h"
#include <iostream>
#include <vector>

namespace small {

    class SceneManager {
public:
    // Constructor
    SceneManager() : activeScene(nullptr) {}

    // Destructor
    ~SceneManager() {
        // Cleanup all scenes
        for (auto scene : scenes) {
            delete scene;
        }
    }

    // Add a scene to the manager
    void AddScene(Scene* scene) {
        scenes.push_back(scene);
    }

    // Set the active scene
    void SetActiveScene(Scene* scene) {
        activeScene = scene;
        activeScene->Initialize();
    }

    // Get the active scene
    Scene* GetActiveScene() const {
        return activeScene;
    }

private:
    std::vector<Scene*> scenes;  // Container to store all scenes
    Scene* activeScene;          // Pointer to the active scene
};

}