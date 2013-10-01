#include "3dgeom.h"
#include <glm\glm.hpp>
#include <vector>

/*
Creates a non indexed cube, returning a cube with 36 points.
*/
GLfloat* createNonIndexedCube(GLfloat* destinationArray, int sizex, int sizey, int sizez)
{
	// Locally this shouldnt impose any problems
	using namespace glm;
	vec3 p1, p2, p3, p4, p5, p6, p7, p8;

	p1 = vec3(sizex, sizey, sizez);
	p2 = vec3(-sizex, sizey, sizez);
	p3 = vec3(sizex, -sizey, sizez);
	p4 = vec3(-sizex, -sizey, sizez);
	p5 = vec3(sizex, sizey, -sizez);
	p6 = vec3(-sizex, sizey, -sizez);
	p7 = vec3(sizex, -sizey, -sizez);
	p8 = vec3(-sizex, -sizey, -sizez);

	std::vector<vec3> data;

	// Allocate 36 places
	data.reserve(36);

	//Front face
	addTriangleToVector(&data, p2, p4, p1);
	addTriangleToVector(&data, p4, p3, p1);

	//Back face
	addTriangleToVector(&data, p5, p7, p6);
	addTriangleToVector(&data, p7, p8, p6);

	//Right face
	addTriangleToVector(&data, p1, p3, p5);
	addTriangleToVector(&data, p3, p7, p5);

	//Left face
	addTriangleToVector(&data, p6, p8, p2);
	addTriangleToVector(&data, p8, p4, p2);

	//Top face
	addTriangleToVector(&data, p6, p2, p5);
	addTriangleToVector(&data, p2, p1, p5);

	//Bottom face
	addTriangleToVector(&data, p3, p7, p4);
	addTriangleToVector(&data, p7, p8, p4);

	// Somewhat unsafe? perhaps typecast glm::vector?
	return (GLfloat*)&data;
}


/*
Helper method for adding three points to a std::vector
*/
void addTriangleToVector(std::vector<glm::vec3>* vec, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3)
{
	vec->push_back(p1);
	vec->push_back(p2);
	vec->push_back(p1);
}