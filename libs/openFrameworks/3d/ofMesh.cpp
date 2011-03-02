#include "ofMesh.h"
#include "ofGraphics.h"

//--------------------------------------------------------------
ofMesh::ofMesh(){
	mode = OF_TRIANGLES_MODE;
	bVertsChanged = true;
	bColorsChanged = true;
	bNormalsChanged = true;
	bTexCoordsChanged = true;
	bIndicesChanged = true;
}

//--------------------------------------------------------------
ofMesh::ofMesh(ofPrimitiveMode mode, const vector<ofVec3f>& verts){
	setMode(mode);
	addVertices(verts);
}

//--------------------------------------------------------------
ofMesh::~ofMesh(){
}

//--------------------------------------------------------------
void ofMesh::clear(){
	bVertsChanged = true;
	bColorsChanged = true;
	bNormalsChanged = true;
	bTexCoordsChanged = true;
	bIndicesChanged = true;
	
	vertices.clear();
	colors.clear();
	normals.clear();
	texCoords.clear();
	indices.clear();
}

//--------------------------------------------------------------
bool ofMesh::haveVertsChanged(){
	if(bVertsChanged){
		bVertsChanged = false;
		return true;
	}else{
		return false;
	}
}

//--------------------------------------------------------------
bool ofMesh::haveColorsChanged(){
	if(bColorsChanged){
		bColorsChanged = false;
		return true;
	}else{
		return false;
	}
}

//--------------------------------------------------------------
bool ofMesh::haveNormalsChanged(){
	if(bNormalsChanged){
		bNormalsChanged = false;
		return true;
	}else{
		return false;
	}
}

//--------------------------------------------------------------
bool ofMesh::haveTexCoordsChanged(){
	if(bTexCoordsChanged){
		bTexCoordsChanged = false;
		return true;
	}else{
		return false;
	}
}

//--------------------------------------------------------------
bool ofMesh::haveIndicesChanged(){
	if(bIndicesChanged){
		bIndicesChanged = false;
		return true;
	}else{
		return false;
	}
}

//ADDERS

