/*
 * gMesh.h
 *
 *  Created on: May 7, 2020
 *      Author: noyan
 */

#ifndef ENGINE_GRAPHICS_GMESH_H_
#define ENGINE_GRAPHICS_GMESH_H_
/*
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
*/
#include <vector>

#include "gNode.h"
#include "gTexture.h"
#include "gMaterial.h"
#include "gVbo.h"
#include "gBoundingBox.h"

class gMesh : public gNode {
public:
	static const int DRAWMODE_POINTS = 0, DRAWMODE_LINES = 1, DRAWMODE_LINELOOP = 2, DRAWMODE_LINESTRIP = 3,
	DRAWMODE_TRIANGLES = 4, DRAWMODE_TRIANGLESTRIP = 5, DRAWMODE_TRIANGLEFAN = 6,
	DRAWMODE_QUADS = 7, DRAWMODE_QUADSTRIP = 8, DRAWMODE_POLYGON = 9;

	gMesh();
	gMesh(std::vector<gVertex> vertices, std::vector<unsigned int> indices, std::vector<gTexture> textures);
	virtual ~gMesh();

	void setVertices(std::vector<gVertex> vertices, std::vector<unsigned int> indices = std::vector<unsigned int>());
	void setTextures(std::vector<gTexture>& textures);
	void setTexture(gTexture* texture);
	void addTexture(gTexture tex);
	const gTexture& getTexture(int textureNo) const;

	const std::vector<gVertex>& getVertices() const;
	const std::vector<unsigned int>& getIndices() const;
	int getVerticesNum() const;
	int getIndicesNum() const;
	gBoundingBox getBoundingBox();
	const gVbo& getVbo() const;
	void clear();

	void setName(std::string name);
	const std::string& getName() const;

	void setDrawMode(int drawMode);
	int getDrawMode() const;

	void setMaterial(gMaterial* material);
	gMaterial& getMaterial();

	void draw();

    const gBoundingBox& getInitialBoundingBox() const;
    bool intersectsTriangles(gRay* ray);
    float distanceTriangles(gRay* ray);

protected:
    void drawStart();
    void drawVbo();
    void drawEnd();
	gVbo vbo;
	std::vector<gVertex> vertices;
    bool isprojection2d;

private:
    std::string name;
	std::vector<unsigned int> indices;
	std::vector<gTexture> textures;
	int drawmode;
    gMaterial material;
    int sli;
    unsigned int ti;

    unsigned int diffuseNr, specularNr, normalNr, heightNr;
    std::string texnumber;
    int textype;

    gLight* scenelight;
    gShader* colorshader;
    gShader* textureshader;
    gShader *pbrshader;

    float bbminx, bbminy, bbminz, bbmaxx, bbmaxy, bbmaxz;
    glm::vec3 bbvpos;
    int bbi;

    gBoundingBox initialboundingbox;
};

#endif /* ENGINE_GRAPHICS_GMESH_H_ */
