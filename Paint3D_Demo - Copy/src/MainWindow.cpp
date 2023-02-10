#include <MainWindow.h>

#include "ui_MainWindow.h"

#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkConeSource.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkSmartPointer.h>
#include <vtkProperty.h>
#include <vtkClipPolyData.h>
#include <vtkPlane.h>
#include <vtkTriangle.h>
#include <vtkCylinderSource.h>
#include <vtkLineSource.h>
#include <vtkTubeFilter.h>
#include <vtkRegularPolygonSource.h>
#include <vtkParametricSpline.h>
#include <vtkParametricFunctionSource.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
    mRenderer(vtkSmartPointer<vtkRenderer>::New()),
    mInteractor(vtkSmartPointer<QVTKInteractor>::New()),
    mInteractorStyle(vtkSmartPointer<vtkInteractorStyle>::New())
{
    ui->setupUi(this);

	// Set up the rendering
	mRenderWindow->AddRenderer(mRenderer);
	mRenderWindow->SetInteractor(mInteractor);
	ui->openGLWidget->setRenderWindow(mRenderWindow);
	mInteractor->SetInteractorStyle(mInteractorStyle);
	mInteractor->Initialize();

	// Set the background color 
	//mRenderer->SetBackground(1, 0, 0);

	// Set the UI connections
	//set Sphere ui connections
	QObject::connect(ui->DrawSphere_Button, &QPushButton::clicked,
		this, &MainWindow::onDrawSphereClick);
	QObject::connect(ui->RemoveSphere_Button, &QPushButton::clicked,
		this, &MainWindow::onRemoveSphereClick);
	QObject::connect(ui->ChangeSphereColor_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeSphereColorClick);
	QObject::connect(ui->ChangeSphereOpacity_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeSphereOpacityClick);
	QObject::connect(ui->RotateSphere_Button, &QPushButton::clicked,
		this, &MainWindow::onRotateSphereClick);
	QObject::connect(ui->FlipSphere_Button, &QPushButton::clicked,
		this, &MainWindow::onFlipSphereClick);
	QObject::connect(ui->TranslateSphere_Button, &QPushButton::clicked,
		this, &MainWindow::onTranslateSphereClick);
	QObject::connect(ui->ScaleSphere_Button, &QPushButton::clicked,
		this, &MainWindow::onScaleSphereClick);
	


	//set Cube ui connections
	QObject::connect(ui->DrawCube_Button, &QPushButton::clicked,
		this, &MainWindow::onDrawCubeClick);
	QObject::connect(ui->RemoveCube_Button, &QPushButton::clicked,
		this, &MainWindow::onRemoveCubeClick);
	QObject::connect(ui->ChangeCubeColor_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeCubeColorClick);
	QObject::connect(ui->ChangeCubeOpacity_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeCubeOpacityClick);
	QObject::connect(ui->RotateCube_Button, &QPushButton::clicked,
		this, &MainWindow::onRotateCubeClick);
	QObject::connect(ui->FlipCube_Button, &QPushButton::clicked,
		this, &MainWindow::onFlipCubeClick);
	QObject::connect(ui->TranslateCube_Button, &QPushButton::clicked,
		this, &MainWindow::onTranslateCubeClick);
	QObject::connect(ui->ScaleCube_Button, &QPushButton::clicked,
		this, &MainWindow::onScaleCubeClick);



	//set Cone ui connections
	QObject::connect(ui->DrawCone_Button, &QPushButton::clicked,
		this, &MainWindow::onDrawConeClick);
	QObject::connect(ui->RemoveCone_Button, &QPushButton::clicked,
		this, &MainWindow::onRemoveConeClick);
	QObject::connect(ui->ChangeConeColor_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeConeColorClick);
	QObject::connect(ui->ChangeConeOpacity_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeConeOpacityClick);
	QObject::connect(ui->RotateCone_Button, &QPushButton::clicked,
		this, &MainWindow::onRotateConeClick);
	QObject::connect(ui->FlipCone_Button, &QPushButton::clicked,
		this, &MainWindow::onFlipConeClick);
	QObject::connect(ui->TranslateCone_Button, &QPushButton::clicked,
		this, &MainWindow::onTranslateConeClick);
	QObject::connect(ui->ScaleCone_Button, &QPushButton::clicked,
		this, &MainWindow::onScaleConeClick);



	//set Hemisphere ui connections
	QObject::connect(ui->DrawHemiSphere_Buttom, &QPushButton::clicked,
		this, &MainWindow::onDrawHemiSphereClick);
	QObject::connect(ui->RemoveHemiSphere_Button, &QPushButton::clicked,
		this, &MainWindow::onRemoveHemiSphereClick);
	QObject::connect(ui->ChangeHemisphereColor_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeHemisphereColorClick);
	QObject::connect(ui->ChangeHemisphereOpacity_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeHemisphereOpacityClick);
	QObject::connect(ui->RotateHemisphere_Button, &QPushButton::clicked,
		this, &MainWindow::onRotateHemisphereClick);
	QObject::connect(ui->FlipHemisphere_Button, &QPushButton::clicked,
		this, &MainWindow::onFlipHemisphereClick);
	QObject::connect(ui->TranslateHemisphere_Button, &QPushButton::clicked,
		this, &MainWindow::onTranslateHemisphereClick);
	QObject::connect(ui->ScaleHemisphere_Button, &QPushButton::clicked,
		this, &MainWindow::onScaleHemisphereClick);



	//set Pyramid ui connections
	QObject::connect(ui->DrawPyramid_Button, &QPushButton::clicked,
		this, &MainWindow::onDrawPyramidClick);
	QObject::connect(ui->RemovePyramid_Button, &QPushButton::clicked,
		this, &MainWindow::onRemovePyramidClick);
	QObject::connect(ui->ChangePyramidColor_Button, &QPushButton::clicked,
		this, &MainWindow::onChangePyramidColorClick);
	QObject::connect(ui->ChangePyramidOpacity_Button, &QPushButton::clicked,
		this, &MainWindow::onChangePyramidOpacityClick);
	QObject::connect(ui->RotatePyramid_Button, &QPushButton::clicked,
		this, &MainWindow::onRotatePyramidClick);
	QObject::connect(ui->FlipPyramid_Button, &QPushButton::clicked,
		this, &MainWindow::onFlipPyramidClick);
	QObject::connect(ui->TranslatePyramid_Button, &QPushButton::clicked,
		this, &MainWindow::onTranslatePyramidClick);
	QObject::connect(ui->ScalePyramid_Button, &QPushButton::clicked,
		this, &MainWindow::onScalePyramidClick);



	//set Cylinder ui connections
	QObject::connect(ui->DrawCylinder_Button, &QPushButton::clicked,
			this, &MainWindow::onDrawCylinderClick);
	QObject::connect(ui->RemoveCylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onRemoveCylinderClick);
	QObject::connect(ui->ChangeCylinderColor_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeCylinderColorClick);
	QObject::connect(ui->ChangeCylinderOpacity_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeCylinderOpacityClick);
	QObject::connect(ui->RotateCylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onRotateCylinderClick);
	QObject::connect(ui->FlipCylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onFlipCylinderClick);
	QObject::connect(ui->TranslateCylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onTranslateCylinderClick);
	QObject::connect(ui->ScaleCylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onScaleCylinderClick);



	//set Tube ui connections
	QObject::connect(ui->DrawTube_Button, &QPushButton::clicked,
				this, &MainWindow::onDrawTubeClick);
	QObject::connect(ui->RemoveTube_Button, &QPushButton::clicked,
		this, &MainWindow::onRemoveTubeClick);
	QObject::connect(ui->ChangeTubeColor_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeTubeColorClick);
	QObject::connect(ui->ChangeTubeOpacity_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeTubeOpacityClick);
	QObject::connect(ui->RotateTube_Button, &QPushButton::clicked,
		this, &MainWindow::onRotateTubeClick);
	QObject::connect(ui->FlipTube_Button, &QPushButton::clicked,
		this, &MainWindow::onFlipTubeClick);
	QObject::connect(ui->TranslateTube_Button, &QPushButton::clicked,
		this, &MainWindow::onTranslateTubeClick);
	QObject::connect(ui->ScaleTube_Button, &QPushButton::clicked,
		this, &MainWindow::onScaleTubeClick);



	//set Doughnut ui connections
	QObject::connect(ui->DrawDoughnut_Button, &QPushButton::clicked,
					this, &MainWindow::onDrawDoughnutClick);
	QObject::connect(ui->RemoveDoughnut_Button, &QPushButton::clicked,
		this, &MainWindow::onRemoveDoughnutClick);
	QObject::connect(ui->ChangeDoughnutColor_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeDoughnutColorClick);
	QObject::connect(ui->ChangeDoughnutOpacity_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeDoughnutOpacityClick);
	QObject::connect(ui->RotateDoughnut_Button, &QPushButton::clicked,
		this, &MainWindow::onRotateDoughnutClick);
	QObject::connect(ui->FlipDoughnut_Button, &QPushButton::clicked,
		this, &MainWindow::onFlipDoughnutClick);
	QObject::connect(ui->TranslateDoughnut_Button, &QPushButton::clicked,
		this, &MainWindow::onTranslateDoughnutClick);
	QObject::connect(ui->ScaleDoughnut_Button, &QPushButton::clicked,
		this, &MainWindow::onScaleDoughnutClick);



	//set Curvedcylinder ui connections
	QObject::connect(ui->DrawCurvedCylinder_Button, &QPushButton::clicked,
						this, &MainWindow::onDrawCurvedCylinderClick);
	QObject::connect(ui->RemoveCurvedCylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onRemoveCurvedCylinderClick);
	QObject::connect(ui->ChangeCurvedcylinderColor_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeCurvedcylinderColorClick);
	QObject::connect(ui->ChangeCurvedcylinderOpacity_Button, &QPushButton::clicked,
		this, &MainWindow::onChangeCurvedcylinderOpacityClick);
	QObject::connect(ui->RotateCurvedcylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onRotateCurvedcylinderClick);
	QObject::connect(ui->FlipCurvedcylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onFlipCurvedcylinderClick);
	QObject::connect(ui->TranslateCurvedcylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onTranslateCurvedcylinderClick);
	QObject::connect(ui->ScaleCurvedcylinder_Button, &QPushButton::clicked,
		this, &MainWindow::onScaleCurvedcylinderClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}


