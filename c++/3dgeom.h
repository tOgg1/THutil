#include <GL\glew.h>
#include <glm\glm.hpp>
#include <vector>

void createNonIndexedCube(GLfloat*, int sizex, int sizey, int sizez);
void addTriangleToVector(std::vector<glm::vec3>* vec, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);