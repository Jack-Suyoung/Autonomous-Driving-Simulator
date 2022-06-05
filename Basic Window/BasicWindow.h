#pragma once

#define SIMULATOR_WIDTH 1080
#define SIMULATOR_HEIGHT 760


class RectButton {
public:
	int8_t s8PressedState;
	float32_t f32xPos;
	float32_t f32yPos;
	float32_t f32Width;
	float32_t f32Height;
	char arch32Name[10];
	GLfloat ColorR;
	GLfloat ColorG;
	GLfloat ColorB;
	GLfloat Brightness;

	void Initialize();
	void DrawButton();
	void UpdateState();
	
};

void RectButton::DrawButton()
{
	glBegin(GL_POLYGON);
	glColor4f(ColorR, ColorG, ColorB, Brightness);
	glVertex3f(f32xPos, f32yPos, 0.0f);
	glVertex3f(f32xPos + f32Width, f32yPos, 0.0f);
	glVertex3f(f32xPos + f32Width, f32yPos + f32Height, 0.0f);
	glVertex3f(f32xPos, f32yPos + f32Height, 0.0f);
	glEnd();
}

void RectButton::UpdateState()
{
	if (s8PressedState == 0)
	{
		s8PressedState = 1;
		ColorR = 0.0f;
		ColorG = 0.5f;
		ColorB = 1.0f;
		Brightness = 1.0f;
		printf("%s Button is On pressed \n", arch32Name);
	}
	else
	{
		s8PressedState = 0;
		ColorR = 0.5f;
		ColorG = 0.5f;
		ColorB = 0.5f;
		Brightness = 0.3f;
		printf("%s Button is OFF pressed \n", arch32Name);
	}
}

void RectButton::Initialize()
{
	if (s8PressedState == 0)
	{
		ColorR = 0.5f;
		ColorG = 0.5f;
		ColorB = 0.5f;
		Brightness = 0.3f;
	}
	else
	{
		ColorR = 0.5f;
		ColorG = 0.5f;
		ColorB = 0.5f;
		Brightness = 0.3f;
	}
}