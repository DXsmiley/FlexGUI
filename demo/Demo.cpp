#include <Flexium/World.hpp>
#include <Flexium/Window.hpp>
#include <Flexium/Object.hpp>
#include <Flexium/Text.hpp>

#include <FlexiumImGUI.hpp>

class FlexGUITest : public flx::Object {

	private:

		bool show_window;

	public:

		FlexGUITest(): show_window(true) {};

		virtual void onUpdate() {
			// This is a demo built into ImGUI
			ImGui::ShowTestWindow(&show_window);
		}

};

int main() {

	// Create the window
	flx::Window::WindowSettings ws;
	ws.title = "Flexium and ImGUI";
	flx::Window::setClearColor(sf::Color::White);
	flx::Window::initiate(ws);

	// Load resources
	flx::Text::loadMapping("fontsheet.xml");

	// Setup the world
	flx::World world;


	world.instanceAdd(new FlexGUI());
	
	// This is our interface.
	world.instanceAdd(new FlexGUITest());
	
	while (world.simulate());

}