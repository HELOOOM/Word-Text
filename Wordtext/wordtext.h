#ifndef WORDTEXT_H
#define WORDTEXT_H

#include <QMainWindow>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class wordtext; }
QT_END_NAMESPACE

class wordtext : public QMainWindow
{
    Q_OBJECT

public:
    wordtext(QWidget *parent = nullptr);
    ~wordtext();

private slots:

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::wordtext *ui;
    QString currentFile=NULL;
      void loadContent(QString currentFile);
      void saveContent(QString currentFile) const;

};
#endif // WORDTEXT_H
