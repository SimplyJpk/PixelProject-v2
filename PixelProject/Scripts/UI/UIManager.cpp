#include "UIManager.h"

#include <cstdlib>

#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "backends/imgui_impl_opengl3.h"

void UIManager::Init(SDL_Window* window, SDL_GLContext glContext)
{
    _window = window;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(window, glContext);
    ImGui_ImplOpenGL3_Init("#version 130");

    // ImGui::SetWindowSize("Debug Window", ImVec2(240, 240));
    // ImGui::SetWindowPos("Debug Window", ImVec2(static_cast<float>(245), 15));
}

void UIManager::DrawGUI()
{
    ImGui::Begin("Debug Window");
    
    ImGui::Text("Random Number: %d", rand() % 100);

    ImGui::End();
}

void UIManager::BeginFrame() const
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(_window);
    ImGui::NewFrame();
}

void UIManager::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


UIManager::~UIManager()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}
