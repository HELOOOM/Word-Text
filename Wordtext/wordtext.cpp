#include "wordtext.h"
#include "ui_wordtext.h"
#include <QTextStream>

wordtext::wordtext(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wordtext)
{
    ui->setupUi(this);
}

wordtext::~wordtext()
{
    delete ui;
}





void wordtext::on_actionOpen_triggered()
{
    QFileDialog l ;
    currentFile= l.getOpenFileName();

      setWindowTitle(currentFile);

      loadContent(currentFile);




}

void wordtext::saveContent(QString filename)const
{
    //Gettign a pointer on the file
    QFile file(filename);

    //Openign the file
    if(file.open(QIODevice::WriteOnly))  //Opening the file in writing mode

    {          auto text = ui->plainTextEdit->toPlainText();

        QTextStream in(&file);


               in << text ;
           }


    file.close();

}
void wordtext::loadContent(QString filename){
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly )) {
        QTextStream in(&file);




    while (!in.atEnd()) {
        QString line = in.readLine();
    ui->plainTextEdit->textCursor().insertText(line);
ui->plainTextEdit->textCursor().insertText("\n");
        // now, line will be a string of the whole line, if you're trying to read a CSV or something, you can split the string

    }
}

 // opens "/home/readme.txt" under Unix
}







void wordtext::on_actionSave_triggered()
{
    //Creating a file dialog to choose a file graphically
    auto dialog = new QFileDialog(this);

    //Check if the current file has a name or not
    if(currentFile == "")
    {
      currentFile = dialog->getSaveFileName(this,"choose your file");

       //Update the window title with the file name
       setWindowTitle(currentFile);

    }

   //If we have a name simply save the content
   if( currentFile != "")
   {
           saveContent(currentFile);
   }

}

