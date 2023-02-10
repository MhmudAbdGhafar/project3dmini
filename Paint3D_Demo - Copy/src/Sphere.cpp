#include <MainWindow.h>

#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTransform.h>

vtkSmartPointer<vtkActor> sphere = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform> transformSphere = vtkSmartPointer<vtkTransform>::New();

void MainWindow::onDrawSphereClick() {
	// Create sphere
	vtkSmartPointer<vtkSphereSource> sphereSource =
		vtkSmartPointer<vtkSphereSource>::New();
	sphereSource->SetRadius(5);
	sphereSource->SetThetaResolution(50);
	sphereSource->SetPhiResolution(50);
	sphereSource->Update();

	// Create the actor where the sphere is rendered
	vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	sphereMapper->SetInputData(sphereSource->GetOutput());
	sphere->SetMapper(sphereMapper);

	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();
	property->SetColor(1.0, 1.0, 1.0); // white color
	sphere->SetProperty(property);

	// Add the sphere actor to the OpenGL
	mRenderer->AddViewProp(sphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRemoveSphereClick() {
	mRenderer->RemoveViewProp(sphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();

	//clean up sphere
	sphere = vtkSmartPointer<vtkActor>::New();
}

void MainWindow::onChangeSphereColorClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();
	
	// Change the color of the actor
	property->SetColor(1.0, 0.0, 0.0); // Red color
	
	double color[3] = { 0, 0, 0 };
	srand(time(NULL));
	color[0] = static_cast<double>(rand()) / RAND_MAX;
	color[1] = static_cast<double>(rand()) / RAND_MAX;
	color[2] = static_cast<double>(rand()) / RAND_MAX;
	property->SetColor(color);
	sphere->SetProperty(property);

	mRenderer->AddViewProp(sphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onChangeSphereOpacityClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();
	
	// Change the opacity of the actor
	property->SetOpacity(0.5); // Half transparent
	sphere->SetProperty(property);

	mRenderer->AddViewProp(sphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRotateSphereClick() {
	transformSphere->RotateZ(30);
	sphere->SetUserTransform(transformSphere);

	mRenderer->AddViewProp(sphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onFlipSphereClick() {
	transformSphere->Scale(-1, 1, 1);
	sphere->SetUserTransform(transformSphere);

	mRenderer->AddViewProp(sphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onTranslateSphereClick() {
	transformSphere->Translate(10, 20, 30);
	sphere->SetUserTransform(transformSphere);

	mRenderer->AddViewProp(sphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onScaleSphereClick() {
	transformSphere->Scale(10, 10, 1);
	sphere->SetUserTransform(transformSphere);

	mRenderer->AddViewProp(sphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}