// OpenGL 라이브러리 구성은 아래 페이지 설명을 그대로 따라함
// https://kyoungwhankim.github.io/ko/blog/opengl_install/

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "types.h"
#include "BasicWindow.h"




GLFWwindow* gstWindow;
GLfloat MousePosX;
GLfloat MousePosY;
RectButton stFileButton = { 0 };

int DrawWindowMain(void);
static void cursorPositionCallback(GLFWwindow* pstWindow, double xPos, double yPos);
static void cursorEnterCallback(GLFWwindow* pstWindow, int entered);
static void mouseButtonCallback(GLFWwindow* pstWindow, int button, int action, int mods);
static void scrollCallback(GLFWwindow* pstWindow, double xOffset, double yOffset);
static int8_t MouseIsInRectButton(RectButton* pstButtonSrc);
static void ConvertDeviceXYtoOpenGLXY();


int DrawWindowMain(void)
{
	if (gstWindow == NULL)
	{
		// GLFW Init
		if (!glfwInit())
		{
			exit(EXIT_FAILURE);
		}
		else
		{
			// Do Nothing
		}

		// Window 만들기
		gstWindow = glfwCreateWindow(SIMULATOR_WIDTH, SIMULATOR_HEIGHT, "Autonomous Driving Simulator", NULL, NULL);

		if (!gstWindow)
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		else
		{
			// Do Nothing
		}

		glfwMakeContextCurrent(gstWindow); // OpenGL Context를 current context로 만들어줌

		// Viewport 만들기
		// window는 우리가 무언가를 그릴 수 있는 도화지임, 도화지의 어느 부분에 그림을 그릴것인지 설정하는 것이 viewport임.
		int framebuf_width, framebuf_height;
		glfwGetFramebufferSize(gstWindow, &framebuf_width, &framebuf_height);
		glViewport(0, 0, framebuf_width, framebuf_height); // 첫번째, 두번째 인자는 뷰포트의 좌하단 픽셀의 x, y값
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, framebuf_width, 0, framebuf_height, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// GLEW Init
		// GLEW 초기화는 반드시 OpenGL context를 생성하고, current context로 설정한 이후에 진행해야 함.
		if (glewInit() != GLEW_OK)
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		else
		{
			// Do Nothing
		}

		glfwSetCursorPosCallback(gstWindow, cursorPositionCallback);
		glfwSetInputMode(gstWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

		glfwSetCursorEnterCallback(gstWindow, cursorEnterCallback);

		glfwSetMouseButtonCallback(gstWindow, mouseButtonCallback);
		glfwSetInputMode(gstWindow, GLFW_STICKY_MOUSE_BUTTONS, 1);

		glfwSetScrollCallback(gstWindow, scrollCallback);


		////////////////////////////////////////
		//			Initialize Button		  //
		////////////////////////////////////////
		stFileButton.f32xPos = 10.0f;
		stFileButton.f32yPos = 700.0f;
		stFileButton.f32Width = 80.0f;
		stFileButton.f32Height = 40.0f;
		strcpy_s(stFileButton.arch32Name, "file");
		stFileButton.Initialize();


	}
	else
	{
		// Already Create window
	}



	glClear(GL_COLOR_BUFFER_BIT);


	stFileButton.DrawButton();


	glfwSwapBuffers(gstWindow);
	glfwPollEvents();



	return 0;
}

static void cursorPositionCallback(GLFWwindow* pstWindow, float64_t xPos, float64_t yPos)
{
	MousePosX = (GLfloat)xPos;
	MousePosY = (GLfloat)yPos;

	ConvertDeviceXYtoOpenGLXY();

	std::cout << MousePosX << " : " << MousePosY << std::endl;
}

void cursorEnterCallback(GLFWwindow* gstWindow, int entered)
{
	if (entered)
	{
		std::cout << "Entered Window" << std::endl;
	}
	else
	{
		std::cout << "Left Window" << std::endl;
	}
}

void mouseButtonCallback(GLFWwindow* pstWindow, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Right button press" << std::endl;

		MouseIsInRectButton(&stFileButton);
	}
	else
	{
		// Do Nothing
	}
}

void scrollCallback(GLFWwindow* pstWindow, double xOffset, double yOffset)
{
	std::cout << xOffset << " : " << yOffset << std::endl;
}

int8_t MouseIsInRectButton(RectButton* pstButtonSrc)
{
	int8_t s8RetVal = 0;

	if ((MousePosX > pstButtonSrc->f32xPos)
		&& (MousePosX < (pstButtonSrc->f32xPos + pstButtonSrc->f32Width))
		&& (MousePosY > pstButtonSrc->f32yPos)
		&& (MousePosY < (pstButtonSrc->f32yPos + pstButtonSrc->f32Height)))
	{
		(*pstButtonSrc).UpdateState();

	}
	else
	{
		// Do Nothing
	}

	return s8RetVal;
}


void ConvertDeviceXYtoOpenGLXY()
{
	GLfloat DeviceMousePosX = MousePosX;
	GLfloat DeviceMousePosY = MousePosY;

	MousePosX = DeviceMousePosX;
	MousePosY = -DeviceMousePosY + (SIMULATOR_HEIGHT);
}