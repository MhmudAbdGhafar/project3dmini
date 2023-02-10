#include <MainWindow.h>

#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTransform.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkClipPolyData.h>
#include <vtkPlane.h>


vtkSmartPointer<vtkActor> hemisphere = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform> transformHemisphere = vtkSmartPointer<vtkTransform>::New();
void MainWindow::onDrawHemiSphereClick() {
	vtkSmartPointer<vtkSphereSource> sphereSource =
		vtkSmartPointer<vtkSphereSource>::New();
	sphereSource->SetRadius(5);
	sphereSource->SetThetaResolution(50);
	sphereSource->SetPhiResolution(50);
	sphereSource->Update();

	vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	sphereMapper->SetInputData(sphereSource->GetOutput());

	vtkSmartPointer<vtkActor> sphereActor =
		vtkSmartPointer<vtkActor>::New();
	sphereActor->SetMapper(sphereMapper);

	// Cut the sphere to form a hemisphere
	vtkSmartPointer<vtkPlane> plane = vtkSmartPointer<vtkPlane>::New();
	plane->SetNormal(0, 1, 0);

	vtkSmartPointer<vtkClipPolyData> clipper =
		vtkSmartPointer<vtkClipPolyData>::New();
	clipper->SetInputData(sphereSource->GetOutput());
	clipper->SetClipFunction(plane);
	clipper->Update();

	vtkSmartPointer<vtkPolyDataMapper> hemisphereMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	hemisphereMapper->SetInputData(clipper->GetOutput());

	//vtkSmartPointer<vtkActor> hemisphereActor = vtkSmartPointer<vtkActor>::New();
	hemisphere->SetMapper(hemisphereMapper);

	// Add the hemisphere actor to the renderer
	mRenderer->AddActor(hemisphere);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();

}

void MainWindow::onRemoveHemiSphereClick() {
	mRenderer->RemoveViewProp(hemisphere);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();

	hemisphere = vtkSmartPointer<vtkActor>::New();
}

void MainWindow::onChangeHemisphereColorClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the color of the actor
	property->SetColor(1.0, 0.0, 0.0); // Red color

	double color[3] = { 0, 0, 0 };
	srand(time(NULL));
	color[0] = static_cast<double>(rand()) / RAND_MAX;
	color[1] = static_cast<double>(rand()) / RAND_MAX;
	color[2] = static_cast<double>(rand()) / RAND_MAX;
	property->SetColor(color);
	hemisphere->SetProperty(property);

	mRenderer->AddViewProp(hemisphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onChangeHemisphereOpacityClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the opacity of the actor
	property->SetOpacity(0.5); // Half transparent
	hemisphere->SetProperty(property);

	mRenderer->AddViewProp(hemisphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRotateHemisphereClick() {
	transformHemisphere->RotateZ(30);
	hemisphere->SetUserTransform(transformHemisphere);

	mRenderer->AddViewProp(hemisphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onFlipHemisphereClick() {
	transformHemisphere->Scale(-1, 1, 1);
	hemisphere->SetUserTransform(transformHemisphere);

	mRenderer->AddViewProp(hemisphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onTranslateHemisphereClick() {
	transformHemisphere->Translate(10, 20, 30);
	hemisphere->SetUserTransform(transformHemisphere);

	mRenderer->AddViewProp(hemisphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onScaleHemisphereClick() {
	transformHemisphere->Scale(1, 10, 1);
	hemisphere->SetUserTransform(transformHemisphere);

	mRenderer->AddViewProp(hemisphere);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}