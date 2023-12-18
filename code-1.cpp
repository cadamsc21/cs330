#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// GLFW window
GLFWwindow* window;

void setupObjects() {
  // Define vertices for a basketball
  GLfloat basketballVertices[] = {
    // ... // Define vertices for a sphere representing a basketball
  };

  // Define vertices for a pen
  GLfloat penVertices[] = {
    // ... // Define vertices for a cylinder representing a pen
  };

  // Define vertices for a jar of water
  GLfloat jarVertices[] = {
    // ... // Define vertices for a cylinder with a rounded bottom representing a jar of water
  };

  // Create Vertex Buffer Objects (VBOs) and Vertex Array Objects (VAOs)
  GLuint basketballVAO, penVAO, jarVAO, basketballVBO, penVBO, jarVBO;
  glGenVertexArrays(3, &basketballVAO, &penVAO, &jarVAO);
  glGenBuffers(3, &basketballVBO, &penVBO, &jarVBO);

  // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s)

  // Setup basketball
  glBindVertexArray(basketballVAO);
  glBindBuffer(GL_ARRAY_BUFFER, basketballVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(basketballVertices), basketballVertices, GL_STATIC_DRAW);

  // Set attribute pointers for basketball
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
  glEnableVertexAttribArray(0);

  // Unbind VAO and VBO for basketball
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // Setup pen
  glBindVertexArray(penVAO);
  glBindBuffer(GL_ARRAY_BUFFER, penVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(penVertices), penVertices, GL_STATIC_DRAW);

  // Set attribute pointers for pen
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
  glEnableVertexAttribArray(0);

  // Unbind VAO and VBO for pen
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // Setup jar of water
  glBindVertexArray(jarVAO);
  glBindBuffer(GL_ARRAY_BUFFER, jarVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(jarVertices), jarVertices, GL_STATIC_DRAW);

  // Set attribute pointers for jar of water
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
  glEnableVertexAttribArray(0);

  // Unbind VAO and VBO for jar of water
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void render() {
  // Render loop
  while (!glfwWindowShouldClose(window)) {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Render objects
    glUseProgram(shaderProgram); // Use shader program

    // Render basketball
    glBindVertexArray(basketballVAO);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(basketballVertices) / 3); // Assuming the number of vertices for the basketball can be evenly divided by 3 to form triangles
    glBindVertexArray(0);

    // Render pen
    glBindVertexArray(penVAO);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(penVertices) / 3); // Assuming the number of vertices for the pen can be evenly divided by 3 to form triangles
    glBindVertexArray(0);

    // Render jar of water
    glBindVertexArray(jarVAO);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(jarVertices) / 3); // Assuming the number of vertices for the jar of water can be evenly divided by 3 to form triangles
    glBindVertexArray(0);

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
  }
}

int main() {
  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    return -1;
  }

  // Create a windowed mode window and its
