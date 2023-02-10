#include <MainWindow.h>

#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTransform.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkClipPolyData.h>
#include <vtkPlane.h>


vtkSmartPointer<vtkActor> cylinder = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform> transformCylinder = vtkSmartPointer<vtkTransform>::New();

void MainWindow::onDrawCylinderClick() {
	vtkSmartPointer<vtkCylinderSource> cylinderSource =
		vtkSmartPointer<vtkCylinderSource>::New();
	cylinderSource->SetHeight(10.0);
	cylinderSource->SetRadius(5.0);
	cylinderSource->SetResolution(50);
	cylinderSource->Update();

	vtkSmartPointer<vtkPolyDataMapper> cylinderMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	cylinderMapper->SetInputData(cylinderSource->GetOutput());


	cylinder->SetMapper(cylinderMapper);

	mRenderer->AddViewProp(cylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();


}

void MainWindow::onRemoveCylinderClick() {
	// Add the pyramid actor to the renderer
	mRenderer->RemoveViewProp(cylinder);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();

	cylinder = vtkSmartPointer<vtkActor>::New();
}

void MainWindow::onChangeCylinderColorClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the color of the actor
	property->SetColor(1.0, 0.0, 0.0); // Red color

	double color[3] = { 0, 0, 0 };
	srand(time(NULL));
	color[0] = static_cast<double>(rand()) / RAND_MAX;
	color[1] = static_cast<double>(rand()) / RAND_MAX;
	color[2] = static_cast<double>(rand()) / RAND_MAX;
	property->SetColor(color);
	cylinder->SetProperty(property);

	mRenderer->AddViewProp(cylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onChangeCylinderOpacityClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the opacity of the actor
	property->SetOpacity(0.5); // Half transparent
	cylinder->SetProperty(property);

	mRenderer->AddViewProp(cylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRotateCylinderClick() {
	transformCylinder->RotateZ(30);
	cylinder->SetUserTransform(transformCylinder);

	mRenderer->AddViewProp(cylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onFlipCylinderClick() {
	transformCylinder->Scale(-1, 1, 1);
	cylinder->SetUserTransform(transformCylinder);

	mRenderer->AddViewProp(cylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onTranslateCylinderClick() {
	transformCylinder->Translate(10, 20, 30);
	cylinder->SetUserTransform(transformCylinder);

	mRenderer->AddViewProp(cylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onScaleCylinderClick() {
	transformCylinder->Scale(1, 10, 1);
	cylinder->SetUserTransform(transformCylinder);

	mRenderer->AddViewProp(cylinder);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}
