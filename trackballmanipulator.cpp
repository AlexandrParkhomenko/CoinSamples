
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/manips/SoTrackballManip.h>

int main(int, char **argv){
	// Initialize Inventor. This returns a main window to use.
	// If unsuccessful, exit.
	static QWidget* myQtdow = SoQt::init("A red cone."); // pass the app name
	if (myQtdow == NULL) exit(1);
	// Make a scene containing a red cone
	SoSeparator *root = new SoSeparator;
	SoPerspectiveCamera *myCamera = new SoPerspectiveCamera;
	SoMaterial *myMaterial = new SoMaterial;


	root->ref();
	root->addChild(myCamera);
	root->addChild(new SoDirectionalLight);
	root->addChild(new SoTrackballManip);
	myMaterial->diffuseColor.setValue(1.0, 1.0, 0.0); // Red
	root->addChild(myMaterial);

	root->addChild(new SoCone);
	// Create a renderArea in which to see our scene graph.
	// The render area will appear within the main window.
	SoQtExaminerViewer *myRenderArea = new SoQtExaminerViewer(myQtdow);
	// Make myCamera see everything.
	myCamera->viewAll(root, myRenderArea->getViewportRegion());
	// Put our scene in myRenderArea, change the title
	myRenderArea->setSceneGraph(root);
	myRenderArea->setTitle("A red cone");
	myRenderArea->show();
	SoQt::show(myQtdow); // Display main window
	SoQt::mainLoop(); // Main Inventor event loop
	delete myRenderArea;
	root->unref();
	return 0;
}
