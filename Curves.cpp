
#include<Inventor/nodes/SoCoordinate3.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoSeparator.h>
#include<fstream>
#include<string>
#include<iostream>
#include<Inventor/nodes/SoPointSet.h>
#include <Inventor/Qt/SoQt.h>
#include<Inventor/nodes/SoTransform.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoDrawStyle.h>
#include<Inventor/nodes/SoComplexity.h>
#include<Inventor/nodes/SoNurbsCurve.h>
#include<Inventor/nodes/SoCylinder.h>
// The control points for this curve
float pts[7][3] = {
	{ 4.0, 6.0, 6.0 },
	{ 4.0, 1.0, 0.0 },
	{ 1.5, 5.0, 6.0 },
	{ 0.0, 2.0, 2.0 },
	{ 1.5, 5.0, 6.0 },
	{ 4.0, 1.0, 0.0 },
	{ 4.0, 6.0, 6.0 } };
// The knot vector
float knots[10] = { 1, 2, 3, 4, 5, 5, 6, 7, 8, 9 };
// Create the nodes needed for the BSpline curve.
SoSeparator *makeCurve(){
	SoSeparator *curveSep = new SoSeparator();
	curveSep->ref();
	// Set the draw style of the curve.
	SoDrawStyle *drawStyle = new SoDrawStyle;
	drawStyle->lineWidth = 4;
	curveSep->addChild(drawStyle);
	// Define the NURBS curve including the control points
	// and a complexity.
	SoComplexity *complexity = new SoComplexity;
	SoCoordinate3 *controlPts = new SoCoordinate3;
	SoNurbsCurve *curve = new SoNurbsCurve;
	complexity->value = 0.8;
	controlPts->point.setValues(0, 7, pts);
	curve->numControlPoints = 7;
	curve->knotVector.setValues(0, 10, knots);
	curveSep->addChild(complexity);
	curveSep->addChild(controlPts);
	curveSep->addChild(curve);
	curveSep->unrefNoDelete();
	return curveSep;
}

int main(int, char **argv){
	// Initialize Inventor. This returns a main window to use.
	// If unsuccessful, exit.
	static QWidget* myQtdow = SoQt::init("Points"); // pass the app name
	if (myQtdow == NULL) exit(1);
	SoSeparator *root = new SoSeparator;
	root->ref();
	root->addChild(makeCurve());
	SoQtExaminerViewer *myRenderArea = new SoQtExaminerViewer(myQtdow);
	myRenderArea->setBackgroundColor(SbColor(1, 1, 1));
	myRenderArea->setSceneGraph(root);
	myRenderArea->setTitle("Points");
	myRenderArea->show();
	SoQt::show(myQtdow); // Display main window
	SoQt::mainLoop(); // Main Inventor event loop
	delete myRenderArea;
	root->unref();
	return 0;
}
