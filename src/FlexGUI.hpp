#ifndef FLEXIUM_IMGUI_FLEX_GUI_HPP
#define FLEXIUM_IMGUI_FLEX_GUI_HPP

#include <Flexium/Object.hpp>

class FlexGUI : public flx::Object {

	private:

	public:

		virtual void onCreate();	
		virtual void onUpdate();
		virtual void onDraw();

		virtual ~FlexGUI() {};

};

#endif