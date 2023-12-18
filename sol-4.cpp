#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawGlassCup() {
    // Your drawing code for the glass cup using OpenGL commands
}

void drawPen() {
    // Your drawing code for the pen using OpenGL commands
}

void drawBasketball() {
    // Your drawing code for the basketball using OpenGL commands
}

void drawBatteryPack() {
    // Your drawing code for the battery pack using OpenGL commands
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set up the camera
    gluLookAt(3.0, 3.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Draw the objects
    drawGlassCup();
    drawPen();
    drawBasketball();
    drawBatteryPack();

    glfwSwapBuffers(window);
}

int main() {
    // Initialize GLFW and GLEW
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Objects", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, (double)width / height, 1.0, 10.0);
        glMatrixMode(GL_MODELVIEW);
    });

    while (!glfwWindowShouldClose(window)) {
        display();
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