//--------------------------------------------------------------
void ofMesh::addVertex(const ofVec3f& v){
	vertices.push_back(v);
	bVertsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addVertices(const vector<ofVec3f>& verts){
	vertices.insert(vertices.end(),verts.begin(),verts.end());
	bVertsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addVertices(const ofVec3f* verts, int amt){
	for (int i = 0; i < amt;i++){
		addVertex(verts[i]);
	}
	bVertsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addColor(const ofColor& c){
	colors.push_back(c);
	bColorsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addColors(const vector<ofColor>& cols){
	colors.insert(colors.end(),cols.begin(),cols.end());
	bColorsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addColors(const ofColor* cols, int amt){
	for (int i = 0; i < amt;i++){
		addColor(cols[i]);
	}
	bColorsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addNormal(const ofVec3f& n){
	normals.push_back(n);
	bNormalsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addNormals(const vector<ofVec3f>& norms){
	normals.insert(normals.end(),norms.begin(),norms.end());
	bNormalsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addNormals(const ofVec3f* norms, int amt){
	for (int i = 0; i < amt;i++){
		addNormal(norms[i]);
	}
	bNormalsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addTexCoord(const ofVec2f& t){
	//TODO: figure out if we add to all other arrays to match
	texCoords.push_back(t);
	bTexCoordsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addTexCoords(const vector<ofVec2f>& tCoords){
	texCoords.insert(texCoords.end(),tCoords.begin(),tCoords.end());
	bTexCoordsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addTexCoords(const ofVec2f* tCoords, int amt){
	for (int i = 0; i < amt;i++){
		addTexCoord(tCoords[i]);
	}
	bTexCoordsChanged = true;
}

//--------------------------------------------------------------
ofIndexType ofMesh::getIndex(int i){
	return indices[i];
}

//--------------------------------------------------------------
void ofMesh::addIndex(ofIndexType i){
	indices.push_back(i);
	bIndicesChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addIndices(const vector<ofIndexType>& inds){
	indices.insert(indices.end(),inds.begin(),inds.end());
	bIndicesChanged = true;
}

//--------------------------------------------------------------
void ofMesh::addIndices(const ofIndexType* inds, int amt){
	for (int i = 0; i < amt;i++){
		addIndex(inds[i]);
	}
	bIndicesChanged = true;
}

//GETTERS
//--------------------------------------------------------------
ofPrimitiveMode ofMesh::getMode() const{
	return mode;
}

//--------------------------------------------------------------
ofVec3f ofMesh::getVertex(int i){
	return vertices[i];
}

//--------------------------------------------------------------
ofVec3f ofMesh::getNormal(int i){
	return normals[i];
}

//--------------------------------------------------------------
ofColor ofMesh::getColor(int i){
	return colors[i];
}

//--------------------------------------------------------------
ofVec2f ofMesh::getTexCoord(int i){
	return texCoords[i];
}

//--------------------------------------------------------------
int ofMesh::getNumVertices() const{
	return (int)vertices.size();
}

//--------------------------------------------------------------
int ofMesh::getNumColors() const{
	return (int)colors.size();
}

//--------------------------------------------------------------
int ofMesh::getNumNormals() const{
	return (int)normals.size();
}

//--------------------------------------------------------------
int ofMesh::getNumTexCoords() const{
	return (int)texCoords.size();
}

//--------------------------------------------------------------
int ofMesh::getNumIndices() const{
	return (int)indices.size();
}

/*
//--------------------------------------------------------------
int ofPrimitive::getNumIndicesSolid(){
	return indicesSolid.size();
}

//--------------------------------------------------------------
int ofPrimitive::getNumIndicesWire(){
	return indicesWire.size();
}
 */

//--------------------------------------------------------------
ofVec3f* ofMesh::getVerticesPointer(){
	return &vertices[0];
}

//--------------------------------------------------------------
ofColor* ofMesh::getColorsPointer(){
	return &colors[0];
}

//--------------------------------------------------------------
ofVec3f* ofMesh::getNormalsPointer(){
	return &normals[0];
}

//--------------------------------------------------------------
ofVec2f* ofMesh::getTexCoordsPointer(){
	return &texCoords[0];
}

//--------------------------------------------------------------
ofIndexType* ofMesh::getIndexPointer(){
	return &indices[0];
}


//--------------------------------------------------------------
const float* ofMesh::getVerticesPointer() const{
	return &vertices[0].x;
}

//--------------------------------------------------------------
const float* ofMesh::getColorsPointer() const{
	return &colors[0].r;
}

//--------------------------------------------------------------
const float* ofMesh::getNormalsPointer() const{
	return &normals[0].x;
}

//--------------------------------------------------------------
const float* ofMesh::getTexCoordsPointer() const{
	return &texCoords[0].x;
}

//--------------------------------------------------------------
const ofIndexType * ofMesh::getIndexPointer() const{
	return &indices[0];
}

vector<ofVec3f> & ofMesh::getVertices(){
	return vertices;
}

/*
//--------------------------------------------------------------
GLuint* ofPrimitive::getSolidIndexPointer(){
	return &indicesSolid[0];
}

//--------------------------------------------------------------
GLuint* ofPrimitive::getWireIndexPointer(){
	return &indicesWire[0];
}
 */

/*
//--------------------------------------------------------------
vector<int>& ofPrimitive::getFace(int faceNum){
	switch(mode){
		//GL_QUADS
		indices[faceNum*4+0];
		indices[faceNum*4+1];
		indices[faceNum*4+2];
		indices[faceNum*4+3];

		//GL_TRIANGLES
		indices[faceNum*3+0];
		indices[faceNum*3+1];
		indices[faceNum*3+2];

		//GL_TRIANGLE_FAN
		// 1 element per fan
		indices[0];
		indices[faceNum+1];
		indices[faceNum+2];

		//GL_TRIANGLE_STRIP
		// 1 element per strip
		indices[faceNum+0];
		indices[faceNum+1];
		indices[faceNum+2];
		default:break;
	}
}
 */

//SETTERS
//--------------------------------------------------------------
void ofMesh::setMode(ofPrimitiveMode m){
	bIndicesChanged = true;
	mode = m;
}

//--------------------------------------------------------------
void ofMesh::setVertex(int index, const ofVec3f& v){
	vertices[index] = v;
	bVertsChanged = true;
	bIndicesChanged = true;
}

//--------------------------------------------------------------
void ofMesh::setNormal(int index, const ofVec3f& n){
	normals[index] = n;
	bNormalsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::setColor(int index, const ofColor& c){
	colors[index] = c;
	bColorsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::setTexCoord(int index, const ofVec2f& t){
	texCoords[index] = t;
	bTexCoordsChanged = true;
}

//--------------------------------------------------------------
void ofMesh::setIndex(int i, ofIndexType  val){
	indices[i] = val;
	bIndicesChanged = true;
}

//--------------------------------------------------------------
void ofMesh::setName(string name_){
	name = name_;
}

//--------------------------------------------------------------
void ofMesh::setupIndicesAuto(){
	bIndicesChanged = true;
	indices.clear();
	for(int i = 0; i < (int)vertices.size();i++){
		indices.push_back((ofIndexType)i);
	}
}

//--------------------------------------------------------------
void ofMesh::drawVertices(){
	draw(OF_MESH_POINTS);
}

//--------------------------------------------------------------
void ofMesh::drawWireframe(){
	draw(OF_MESH_WIREFRAME);
}

//--------------------------------------------------------------
void ofMesh::drawFaces(){
	draw(OF_MESH_FILL);
}

//--------------------------------------------------------------
void ofMesh::draw(ofPolyRenderMode renderType){
	ofGetDefaultRenderer()->draw(*this,renderType);
}
