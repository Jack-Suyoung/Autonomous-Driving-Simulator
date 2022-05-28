// OpenGL ���̺귯�� ������ �Ʒ� ������ ������ �״�� ������
// https://kyoungwhankim.github.io/ko/blog/opengl_install/

#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


int main(void)
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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OPENGL ���� x.y �� x�� 4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // OPENGL ���� x.y �� y�� 6, �� 4.6 ���� ����
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // �� �̻� ������ �ʴ� ���� ȣȯ ��ɵ� ���� ó��
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // ���� ȣȯ�� ����

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

	// ���� ȭ�� �׸���
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// ���α׷� ����
	glfwTerminate();

	return 0;
}