
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCone.h>

int main(int, char ** argv){
	static QWidget* window = SoQt::init(argv[0]);
	if (window == NULL) exit(1);

	SoQtExaminerViewer * viewer = new SoQtExaminerViewer(window);	
	
	viewer->setDecoration(false);
	

	SoSeparator * root = new SoSeparator;
	SoCone * cone = new SoCone;

	root->ref();
	root->addChild(cone);

	viewer->setSceneGraph(root);
	viewer->show();

	SoQt::show(window);
	SoQt::mainLoop();
	delete viewer;
	root->unref();
	return 0;
}
