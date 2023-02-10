#include <MainWindow.h>

#include <vtkTubeFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTransform.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkLineSource.h>

vtkSmartPointer<vtkActor> tube = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform> transformTube = vtkSmartPointer<vtkTransform>::New();
void MainWindow::onDrawTubeClick() {
	vtkSmartPointer<vtkTubeFilter> tubeFilter =
		vtkSmartPointer<vtkTubeFilter>::New();

	vtkSmartPointer<vtkLineSource> lineSource =
		vtkSmartPointer<vtkLineSource>::New();
	lineSource->SetPoint1(0, 0, 0);
	lineSource->SetPoint2(1, 1, 1);
	lineSource->Update();

	tubeFilter->SetInputData(lineSource->GetOutput());
	tubeFilter->SetRadius(0.5);
	tubeFilter->SetNumberOfSides(50);
	tubeFilter->Update();

	vtkSmartPointer<vtkPolyDataMapper> tubeMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	tubeMapper->SetInputData(tubeFilter->GetOutput());


	tube->SetMapper(tubeMapper);

	mRenderer->AddViewProp(tube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();

}

void MainWindow::onRemoveTubeClick() {
	// Add the pyramid actor to the renderer
	mRenderer->RemoveViewProp(tube);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();

	tube = vtkSmartPointer<vtkActor>::New();
}

void MainWindow::onChangeTubeColorClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the color of the actor
	property->SetColor(1.0, 0.0, 0.0); // Red color

	double color[3] = { 0, 0, 0 };
	srand(time(NULL));
	color[0] = static_cast<double>(rand()) / RAND_MAX;
	color[1] = static_cast<double>(rand()) / RAND_MAX;
	color[2] = static_cast<double>(rand()) / RAND_MAX;
	property->SetColor(color);
	tube->SetProperty(property);

	mRenderer->AddViewProp(tube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onChangeTubeOpacityClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the opacity of the actor
	property->SetOpacity(0.5); // Half transparent
	tube->SetProperty(property);

	mRenderer->AddViewProp(tube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRotateTubeClick() {
	transformTube->RotateZ(30);
	tube->SetUserTransform(transformTube);

	mRenderer->AddViewProp(tube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onFlipTubeClick() {
	transformTube->Scale(-1, 1, 1);
	tube->SetUserTransform(transformTube);

	mRenderer->AddViewProp(tube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onTranslateTubeClick() {
	transformTube->Translate(1.0, 2.0, 3.0);
	tube->SetUserTransform(transformTube);

	mRenderer->AddViewProp(tube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onScaleTubeClick() {
	transformTube->Scale(1, 10, 1);
	tube->SetUserTransform(transformTube);

	mRenderer->AddViewProp(tube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}