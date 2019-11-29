#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QMainWindow>
#include "jsonUtility.h"
#include "message.h"
#include "myClient.h"

class QEvent;
namespace Ui {class EditorWindow;}

class EditorWindow : public QMainWindow {
    Q_OBJECT

public:
    EditorWindow(myClient* client, QWidget *parent = nullptr);
    //COSTRUTTORE DI COPIA --> DECOMMENTA PER RENDERLA VIETATA, NON COPIABILE
    //EditorWindow(const EditorWindow& source) = delete;
    ~EditorWindow();
    bool eventFilter(QObject *obj, QEvent *ev);
private slots:
    //void on_pushButton_3_clicked(); --> Old Rename Function Deprecated

    //Button for change style of the text
    void on_buttonGrassetto_clicked();
    void on_buttonCorsivo_clicked();
    void on_buttonSottolineato_clicked();
    void on_buttonColor_clicked();
    void on_buttonBackgroundColor_clicked();

    //Button for align the text
    void on_buttonAlignDX_clicked();
    void on_buttonAlignCX_clicked();
    void on_buttonAlignSX_clicked();
    void on_buttonAlignJFX_clicked();

    //Button for modify the text
    void on_buttonUndo_clicked();
    void on_buttonRedo_clicked();
    void on_buttonTaglia_clicked();
    void on_buttonIncolla_clicked();
    void on_buttonCopia_clicked();

    //Button for highlight the text
    void on_buttonSearch_clicked();

    //Button for modify font and size of text
    void on_fontDimensionBox_activated(int index);
    void on_fontSelectorBox_currentFontChanged(const QFont &f);

    //RealTextEdit Function
    void on_RealTextEdit_cursorPositionChanged();
    void on_RealTextEdit_textChanged();

    //TopLeftBar Button
    void on_buttonExit_clicked();
    void on_buttonToIcon_clicked();
    void on_buttonReduce_clicked();

    //TopRightBar Button
    void on_fileButton_clicked();
    void on_pdfButton_clicked();
    //void on_uriButton_clicked(); MAYBE WE HAVE TO DELETE THIS

    //FileFrame Button
    //void on_newDocButton_clicked(); MAYBE WE HAVE TO DELETE THIS
    //void on_URIButton_clicked(); MAYBE WE HAVE TO DELETE THIS
    void on_buttonRename_clicked();
    void on_aboutButton_clicked();
    void on_CloseButton_clicked();

    /************************************
     *               EVENT              *
     ************************************/
    void keyPressEvent(QKeyEvent *e);

    /************************************
     *              ACTION              *
     ************************************/
    void on_actionFullscreen_triggered();
    void on_actionSave_triggered();
    void on_actionNew_triggered();
    void on_actionAbout_triggered();

    /************************************
     *        STANDALONE FUNCTION       *
     ************************************/
    void LogoutRequest();
    void PaintItBlack();
    void AlignSXButtonHandler();
    void AlignCXButtonHandler();
    void AlignDXButtonHandler();
    void AlignJFXButtonHandler();
    void AlignButtonStyleHandler();
    void SmokinSexyShowtimeStyleHandler();

    /************************************
     *           DEBUG FUNCTION         *
     ************************************/
    void on_DebugIns1_clicked();
    void on_DebugInsInit_clicked();
    void on_DebugDel1_clicked();
    void on_DebugCursLeft_clicked();
    void on_DebugCursRight_clicked();
    void on_DebugCursLeftAnchor_clicked();
    void on_DebugWordLeft_clicked();
    void on_DebugWordRight_clicked();
    void on_DebugIns6Word_clicked();
    void on_buttonDarkMode_clicked();

    void on_actionExit_triggered();

public slots:
    void showPopupSuccess(QString result, std::string filename = "");
    void showPopupFailure(QString result);
    void showSymbol(std::pair<int, wchar_t> tuple);
    void eraseSymbol(int index);
    void eraseSymbols(int startIndex, int endIndex);
    void showSymbols(std::vector<symbol> symbols);

private:
    Ui::EditorWindow *ui;
    QPoint oldPos;                  //This "oldPos" object is used to save the old position of the windows for the translation of windows
    void sendRequestMsg(std::string req);
    myClient *_client;

protected:
    //Function for mouse related event
    void mousePressEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);
    //void keyPressEvent(QKeyEvent *event);
};

#endif // EDITORWINDOW_H
