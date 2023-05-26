namespace small {

    class Shader
    {
    public:
        unsigned int compileShader(unsigned int type, const char* source);
        unsigned int createShaderProgram(const char* vsource,const char* fsource); 
    };
}