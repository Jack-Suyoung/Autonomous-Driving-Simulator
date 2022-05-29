// OpenGL ���̺귯�� ������ �Ʒ� ������ ������ �״�� ������
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

	// GLFW Window Hint ����
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OPENGL ���� x.y �� x�� 4
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // OPENGL ���� x.y �� y�� 6, �� 4.6 ���� ����
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // �� �̻� ������ �ʴ� ���� ȣȯ ��ɵ� ���� ó��
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // ���� ȣȯ�� ����

	// Window �����
	GLFWwindow* window = glfwCreateWindow(1080, 720, "Autonomous Driving Simulator", NULL, NULL); // â�� ����� context ����
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	else
	{
		// Do Nothing
	}

	glfwMakeContextCurrent(window); // OpenGL Context�� current context�� �������

	// Viewport �����
	// window�� �츮�� ���𰡸� �׸� �� �ִ� ��ȭ����, ��ȭ���� ��� �κп� �׸��� �׸������� �����ϴ� ���� viewport��.
	int framebuf_width, framebuf_height;
	glfwGetFramebufferSize(window, &framebuf_width, &framebuf_height);
	glViewport(0, 0, framebuf_width, framebuf_height); // ù��°, �ι�° ���ڴ� ����Ʈ�� ���ϴ� �ȼ��� x, y��
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, framebuf_height, 0, framebuf_width, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// GLEW Init
	// GLEW �ʱ�ȭ�� �ݵ�� OpenGL context�� �����ϰ�, current context�� ������ ���Ŀ� �����ؾ� ��.
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

	// ���� ȭ�� �׸���
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

	// ���α׷� ����
	glfwTerminate();

	return 0;
}