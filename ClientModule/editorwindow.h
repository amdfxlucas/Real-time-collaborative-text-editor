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
    //EditorWindow(const EditorWindow& source) = delete;
    ~EditorWindow();
    bool eventFilter(QObject *obj, QEvent *ev);

private slots:

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

    //OLD TopLeftBar Button
    //void on_buttonExit_clicked();
    //void on_buttonToIcon_clicked();
    //void on_buttonReduce_clicked();

    //ViewFrame Button

    /************************************
     *               EVENT              *
     ************************************/
    void keyPressEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent * event);
    /************************************
     *              ACTION              *
     ************************************/
    void on_actionFullscreen_triggered();
    void on_actionNew_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();
    void on_actionRinomina_triggered();
    void on_actionEsporta_come_PDF_triggered();
    void on_actionInvita_tramite_URI_triggered();
    void on_actionDark_Mode_triggered();
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

public slots:
    void showPopupSuccess(QString result, std::string filename = "");
    void showPopupFailure(QString result);
    void showSymbol(std::pair<int, wchar_t> tuple, symbolStyle style);
    void eraseSymbol(int index);
    void eraseSymbols(int startIndex, int endIndex);
    void formatSymbols(int startIndex, int endIndex, int format);
    void showSymbolsAt(int startIndex, std::vector<symbol> symbols);    

private:
    Ui::EditorWindow *ui;
    void sendRequestMsg(std::string req);
    myClient *_client;
    QString docName = _client->getFilename().toLatin1(); //toLatin1 accept accented char
    QString textOnTitleBar;
    bool BruteClose=true;
    symbolStyle getCurCharStyle();
    symbolStyle getStyleFromHTMLStyles(QVector<QVector<QString>>& styles);
    QVector<QVector<QString>> getStylesFromHTML(QString htmlText);
    void sendFormatRequest(int format);
    enum formatType {MAKE_BOLD=0, MAKE_ITALIC=1, MAKE_UNDERLINE=2, UNMAKE_BOLD=3, UNMAKE_ITALIC=4, UNMAKE_UNDERLINE=5, FORMAT_UNKNOWN=6};

};

#endif // EDITORWINDOW_H
