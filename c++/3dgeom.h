#include <GL\glew.h>
#include <glm\glm.hpp>
#include <vector>

#ifndef CUBE_NOINDEX_SIZE
#define CUBE_NOINDEX_SIZE 108
#endif

#ifndef CUBE_NOINDEX_COLOR_SIZE
#define CUBE_NOINDEX_COLOR_SIZE 144
#endif


void createNonIndexedCube(GLfloat*, GLfloat* normalArray, float sizex, float sizey, float sizez, bool createNormalVectors);
void createFaceColorsForNonIndexedCube(GLfloat* array, glm::vec4 colorFront, glm::vec4 colorBack,	glm::vec4 colorRight, glm::vec4 colorLeft, glm::vec4 colorTop, glm::vec4 colorBottom);
void createIndexedCube(GLfloat* vertexArray, GLfloat* normalArray, GLint* indexArray, float sizex, float sizey, float sizez, bool createNormalVectors);
void createColorsForIndexedCube(GLfloat* colorArray, GLint &indexArray,	glm::vec4 colorFront, glm::vec4 colorBack, glm::vec4 colorRight, glm::vec4 colorLeft, glm::vec4 colorTop, glm::vec4 colorBottom);

//Helper methods
void addVec3TripletToVector(std::vector<glm::vec3>* vec, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);
void addVec4TripletToVector(std::vector<glm::vec4>* vec, glm::vec4 p1, glm::vec4 p2, glm::vec4 p3);