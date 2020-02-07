#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		
	uint8_t step;
	uint16_t vVoltage;
	uint16_t vSpeed;
	uint16_t vExtend;
	uint16_t vRetract;
	uint16_t vDelay;
	uint16_t vLoop;
	uint16_t vRepeat;
	uint16_t vJump;
	uint16_t vCycle;
	uint16_t temp;
	uint32_t vTotalCycle;

	uint8_t pCnt;
	char command[1500];
	Unicode::UnicodeChar cmd[1500];
	float voltage;


	enum BtnStatusSet {Ready, setSpeed, setExtend, setRetract, setDelay, setLoop, setRepeat, setJump, setCycle};
	BtnStatusSet BtnStatus;
	enum MSTATUS { Extending, Retracting, Cycling, Paused, Idle };
	MSTATUS mStatus;

	bool isProgrameMode;
	bool isFullStep;

	int tickCnt;
	virtual void addMotion();
	virtual void addLoop();
	virtual void addJump();
	virtual void handleTickEvent();

			
protected:
	/*
 * Callback Declarations
 */
	touchgfx::Callback<Screen1View, const touchgfx::AbstractButton&> buttonCallback;

	/*
	 * Callback Handler Declarations
	 */
	void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SCREEN1VIEW_HPP
