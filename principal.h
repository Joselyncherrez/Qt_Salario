/*
 * Programación Orientada a Objetos
 * Autor: Joselyn Chérrez <jcherrezl1@estups.edu.ec>
 *
 * PRACTICA 09
 */

#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <acerca_de.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

public slots:
    void calcular();
    void guardar();
    void abrir();
    void nuevo();


private slots:
    void on_actionAcerca_de_triggered();

private:
    Ui::Principal *ui;
    void limpiar();

};
#endif // PRINCIPAL_H
