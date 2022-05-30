// OpenGL 라이브러리 구성은 아래 페이지 설명을 그대로 따라함
// https://kyoungwhankim.github.io/ko/blog/opengl_install/

#include <iostream>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "types.h"
#include "BasicWindow.h"


int ViewreMain(void);

GLFWwindow* gstWindow;

static void cursorPositionCallback(GLFWwindow* pstWindow, double xPos, double yPos);
void cursorEnterCallback(GLFWwindow* pstWindow, int entered);
void mouseButtonCallback(GLFWwindow* pstWindow, int button, int action, int mods);
void scrollCallback(GLFWwindow* pstWindow, double xOffset, double yOffset);

int ViewreMain(void)
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
		glOrtho(0, framebuf_height, 0, framebuf_width, 0, 1);
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
	}

	glfwSetCursorPosCallback(gstWindow, cursorPositionCallback);
	glfwSetInputMode(gstWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	glfwSetCursorEnterCallback(gstWindow, cursorEnterCallback);

	glfwSetMouseButtonCallback(gstWindow, mouseButtonCallback);
	glfwSetInputMode(gstWindow, GLFW_STICKY_MOUSE_BUTTONS, 1);

	glfwSetScrollCallback(gstWindow, scrollCallback);

	GLfloat lineVertices[] =
	{
		400, 200, 0,
		100, 300, 0
	};

	GLfloat SquareButton[] =
	{
		10, 1000, 0,
		50, 1000, 0,
		50, 950, 0,
		10, 950, 0
	};

	//GLfloat SquareButton[] =
	//{
	//	400, 200, 0,
	//	100, 300, 0,
	//	200
	//}

	//// 빨간 화면 그리기
	//while (!glfwWindowShouldClose(window))
	//{
		//glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//glBegin(GL_LINE_STRIP);
		//glLineWidth(10);
		//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		//glVertex3f(200.0f, 100.0f, 0.0f);
		//glVertex3f(100.0f, 300.0f, 0.0f);
		//glEnd();


		glEnableClientState(GL_VERTEX_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, lineVertices);
		glDrawArrays(GL_LINES, 0, 2);
		
		glColor4f(0.0f, 1.0f, 1.0f, 0.5f);
		glVertexPointer(3, GL_FLOAT, 0, SquareButton);
		glDrawArrays(GL_POLYGON, 0, 4);

		glDisableClientState(GL_VERTEX_ARRAY);

		glfwSwapBuffers(gstWindow);
		glfwPollEvents();

	//}

	// 프로그램 종료
	//glfwTerminate();

	return 0;
}

static void cursorPositionCallback(GLFWwindow* pstWindow, double xPos, double yPos)
{
	std::cout << xPos << " : " << yPos << std::endl;
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
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		std::cout << "Right button press" << std::endl;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		std::cout << "Right button Released" << std::endl;
	}
}

void scrollCallback(GLFWwindow* pstWindow, double xOffset, double yOffset)
{
	std::cout << xOffset << " : " << yOffset << std::endl;
}