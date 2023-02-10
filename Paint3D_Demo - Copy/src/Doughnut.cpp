#include <MainWindow.h>

#include <vtkTubeFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTransform.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkRegularPolygonSource.h>


vtkSmartPointer<vtkActor> doughnut = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform> transformDoughnut = vtkSmartPointer<vtkTransform>::New();

void MainWindow::onDrawDoughnutClick() {
	vtkSmartPointer<vtkRegularPolygonSource> polygonSource =
		vtkSmartPointer<vtkRegularPolygonSource>::New();
	polygonSource->SetNumberOfSides(50);
	polygonSource->SetRadius(5.0);
	polygonSource->SetCenter(0.0, 0.0, 0.0);
	polygonSource->Update();

	vtkSmartPointer<vtkTubeFilter> tubeFilter =
		vtkSmartPointer<vtkTubeFilter>::New();
	tubeFilter->SetInputData(polygonSource->GetOutput());
	tubeFilter->SetRadius(2.5);
	tubeFilter->SetNumberOfSides(50);
	tubeFilter->Update();

	vtkSmartPointer<vtkPolyDataMapper> doughnutMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	doughnutMapper->SetInputData(tubeFilter->GetOutput());

	//vtkSmartPointer<vtkActor> doughnutActor = vtkSmartPointer<vtkActor>::New();
	doughnut->SetMapper(doughnutMapper);

	mRenderer->AddViewProp(doughnut);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRemoveDoughnutClick() {
	// Add the pyramid actor to the renderer
	mRenderer->RemoveViewProp(doughnut);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();

	doughnut = vtkSmartPointer<vtkActor>::New();
}

void MainWindow::onChangeDoughnutOpacityClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the opacity of the actor
	property->SetOpacity(0.5); // Half transparent
	doughnut->SetProperty(property);

	mRenderer->AddViewProp(doughnut);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onChangeDoughnutColorClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the color of the actor
	property->SetColor(1.0, 0.0, 0.0); // Red color

	double color[3] = { 0, 0, 0 };
	srand(time(NULL));
	color[0] = static_cast<double>(rand()) / RAND_MAX;
	color[1] = static_cast<double>(rand()) / RAND_MAX;
	color[2] = static_cast<double>(rand()) / RAND_MAX;
	property->SetColor(color);
	doughnut->SetProperty(property);

	mRenderer->AddViewProp(doughnut);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRotateDoughnutClick() {
	transformDoughnut->RotateZ(30);
	doughnut->SetUserTransform(transformDoughnut);

	mRenderer->AddViewProp(doughnut);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onFlipDoughnutClick() {
	transformDoughnut->Scale(-1, 1, 1);
	doughnut->SetUserTransform(transformDoughnut);

	mRenderer->AddViewProp(doughnut);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onTranslateDoughnutClick() {
	transformDoughnut->Translate(1.0, 2.0, 3.0);
	doughnut->SetUserTransform(transformDoughnut);

	mRenderer->AddViewProp(doughnut);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onScaleDoughnutClick() {
	transformDoughnut->Scale(1, 10, 1);
	doughnut->SetUserTransform(transformDoughnut);

	mRenderer->AddViewProp(doughnut);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}