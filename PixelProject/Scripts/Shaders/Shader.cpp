#include "Shader.h"
#include <unordered_map>
#include <stdexcept>

Shader::Shader(const GLuint program_id)
    : _program(program_id), _name(DEFAULT_SHADER_NAME)
{
}

Shader::Shader(const GLuint program_id, const std::string& name)
    : _program(program_id)
    , _name(name)
{
}

Shader::~Shader()
{
    glDeleteProgram(_program);
}

void Shader::UseProgram() const
{
   glUseProgram(_program);
}

GLuint Shader::GetProgramID() const
{
   return _program;
}

GLuint Shader::GetUniformLocation(const std::string& uniform_name)
{
   // Check if in map already
   const auto i = _uniform_locations.find(uniform_name);
   if (i != _uniform_locations.end())
   {
      return i->second;
   }

   // Check if exists in shader
   auto pos = glGetUniformLocation(_program, uniform_name.c_str());
   if (pos != -1)
   {
      _uniform_locations.insert({ uniform_name, pos });
      return pos;
   }

   // Complain that it doesn't exist
   throw std::runtime_error("Program [" + std::to_string(_program) + " '" + _name + "']: '" + uniform_name + "' does not exist.");
}