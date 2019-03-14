
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>

int main(int, char **argv){
	// Initialize Inventor. This returns a main window to use.
	// If unsuccessful, exit.
	static QWidget* myQtdow = SoQt::init("A red cone."); // pass the app name
	if (myQtdow == NULL) exit(1);
	// Make a scene containing a red cone
	SoSeparator *root = new SoSeparator;
	root->ref();
	SoMaterial *myMaterial = new SoMaterial;
	myMaterial->diffuseColor.setValue(1.0, 0.0, 0.0);
	root->addChild(myMaterial);
	root->addChild(new SoCone);
	// Set up viewer:
	SoQtExaminerViewer *myViewer =new SoQtExaminerViewer(myQtdow);
	myViewer->setSceneGraph(root);
	myViewer->setTitle("Examiner Viewer");
	myViewer->show(); 
	
	SoQt::show(myQtdow); // Display main window
	SoQt::mainLoop(); // Main Inventor event loop
	
	root->unref();
	return 0;
}
