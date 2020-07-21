/*
 * Programación Orientada a Objetos
 * Autor: Joselyn Chérrez <jcherrezl1@estups.edu.ec>
 *
 * PRACTICA 09
 */

#include "principal.h"
#include "ui_principal.h"
#include <QFileDialog>
#include <QDebug>


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->cmdCalcular, SIGNAL(released()),
            this, SLOT(calcular()));
    connect(ui->mnuCalcular, SIGNAL(triggered(bool)),
            this, SLOT(calcular()));
    connect(ui->mnuSalir, SIGNAL(triggered(bool)),
            this, SLOT(close()));
    connect(ui->mnuGuardar, SIGNAL(triggered(bool)),
            this, SLOT(guardar()));
    connect(ui->mnuAbrir, SIGNAL(triggered(bool)),
            this, SLOT(abrir()));
    connect(ui->mnuNuevo, SIGNAL(triggered(bool)),
            this,SLOT(nuevo()));

}

Principal::~Principal()
{
    delete ui;
}


void Principal::calcular()
{

//MODELO
    //obtener datos
    QString nombre =ui->inNombre->text();
    int horas = ui->inHoras->value();

    if (nombre == "" || horas == 0){
        ui->statusbar->showMessage(tr("No se han ingresado datos que se puedan calcular."),5000);
        return;
    }

    float const HORA_EXTRA= 20.10;
//CONTROLADOR
    //Calcular horas extra
    int extra = 0;
    if (horas > 40){
        extra = horas - 40;
        horas = 40;
    }

    //Calcular del salario
    float salario = 0;
    if(ui->inMatutina->isChecked()){
        salario = horas * 5.15 + extra * HORA_EXTRA;
    }else if (ui->inVespertina->isChecked()){
        salario = horas * 8.50 + extra * HORA_EXTRA;
    }else{
        salario = horas * 12.65 + extra * HORA_EXTRA;
    }

    //Calcular el descuento
    float descuento =salario * 9.5 / 100;
    float salario_neto = salario - descuento;

// VISTA
    //Imprimir resultados
    QString resultado = tr("\nObrero: ") + nombre + "\n";
    resultado += tr ("Salario: $")+ QString::number(salario) + "\n";
    resultado += tr ("Descuento (9.5%): $") + QString::number(descuento) + "\n";
    resultado += tr ("Salario neto: $") + QString::number(salario_neto) + "\n";
    resultado += "--\n";

    ui->outResultado->appendPlainText(resultado);
    limpiar();
}

void Principal::guardar()
{
        QString fileName = QFileDialog::getSaveFileName(this,tr("Guardar datos"), QDir::home().absolutePath() ,tr( "Archivo de Texto (*.txt)"));
        QFile data(fileName);
        if (data.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream salida(&data);
            salida << ui->outResultado->toPlainText();
            ui->statusbar->showMessage(tr("Datos almacenados en: " )+ fileName, 5000);
        }
        data.close();
}

void Principal::abrir()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr ("Abrir "), QDir::home().absolutePath() , tr("Archivo de Texto (*.txt)"));
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while (!in.atEnd()){
            QString linea = in.readAll();
            ui->outResultado->setPlainText(linea);
        }
    }

}

void Principal::nuevo()
{
        ui->outResultado->setPlainText("");

}

void Principal::limpiar()
{

    ui->inNombre->setText("");
    ui->inHoras->setValue(0);
    ui->inMatutina->setChecked(true);
    ui->inNombre->setFocus();

}

void Principal::on_actionAcerca_de_triggered()
{
    Acerca_de *ventana1 = new Acerca_de(this);
    ventana1->setModal(true);
    ventana1->show();
}
