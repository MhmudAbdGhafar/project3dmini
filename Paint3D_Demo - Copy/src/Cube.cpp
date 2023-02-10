#include <MainWindow.h>

#include <vtkCubeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTransform.h>
#include <vtkDataSetSurfaceFilter.h>

vtkSmartPointer<vtkActor> cube = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform> transformCube = vtkSmartPointer<vtkTransform>::New();
void MainWindow::onDrawCubeClick() {

	vtkSmartPointer<vtkCubeSource> cubeSource =
		vtkSmartPointer<vtkCubeSource>::New();
	cubeSource->SetBounds(-5, 5, -5, 5, -5, 5);
	cubeSource->Update();

	vtkSmartPointer<vtkPolyDataMapper> cubeMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	cubeMapper->SetInputData(cubeSource->GetOutput());

	cube->SetMapper(cubeMapper);

	mRenderer->AddViewProp(cube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRemoveCubeClick() {
	mRenderer->RemoveViewProp(cube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();

	cube = vtkSmartPointer<vtkActor>::New();
}

void MainWindow::onChangeCubeColorClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the color of the actor
	property->SetColor(1.0, 0.0, 0.0); // Red color

	double color[3] = { 0, 0, 0 };
	srand(time(NULL));
	color[0] = static_cast<double>(rand()) / RAND_MAX;
	color[1] = static_cast<double>(rand()) / RAND_MAX;
	color[2] = static_cast<double>(rand()) / RAND_MAX;
	property->SetColor(color);
	cube->SetProperty(property);

	mRenderer->AddViewProp(cube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onChangeCubeOpacityClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the opacity of the actor
	property->SetOpacity(0.5); // Half transparent
	cube->SetProperty(property);

	mRenderer->AddViewProp(cube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRotateCubeClick() {
	transformCube->RotateZ(30);
	cube->SetUserTransform(transformCube);

	mRenderer->AddViewProp(cube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onFlipCubeClick() {
	transformCube->Scale(-1, 1, 1);
	cube->SetUserTransform(transformCube);

	mRenderer->AddViewProp(cube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onTranslateCubeClick() {
	transformCube->Translate(1.0, 2.0, 3.0);
	cube->SetUserTransform(transformCube);

	mRenderer->AddViewProp(cube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onScaleCubeClick() {
	transformCube->Scale(1, 10, 1);
	cube->SetUserTransform(transformCube);

	mRenderer->AddViewProp(cube);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}
