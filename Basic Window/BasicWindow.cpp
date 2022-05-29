// OpenGL 라이브러리 구성은 아래 페이지 설명을 그대로 따라함
// https://kyoungwhankim.github.io/ko/blog/opengl_install/

#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "types.h"


int ViewreMain(void);


int ViewreMain(void)
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

	// GLFW Window Hint 설정
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OPENGL 버전 x.y 중 x가 4
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // OPENGL 버전 x.y 중 y가 6, 즉 4.6 버전 실행
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 더 이상 쓰이지 않는 하위 호환 기능들 에러 처리
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // 상위 호환성 지원

	// Window 만들기
	GLFWwindow* window = glfwCreateWindow(1080, 720, "Autonomous Driving Simulator", NULL, NULL); // 창을 만들고 context 생성
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	else
	{
		// Do Nothing
	}

	glfwMakeContextCurrent(window); // OpenGL Context를 current context로 만들어줌

	// Viewport 만들기
	// window는 우리가 무언가를 그릴 수 있는 도화지임, 도화지의 어느 부분에 그림을 그릴것인지 설정하는 것이 viewport임.
	int framebuf_width, framebuf_height;
	glfwGetFramebufferSize(window, &framebuf_width, &framebuf_height);
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

	GLfloat lineVertices[] =
	{
		400, 200, 0,
		100, 300, 0
	};

	// 빨간 화면 그리기
	while (!glfwWindowShouldClose(window))
	{
		//glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_LINE_STRIP);
		glLineWidth(10);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glVertex3f(200.0f, 100.0f, 0.0f);
		glVertex3f(100.0f, 300.0f, 0.0f);
		glEnd();

		//glBegin(GL_LINE_STRIP);
		//glLineWidth(10);
		//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		//glVertex3f(400.0f, 200.0f, 0.0f);
		//glVertex3f(100.0f, 300.0f, 0.0f);
		//glEnd();
		glEnableClientState(GL_VERTEX_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, lineVertices);
		glDrawArrays(GL_LINES, 0, 2);
		

		glDisableClientState(GL_VERTEX_ARRAY);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	// 프로그램 종료
	glfwTerminate();

	return 0;
}