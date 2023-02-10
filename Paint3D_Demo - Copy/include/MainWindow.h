#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <QVTKInteractor.h>
#include <vtkInteractorStyle.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;

    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow;
    vtkSmartPointer<vtkRenderer> mRenderer;
    vtkSmartPointer<QVTKInteractor> mInteractor;
    vtkSmartPointer<vtkInteractorStyle> mInteractorStyle;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    //Sphere
    void onDrawSphereClick();
    void onRemoveSphereClick();
    void onChangeSphereColorClick();
    void onChangeSphereOpacityClick();
    void onRotateSphereClick();
    void onFlipSphereClick();
    void onTranslateSphereClick();
    void onScaleSphereClick();
    

    //Cube
    void onDrawCubeClick();
    void onRemoveCubeClick();
    void onChangeCubeColorClick();
    void onChangeCubeOpacityClick();
    void onRotateCubeClick();
    void onFlipCubeClick();
    void onTranslateCubeClick();
    void onScaleCubeClick();


    //Cone
    void onDrawConeClick();
    void onRemoveConeClick();
    void onChangeConeColorClick();
    void onChangeConeOpacityClick();
    void onRotateConeClick();
    void onFlipConeClick();
    void onTranslateConeClick();
    void onScaleConeClick();


    //Hemisphere
    void onDrawHemiSphereClick();
    void onRemoveHemiSphereClick();
    void onChangeHemisphereColorClick();
    void onChangeHemisphereOpacityClick();
    void onRotateHemisphereClick();
    void onFlipHemisphereClick();
    void onTranslateHemisphereClick();
    void onScaleHemisphereClick();


    //Pyramid
    void onDrawPyramidClick();
    void onRemovePyramidClick();
    void onChangePyramidColorClick();
    void onChangePyramidOpacityClick();
    void onRotatePyramidClick();
    void onFlipPyramidClick();
    void onTranslatePyramidClick();
    void onScalePyramidClick();


    //Cylinder
    void onDrawCylinderClick();
    void onRemoveCylinderClick();
    void onChangeCylinderColorClick();
    void onChangeCylinderOpacityClick();
    void onRotateCylinderClick();
    void onFlipCylinderClick();
    void onTranslateCylinderClick();
    void onScaleCylinderClick();


    //Tube
    void onDrawTubeClick();
    void onRemoveTubeClick();
    void onChangeTubeColorClick();
    void onChangeTubeOpacityClick();
    void onRotateTubeClick();
    void onFlipTubeClick();
    void onTranslateTubeClick();
    void onScaleTubeClick();


    //Doughnut
    void onDrawDoughnutClick();
    void onRemoveDoughnutClick();
    void onChangeDoughnutColorClick();
    void onChangeDoughnutOpacityClick();
    void onRotateDoughnutClick();
    void onFlipDoughnutClick();
    void onTranslateDoughnutClick();
    void onScaleDoughnutClick();


    //Curvedcylinder
    void onDrawCurvedCylinderClick();
    void onRemoveCurvedCylinderClick();
    void onChangeCurvedcylinderColorClick();
    void onChangeCurvedcylinderOpacityClick();
    void onRotateCurvedcylinderClick();
    void onFlipCurvedcylinderClick();
    void onTranslateCurvedcylinderClick();
    void onScaleCurvedcylinderClick();
};

#endif // MAINWINDOW_H
