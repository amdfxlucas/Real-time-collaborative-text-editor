#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "editorstate.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(EditorState& estate, QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_Save_clicked();
    void on_pushButton_clicked();
    void on_day_clicked();
    void on_Default_clicked();

private:
    void WriteSettingOnFile();

private:
    Ui::Settings *ui;
    EditorState &estate;
};

#endif // SETTINGS_H