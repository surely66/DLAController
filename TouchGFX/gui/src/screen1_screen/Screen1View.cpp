#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <string.h>
#include <stdio.h>
#include <main.h>


 Screen1View::Screen1View():
 	buttonCallback(this, &Screen1View::buttonCallbackHandler)
{
	step = 0;
	vVoltage = 0;
	vSpeed = 0;
	vExtend = 0;
	vRetract = 0;
	vDelay = 0;
	vLoop = 0;
	vRepeat = 0;
	vJump = 0;
	vCycle = 0;
	vTotalCycle = 0;
	temp = 0;

	BtnStatus = Ready;
	mStatus = Idle;
	isProgrameMode = false;
	isFullStep = true;

	pCnt = 0;
	voltage = 12.5f;

	tickCnt = 0;
	ExtendBtn.setAction(buttonCallback);
	RetractBtn.setAction(buttonCallback);

	ProgrameBtn.setAction(buttonCallback);
	AddMotionBtn.setAction(buttonCallback);
	AddLoopBtn.setAction(buttonCallback);
	AddJumpBtn.setAction(buttonCallback);

	StartBtn.setAction(buttonCallback);
	StopBtn.setAction(buttonCallback);
	ClearBtn.setAction(buttonCallback);

	inputSpeed.setAction(buttonCallback);
	inputExtend.setAction(buttonCallback);
	inputRetract.setAction(buttonCallback);
	inputDelay.setAction(buttonCallback);
	inputLoop.setAction(buttonCallback);
	inputRepeat.setAction(buttonCallback);
	inputJump.setAction(buttonCallback);
	inputCycle.setAction(buttonCallback);

	D0.setAction(buttonCallback);
	D1.setAction(buttonCallback);
	D2.setAction(buttonCallback);
	D3.setAction(buttonCallback);
	D4.setAction(buttonCallback);
	D5.setAction(buttonCallback);
	D6.setAction(buttonCallback);
	D7.setAction(buttonCallback);
	D8.setAction(buttonCallback);
	D9.setAction(buttonCallback);
	DEL.setAction(buttonCallback);
	DOK.setAction(buttonCallback);

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}


