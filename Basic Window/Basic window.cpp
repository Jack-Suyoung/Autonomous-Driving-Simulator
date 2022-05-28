// OpenGL 라이브러리 구성은 아래 페이지 설명을 그대로 따라함
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

	// GLFW Window Hint 설정
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OPENGL 버전 x.y 중 x가 4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // OPENGL 버전 x.y 중 y가 6, 즉 4.6 버전 실행
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 더 이상 쓰이지 않는 하위 호환 기능들 에러 처리
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // 상위 호환성 지원

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

	// 빨간 화면 그리기
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// 프로그램 종료
	glfwTerminate();

	return 0;
}