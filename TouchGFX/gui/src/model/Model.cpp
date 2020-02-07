#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <main.h>

Model::Model() : modelListener(0)
{
	mcuLoad = 0;

}

void Model::tick()
{
			mcuLoad = touchgfx::HAL::getInstance()->getMCULoadPct();
}