void Screen1View::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{

	if (BtnStatus == Ready)
	{
		if (&src == &ProgrameBtn)
		{
			isProgrameMode = ProgrameBtn.getState();
			if (isProgrameMode == true)
			{
				ExtendBtn.setVisible(false);
				ExtendBtn.invalidate();
				RetractBtn.setVisible(false);
				RetractBtn.invalidate();
				radioButtonRetract.setVisible(true);
				radioButtonRetract.invalidate();
				radioButtonExtend.setVisible(true);
				radioButtonExtend.invalidate();
			}
			else if (isProgrameMode == false)
			{
				ExtendBtn.setVisible(true);
				ExtendBtn.invalidate();
				RetractBtn.setVisible(true);
				RetractBtn.invalidate();
				radioButtonRetract.setVisible(false);
				radioButtonRetract.invalidate();
				radioButtonExtend.setVisible(false);
				radioButtonExtend.invalidate();
			}

		}
		else if (&src == &inputSpeed)
		{

			modalWindow.setVisible(true);
			modalWindow.invalidate();
			BtnStatus = setSpeed;
			temp = 0;
		}
		else if (&src == &inputExtend)
		{

			modalWindow.setVisible(true);
			modalWindow.invalidate();
			BtnStatus = setExtend;
			temp = 0;
		}
		else if (&src == &inputRetract)
		{

			modalWindow.setVisible(true);
			modalWindow.invalidate();
			BtnStatus = setRetract;
			temp = 0;
		}
		else if (isProgrameMode == false)
		{

			if(&src == &ExtendBtn)
			{
				touchgfx_printf("Extend Motion\n");
			}
			else if (&src == &RetractBtn)
			{
				touchgfx_printf("Retract Motion\n");
			}

		}
		else if (isProgrameMode == true)
		{

			if (&src == &inputDelay)
			{

				modalWindow.setVisible(true);
				modalWindow.invalidate();
				BtnStatus = setDelay;
				temp = 0;
			}
			else if (&src == &inputLoop)
			{

				modalWindow.setVisible(true);
				modalWindow.invalidate();
				BtnStatus = setLoop;
				temp = 0;
			}
			else if (&src == &inputRepeat)
			{

				modalWindow.setVisible(true);
				modalWindow.invalidate();
				BtnStatus = setRepeat;
				temp = 0;
			}
			else if (&src == &inputJump)
			{

				modalWindow.setVisible(true);
				modalWindow.invalidate();
				BtnStatus = setJump;
				temp = 0;
			}
			else if (&src == &inputCycle)
			{

				modalWindow.setVisible(true);
				modalWindow.invalidate();
				BtnStatus = setCycle;
				temp = 0;
			}
			else if ((&src == &AddMotionBtn) && (BtnStatus == Ready))
			{
				Screen1View::addMotion();
			}
		}

	}

	else if(BtnStatus !=Ready)
	{
		if (&src == &D0)
		{
		temp = temp * 10;
		}
		else if (&src == &D1)
		{
		temp = temp * 10 + 1;
		}
		else if (&src == &D2)
		{
		temp = temp * 10 + 2;
		}
		else if (&src == &D3)
		{
		temp = temp * 10 + 3;
		}
		else if (&src == &D4)
		{
		temp = temp * 10 + 4;
		}
		else if (&src == &D5)
		{
		temp = temp * 10 + 5;
		}
		else if (&src == &D6)
		{
		temp = temp * 10 + 6;
		}
		else if (&src == &D7)
		{
		temp = temp * 10 + 7;
		}
		else if (&src == &D8)
		{
		temp = temp * 10 + 8;
		}
		else if (&src == &D9)
		{
		temp = temp * 10 + 9;
		}
		else if (&src == &DEL)
		{
		temp = temp / 10;
		}
		else if (&src == &DOK)
		{

			if (BtnStatus == setSpeed)
			{
				vSpeed = temp;
				Unicode::snprintf(dSpeedBuffer, DSPEED_SIZE, "%d", vSpeed);
				dSpeed.invalidate();
			}
			else if (BtnStatus == setExtend)
			{
				vExtend = temp;
				Unicode::snprintf(dExtendBuffer, DEXTEND_SIZE, "%d", vExtend);
				dExtend.invalidate();
			}
			else if (BtnStatus == setRetract)
			{
				vRetract = temp;
				Unicode::snprintf(dRetractBuffer, DRETRACT_SIZE, "%d", vRetract);
				dRetract.invalidate();
			}
			else if (BtnStatus == setDelay)
			{
				vDelay = temp;
				Unicode::snprintf(dDelayBuffer, DDELAY_SIZE, "%d", vDelay);
				dDelay.invalidate();
			}
			else if (BtnStatus == setLoop)
			{
				vLoop = temp;
				Unicode::snprintf(dLoopBuffer, DLOOP_SIZE, "%d", vLoop);
				dLoop.invalidate();
			}
			else if (BtnStatus == setRepeat)
			{
				vRepeat = temp;
				Unicode::snprintf(dRepeatBuffer, DREPEAT_SIZE, "%d", vRepeat);
				dRepeat.invalidate();
			}
			else if (BtnStatus == setJump)
			{
				vJump = temp;
				Unicode::snprintf(dJumpBuffer, DJUMP_SIZE, "%d", vJump);
				dJump.invalidate();
			}
			else if (BtnStatus == setCycle)
			{
				vCycle = temp;
				Unicode::snprintf(dCycleBuffer, DCYCLE_SIZE, "%d", vCycle);
				dCycle.invalidate();
			}
			
			temp = 0;
			BtnStatus = Ready;
			modalWindow.setVisible(false);
			modalWindow.invalidate();

		}

	}


}

void Screen1View::addMotion()
{
	char cmdLine[100];
	char mode[5];
	char dir[3];
	uint16_t temp;
	pCnt++;
	if (radioButtonFS.getSelected()) strcpy(mode, "FS");
	else strcpy(mode, "HS");
	if (radioButtonExtend.getSelected())
	{
		strcpy(dir, "+ ");
		temp = vExtend;
	}
	else
	{
		strcpy(dir, "- ");
		temp = vRetract;
	}

	sprintf(cmdLine, "P%d - %.1fV %s %dPPS %s %d Steps %d ms\n", pCnt,voltage, mode,vSpeed,dir,temp,vDelay );
	strcat(command, cmdLine);
	Unicode::fromUTF8((uint8_t *)command, cmd, 0xffff);
	Unicode::snprintf(displayCmdBuffer, DISPLAYCMD_SIZE, "%s", cmd);
	displayCmd.invalidate();

}


void Screen1View::addLoop()
{


}

void Screen1View::addJump()
{


}

void	Screen1View::handleTickEvent()
{






}