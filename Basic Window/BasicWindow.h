#pragma once

#define SIMULATOR_WIDTH 1080
#define SIMULATOR_HEIGHT 760

typedef struct tRectButton
{
	float32_t f32xPos;
	float32_t f32yPos;
	float32_t f32Width;
	float32_t f32Height;
	int8_t s8OnPressed;
}RectButton_t;