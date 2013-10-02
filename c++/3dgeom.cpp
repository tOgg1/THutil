#include "3dgeom.h"
#include <glm\glm.hpp>
#include <vector>




/*
Creates a non indexed cube, returning a cube with 36 points.
*/
void createNonIndexedCube(GLfloat* array, GLfloat* normalArray, float sizex, float sizey, float sizez, bool createNormalVectors)
{

	glm::vec3 p1, p2, p3, p4, p5, p6, p7, p8;

	p1 = glm::vec3(sizex, sizey, sizez);
	p2 = glm::vec3(-sizex, sizey, sizez);
	p3 = glm::vec3(sizex, -sizey, sizez);
	p4 = glm::vec3(-sizex, -sizey, sizez);
	p5 = glm::vec3(sizex, sizey, -sizez);
	p6 = glm::vec3(-sizex, sizey, -sizez);
	p7 = glm::vec3(sizex, -sizey, -sizez);
	p8 = glm::vec3(-sizex, -sizey, -sizez);

	std::vector<glm::vec3> data;
	
	// Allocate 36 places
	data.reserve(36);

	//Front face
	addVec3TripletToVector(&data, p2, p4, p1);
	addVec3TripletToVector(&data, p4, p3, p1);

	//Back face
	addVec3TripletToVector(&data, p5, p7, p6);
	addVec3TripletToVector(&data, p7, p8, p6);

	//Right face
	addVec3TripletToVector(&data, p1, p3, p5);
	addVec3TripletToVector(&data, p3, p7, p5);

	//Left face
	addVec3TripletToVector(&data, p6, p8, p2);
	addVec3TripletToVector(&data, p8, p4, p2);

	//Top face
	addVec3TripletToVector(&data, p6, p2, p5);
	addVec3TripletToVector(&data, p2, p1, p5);

	//Bottom face
	addVec3TripletToVector(&data, p3, p4, p7);
	addVec3TripletToVector(&data, p4, p8, p7);

	memcpy(array, (GLfloat*)&data[0], sizeof(data[0])*data.size());

	if(createNormalVectors)
	{
		glm::vec3 n1, n2, n3, n4, n5, n6;
		n1 = glm::vec3( 1,  0,  0);
		n2 = glm::vec3( 0,  1,  0);
		n3 = glm::vec3( 0,  0,  1);
		n4 = glm::vec3(-1,  0,  0);
		n5 = glm::vec3( 0, -1,  0);
		n6 = glm::vec3( 0,  0, -1);

		std::vector<glm::vec3> normalData;
		data.reserve(36);

		//Front face
		addVec3TripletToVector(&normalData, n3, n3, n3);
		addVec3TripletToVector(&normalData, n3, n3, n3);

		//Back face
		addVec3TripletToVector(&normalData, n6, n6, n6);
		addVec3TripletToVector(&normalData, n6, n6, n6);
	
		//Right face
		addVec3TripletToVector(&normalData, n1, n1, n1);
		addVec3TripletToVector(&normalData, n1, n1, n1);

		//Left face
		addVec3TripletToVector(&normalData, n4, n4, n4);
		addVec3TripletToVector(&normalData, n4, n4, n4);
	
		//Top face
		addVec3TripletToVector(&normalData, n2, n2, n2);
		addVec3TripletToVector(&normalData, n2, n2, n2);
		
		//Bottom face
		addVec3TripletToVector(&normalData, n5, n5, n5);
		addVec3TripletToVector(&normalData, n5, n5, n5);

		memcpy(normalArray, (GLfloat*)&data[0], sizeof(normalData[0])*normalData.size());
	}
}

/*
Generate colors for all faces of cube
*/
void createFaceColorsForNonIndexedCube(	
	GLfloat* array,
	glm::vec4 colorFront,
	glm::vec4 colorBack,
	glm::vec4 colorRight,
	glm::vec4 colorLeft,
	glm::vec4 colorTop,
	glm::vec4 colorBottom
)
{
	std::vector<glm::vec4> data;
	data.reserve(36);

	addVec4TripletToVector(&data, colorFront, colorFront, colorFront);
	addVec4TripletToVector(&data, colorFront, colorFront, colorFront);

	addVec4TripletToVector(&data, colorBack, colorBack, colorBack);
	addVec4TripletToVector(&data, colorBack, colorBack, colorBack);

	addVec4TripletToVector(&data, colorRight, colorRight, colorRight);
	addVec4TripletToVector(&data, colorRight, colorRight, colorRight);

	addVec4TripletToVector(&data, colorLeft, colorLeft, colorLeft);
	addVec4TripletToVector(&data, colorLeft, colorLeft, colorLeft);

	addVec4TripletToVector(&data, colorTop, colorTop, colorTop);
	addVec4TripletToVector(&data, colorTop, colorTop, colorTop);

	addVec4TripletToVector(&data, colorBottom, colorBottom, colorBottom);
	addVec4TripletToVector(&data, colorBottom, colorBottom, colorBottom);

	memcpy(array, (GLfloat*)&data[0], sizeof(data[0])*data.size());
}

void createIndexedCube(GLfloat* vertexArray, GLfloat* normalArray, GLint* indexArray, float sizex, float sizey, float sizez, bool createNormalVectors)
{


}

void createColorsForIndexedCube
	(
	GLfloat* colorArray,
	glm::vec4 colorFront,
	glm::vec4 colorBack,
	glm::vec4 colorRight,
	glm::vec4 colorLeft,
	glm::vec4 colorTop,
	glm::vec4 colorBottom
)
{

}


/*
Helper method for adding three points to a std::vector
*/
void addVec3TripletToVector(std::vector<glm::vec3>* vec, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3)
{
	vec->push_back(p1);
	vec->push_back(p2);
	vec->push_back(p3);
}

void addVec4TripletToVector(std::vector<glm::vec4>* vec, glm::vec4 p1, glm::vec4 p2, glm::vec4 p3)
{
	vec->push_back(p1);
	vec->push_back(p2);
	vec->push_back(p3);
}