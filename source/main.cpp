
#include <iostream>
#include<glad/glad.h>
#include <GLFW/glfw3.h>

int global_width = 700;
int global_height = 700;
/* ������� ��� ��������� �������� ���� */
void glfwWindowSizeCallback(GLFWwindow* window, int width, int height) {
    global_width = width;
    global_height = height;
    glViewport(0, 0, global_width, global_height);
}

/* ������� ��� ����������� ������� ������ */
void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
        /* ���� ���� ������ ������� Escape, �� ���� ���� 
        ��������� � true � ��� �������� � �������, ��� 
        ���������, ���� ����� ������� */
    }
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "glfwInit failed" << std::endl; // ������� ������, ���� ������ �� ���������
        return -1;
    }

    /* ���-�� ������ ������ */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(global_width, global_height, "Game Engine", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    
    glfwSetWindowSizeCallback(window, glfwWindowSizeCallback); // ������ ����� ������� ����, ���� ��� ���� ��������
    glfwSetKeyCallback(window, glfwKeyCallback); // ��������� ������� ������� Escape

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	
    /* ������� ������ ���� ������� �� ���������*/
	if(!gladLoadGL()) {
		std::cout << "Can not load GLAD" << std::endl;
		return -1;
	}
	
    std::cout << "Rendered " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl; // ������� ��������� �������� OpenGL
	glClearColor(0, 1, 0, 1); // ������ ����� ���� ����
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}