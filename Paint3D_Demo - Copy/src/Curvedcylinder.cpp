#include <MainWindow.h>

#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTransform.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkClipPolyData.h>
#include <vtkPlane.h>
#include <vtkParametricSpline.h>
#include <vtkParametricFunctionSource.h>
#include <vtkTubeFilter.h>

vtkSmartPointer<vtkActor> curvedCylinder = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform> transformCurvedcylinder = vtkSmartPointer<vtkTransform>::New();

void MainWindow::onDrawCurvedCylinderClick() {
	vtkSmartPointer<vtkParametricSpline> spline =
		vtkSmartPointer<vtkParametricSpline>::New();

	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();
	points->InsertNextPoint(1.0, 0.0, 0.0);
	points->InsertNextPoint(0.0, 1.0, 0.0);
	points->InsertNextPoint(-1.0, -1.0, 0.0);
	spline->SetPoints(points);

	vtkSmartPointer<vtkParametricFunctionSource> functionSource =
		vtkSmartPointer<vtkParametricFunctionSource>::New();
	functionSource->SetParametricFunction(spline);
	functionSource->Update();

	vtkSmartPointer<vtkTubeFilter> tubeFilter =
		vtkSmartPointer<vtkTubeFilter>::New();
	tubeFilter->SetInputData(functionSource->GetOutput());
	tubeFilter->SetRadius(0.5);
	tubeFilter->SetNumberOfSides(50);
	tubeFilter->Update();

	vtkSmartPointer<vtkPolyDataMapper> curvedCylinderMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	curvedCylinderMapper->SetInputData(tubeFilter->GetOutput());

	//vtkSmartPointer<vtkActor> curvedCylinderActor = vtkSmartPointer<vtkActor>::New();
	curvedCylinder->SetMapper(curvedCylinderMapper);

	mRenderer->AddViewProp(curvedCylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();

}

void MainWindow::onRemoveCurvedCylinderClick() {
	// Add the pyramid actor to the renderer
	mRenderer->RemoveViewProp(curvedCylinder);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();

	curvedCylinder = vtkSmartPointer<vtkActor>::New();
}

void MainWindow::onChangeCurvedcylinderColorClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the color of the actor
	property->SetColor(1.0, 0.0, 0.0); // Red color

	double color[3] = { 0, 0, 0 };
	srand(time(NULL));
	color[0] = static_cast<double>(rand()) / RAND_MAX;
	color[1] = static_cast<double>(rand()) / RAND_MAX;
	color[2] = static_cast<double>(rand()) / RAND_MAX;
	property->SetColor(color);
	curvedCylinder->SetProperty(property);

	mRenderer->AddViewProp(curvedCylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onChangeCurvedcylinderOpacityClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the opacity of the actor
	property->SetOpacity(0.5); // Half transparent
	curvedCylinder->SetProperty(property);

	mRenderer->AddViewProp(curvedCylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRotateCurvedcylinderClick() {
	transformCurvedcylinder->RotateZ(30);
	curvedCylinder->SetUserTransform(transformCurvedcylinder);

	mRenderer->AddViewProp(curvedCylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onFlipCurvedcylinderClick() {
	transformCurvedcylinder->Scale(-1, 1, 1);
	curvedCylinder->SetUserTransform(transformCurvedcylinder);

	mRenderer->AddViewProp(curvedCylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onTranslateCurvedcylinderClick() {
	transformCurvedcylinder->Translate(10, 20, 30);
	curvedCylinder->SetUserTransform(transformCurvedcylinder);

	mRenderer->AddViewProp(curvedCylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onScaleCurvedcylinderClick() {
	transformCurvedcylinder->Scale(1, 10, 1);
	curvedCylinder->SetUserTransform(transformCurvedcylinder);

	mRenderer->AddViewProp(curvedCylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}