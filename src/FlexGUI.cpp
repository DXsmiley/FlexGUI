#include "FlexGUI.hpp"

#include <Flexium/Window.hpp>
#include <Flexium/Input.hpp>
#include <Flexium/Console.hpp>

#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

void FlexGUI::onCreate() {
	setMeta(true);
	setDepth(-100);
	ImGui::SFML::SetWindow(*flx::Window::getHandle());
	ImGui::SFML::InitImGui();
}

void FlexGUI::onUpdate() {
	ImGui::SFML::UpdateImGui();
	// Pass keyboard events to ImGUI
	ImGuiIO& io = ImGui::GetIO();
	for (int i = 0; i < flx::Input::Key::KeyCount; ++i) {
		io.KeysDown[i] = flx::Input::keyDown(i);
		io.KeyCtrl = flx::Input::keyDownEx(flx::Input::Key::ExControl);
		io.KeyShift = flx::Input::keyDownEx(flx::Input::Key::ExShift);
	}
	if (flx::Input::characterTyped() != '\0') {
		io.AddInputCharacter(flx::Input::characterTyped());
	}
}

void FlexGUI::onDraw() {
	ImGui::Render();
}