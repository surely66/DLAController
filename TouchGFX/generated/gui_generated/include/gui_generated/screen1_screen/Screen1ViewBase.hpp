/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1VIEWBASE_HPP
#define SCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/ModalWindow.hpp>
#include <touchgfx/Color.hpp>

#include <touchgfx/widgets/RadioButtonGroup.hpp>
class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void setVoltage(int value)
    {
        // Override and implement this function in Screen1
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box boxBackground;
    touchgfx::ToggleButton ProgrameBtn;
    touchgfx::Slider sliderVoltage;
    touchgfx::Box boxVoltage;
    touchgfx::TextArea textArea1;
    touchgfx::TextAreaWithOneWildcard dVoltage;
    touchgfx::TextArea textArea2;
    touchgfx::TextArea textArea3;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::TextArea textArea4;
    touchgfx::RadioButton radioButtonFS;
    touchgfx::RadioButton radioButtonHS;
    touchgfx::TextArea textArea5;
    touchgfx::RadioButton radioButtonExtend;
    touchgfx::TextArea textArea6;
    touchgfx::RadioButton radioButtonRetract;
    touchgfx::ButtonWithLabel ExtendBtn;
    touchgfx::Button inputExtend;
    touchgfx::TextAreaWithOneWildcard dExtend;
    touchgfx::ButtonWithLabel RetractBtn;
    touchgfx::ButtonWithLabel AddMotionBtn;
    touchgfx::ButtonWithLabel AddLoopBtn;
    touchgfx::ButtonWithLabel AddJumpBtn;
    touchgfx::Button inputRetract;
    touchgfx::TextAreaWithOneWildcard dRetract;
    touchgfx::Button inputSpeed;
    touchgfx::TextAreaWithOneWildcard dSpeed;
    touchgfx::TextArea textArea7_1;
    touchgfx::TextArea textArea7_1_1;
    touchgfx::TextArea textArea7_1_1_1;
    touchgfx::Box box1;
    touchgfx::Line line1_1;
    touchgfx::PainterRGB565 line1_1Painter;
    touchgfx::TextArea title1;
    touchgfx::TextArea title2;
    touchgfx::TextArea textArea7_2;
    touchgfx::Button inputDelay;
    touchgfx::TextAreaWithOneWildcard dDelay;
    touchgfx::TextArea textArea7_2_1;
    touchgfx::Button inputLoop;
    touchgfx::TextAreaWithOneWildcard dLoop;
    touchgfx::TextArea textArea7_2_1_1;
    touchgfx::Button inputRepeat;
    touchgfx::TextAreaWithOneWildcard dRepeat;
    touchgfx::TextArea textArea7_2_1_1_1;
    touchgfx::Button inputJump;
    touchgfx::TextAreaWithOneWildcard dJump;
    touchgfx::TextArea textArea7_2_1_1_2;
    touchgfx::Button inputCycle;
    touchgfx::TextAreaWithOneWildcard dCycle;
    touchgfx::TextArea textArea7_2_1_1_1_1;
    touchgfx::ButtonWithLabel AutoBtn;
    touchgfx::ButtonWithLabel StartBtn;
    touchgfx::ButtonWithLabel StopBtn;
    touchgfx::ButtonWithLabel ClearBtn;
    touchgfx::Box boxMotor_1;
    touchgfx::TextAreaWithOneWildcard dTotalCycle;
    touchgfx::TextArea textArea2_2;
    touchgfx::TextAreaWithOneWildcard displayCmd;
    touchgfx::ModalWindow modalWindow;
    touchgfx::ButtonWithLabel D7;
    touchgfx::ButtonWithLabel D4;
    touchgfx::ButtonWithLabel D1;
    touchgfx::ButtonWithLabel D8;
    touchgfx::ButtonWithLabel D5;
    touchgfx::ButtonWithLabel D2;
    touchgfx::ButtonWithLabel D9;
    touchgfx::ButtonWithLabel D6;
    touchgfx::ButtonWithLabel D3;
    touchgfx::ButtonWithLabel D0;
    touchgfx::ButtonWithLabel DEL;
    touchgfx::ButtonWithLabel DOK;

    touchgfx::RadioButtonGroup<2> radioButtonGroupMode;
    touchgfx::RadioButtonGroup<2> radioButtonGroupDir;

    /*
     * Wildcard Buffers
     */
    static const uint16_t DVOLTAGE_SIZE = 5;
    touchgfx::Unicode::UnicodeChar dVoltageBuffer[DVOLTAGE_SIZE];
    static const uint16_t DEXTEND_SIZE = 6;
    touchgfx::Unicode::UnicodeChar dExtendBuffer[DEXTEND_SIZE];
    static const uint16_t DRETRACT_SIZE = 6;
    touchgfx::Unicode::UnicodeChar dRetractBuffer[DRETRACT_SIZE];
    static const uint16_t DSPEED_SIZE = 6;
    touchgfx::Unicode::UnicodeChar dSpeedBuffer[DSPEED_SIZE];
    static const uint16_t DDELAY_SIZE = 6;
    touchgfx::Unicode::UnicodeChar dDelayBuffer[DDELAY_SIZE];
    static const uint16_t DLOOP_SIZE = 6;
    touchgfx::Unicode::UnicodeChar dLoopBuffer[DLOOP_SIZE];
    static const uint16_t DREPEAT_SIZE = 6;
    touchgfx::Unicode::UnicodeChar dRepeatBuffer[DREPEAT_SIZE];
    static const uint16_t DJUMP_SIZE = 6;
    touchgfx::Unicode::UnicodeChar dJumpBuffer[DJUMP_SIZE];
    static const uint16_t DCYCLE_SIZE = 6;
    touchgfx::Unicode::UnicodeChar dCycleBuffer[DCYCLE_SIZE];
    static const uint16_t DTOTALCYCLE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar dTotalCycleBuffer[DTOTALCYCLE_SIZE];
    static const uint16_t DISPLAYCMD_SIZE = 1500;
    touchgfx::Unicode::UnicodeChar displayCmdBuffer[DISPLAYCMD_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen1ViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<Screen1ViewBase, const touchgfx::Slider&, int> sliderValueChangedCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 15360;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // SCREEN1VIEWBASE_HPP
