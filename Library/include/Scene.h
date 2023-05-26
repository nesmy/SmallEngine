namespace small {
    class Scene {
public:
    // Constructor
    Scene();

    // Destructor
    ~Scene();

    // Scene initialization method
    void Initialize();

    // Scene update method
    void Update(float deltaTime);

    // Scene rendering method
    void Render();
};

}