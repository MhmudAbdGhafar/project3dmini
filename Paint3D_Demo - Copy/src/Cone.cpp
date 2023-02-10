#include <MainWindow.h>

#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTransform.h>
#include <vtkDataSetSurfaceFilter.h>

vtkSmartPointer<vtkActor> cone = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform> transformCone = vtkSmartPointer<vtkTransform>::New();
void MainWindow::onDrawConeClick() {
	vtkSmartPointer<vtkConeSource> coneSource =
		vtkSmartPointer<vtkConeSource>::New();
	coneSource->SetHeight(5);
	coneSource->SetRadius(3);
	coneSource->SetResolution(50);
	coneSource->Update();

	vtkSmartPointer<vtkPolyDataMapper> coneMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	coneMapper->SetInputData(coneSource->GetOutput());

	//vtkSmartPointer<vtkActor> coneActor = vtkSmartPointer<vtkActor>::New();
	cone->SetMapper(coneMapper);

	// Add the cone actor to the renderer
	mRenderer->AddActor(cone);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();
}

void MainWindow::onRemoveConeClick() {
	mRenderer->RemoveViewProp(cone);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();

	cone = vtkSmartPointer<vtkActor>::New();
}

void MainWindow::onChangeConeColorClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the color of the actor
	property->SetColor(1.0, 0.0, 0.0); // Red color

	double color[3] = { 0, 0, 0 };
	srand(time(NULL));
	color[0] = static_cast<double>(rand()) / RAND_MAX;
	color[1] = static_cast<double>(rand()) / RAND_MAX;
	color[2] = static_cast<double>(rand()) / RAND_MAX;
	property->SetColor(color);
	cone->SetProperty(property);

	mRenderer->AddViewProp(cone);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onChangeConeOpacityClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the opacity of the actor
	property->SetOpacity(0.5); // Half transparent
	cone->SetProperty(property);

	mRenderer->AddViewProp(cone);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRotateConeClick() {
	transformCone->RotateZ(30);
	cone->SetUserTransform(transformCone);

	mRenderer->AddViewProp(cone);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onFlipConeClick() {
	transformCone->Scale(-1, 1, 1);
	cone->SetUserTransform(transformCone);

	mRenderer->AddViewProp(cone);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onTranslateConeClick() {
	transformCone->Translate(10, 20, 30);
	cone->SetUserTransform(transformCone);

	mRenderer->AddViewProp(cone);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onScaleConeClick() {
	transformCone->Scale(10, 10, 10);
	cone->SetUserTransform(transformCone);

	mRenderer->AddViewProp(cone);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}