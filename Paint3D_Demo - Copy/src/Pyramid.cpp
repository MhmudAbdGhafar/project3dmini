#include <MainWindow.h>

#include <vtkTriangle.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkMath.h>
#include <vtkTransform.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkClipPolyData.h>
#include <vtkPlane.h>



vtkSmartPointer<vtkActor> pyramidActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkTransform> transformPyramid = vtkSmartPointer<vtkTransform>::New();
void MainWindow::onDrawPyramidClick() {
	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();
	points->InsertNextPoint(0, 0, 0);
	points->InsertNextPoint(5, 5, 0);
	points->InsertNextPoint(10, 0, 0);
	points->InsertNextPoint(5, 0, 5);

	vtkSmartPointer<vtkCellArray> triangles =
		vtkSmartPointer<vtkCellArray>::New();
	vtkSmartPointer<vtkTriangle> triangle =
		vtkSmartPointer<vtkTriangle>::New();

	triangle->GetPointIds()->SetId(0, 0);
	triangle->GetPointIds()->SetId(1, 1);
	triangle->GetPointIds()->SetId(2, 2);
	triangles->InsertNextCell(triangle);

	triangle = vtkSmartPointer<vtkTriangle>::New();
	triangle->GetPointIds()->SetId(0, 0);
	triangle->GetPointIds()->SetId(1, 2);
	triangle->GetPointIds()->SetId(2, 3);
	triangles->InsertNextCell(triangle);

	triangle = vtkSmartPointer<vtkTriangle>::New();
	triangle->GetPointIds()->SetId(0, 0);
	triangle->GetPointIds()->SetId(1, 3);
	triangle->GetPointIds()->SetId(2, 1);
	triangles->InsertNextCell(triangle);

	triangle = vtkSmartPointer<vtkTriangle>::New();
	triangle->GetPointIds()->SetId(0, 1);
	triangle->GetPointIds()->SetId(1, 3);
	triangle->GetPointIds()->SetId(2, 2);
	triangles->InsertNextCell(triangle);

	vtkSmartPointer<vtkPolyData> pyramid =
		vtkSmartPointer<vtkPolyData>::New();
	pyramid->SetPoints(points);
	pyramid->SetPolys(triangles);

	vtkSmartPointer<vtkPolyDataMapper> pyramidMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	pyramidMapper->SetInputData(pyramid);

	//vtkSmartPointer<vtkActor> pyramidActor = vtkSmartPointer<vtkActor>::New();
	pyramidActor->SetMapper(pyramidMapper);

	// Add the pyramid actor to the renderer
	mRenderer->AddActor(pyramidActor);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();

}

void MainWindow::onRemovePyramidClick() {
	// Add the pyramid actor to the renderer
	mRenderer->RemoveViewProp(pyramidActor);

	// Reset the camera
	mRenderer->ResetCamera();

	// Render the scene
	mRenderWindow->Render();

	pyramidActor = vtkSmartPointer<vtkActor>::New();
}

void MainWindow::onChangePyramidColorClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the color of the actor
	property->SetColor(1.0, 0.0, 0.0); // Red color

	double color[3] = { 0, 0, 0 };
	srand(time(NULL));
	color[0] = static_cast<double>(rand()) / RAND_MAX;
	color[1] = static_cast<double>(rand()) / RAND_MAX;
	color[2] = static_cast<double>(rand()) / RAND_MAX;
	property->SetColor(color);
	pyramidActor->SetProperty(property);

	mRenderer->AddViewProp(pyramidActor);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onChangePyramidOpacityClick() {
	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();

	// Change the opacity of the actor
	property->SetOpacity(0.5); // Half transparent
	pyramidActor->SetProperty(property);

	mRenderer->AddViewProp(pyramidActor);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onRotatePyramidClick() {
	transformPyramid->RotateZ(30);
	pyramidActor->SetUserTransform(transformPyramid);

	mRenderer->AddViewProp(pyramidActor);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onFlipPyramidClick() {
	transformPyramid->Scale(-1, 1, 1);
	pyramidActor->SetUserTransform(transformPyramid);

	mRenderer->AddViewProp(pyramidActor);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onTranslatePyramidClick() {
	transformPyramid->Translate(10, 20, 30);
	pyramidActor->SetUserTransform(transformPyramid);

	mRenderer->AddViewProp(pyramidActor);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}

void MainWindow::onScalePyramidClick() {
	transformPyramid->Scale(1, 10, 1);
	pyramidActor->SetUserTransform(transformPyramid);

	mRenderer->AddViewProp(pyramidActor);
	mRenderer->ResetCamera();
	mRenderWindow->Render();
}