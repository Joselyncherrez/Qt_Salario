/*
 * Programación Orientada a Objetos
 * Autor: Joselyn Chérrez <jcherrezl1@estups.edu.ec>
 *
 * PRACTICA 09
 */
#include "acerca_de.h"
#include "ui_acerca_de.h"

Acerca_de::Acerca_de(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca_de)
{
    ui->setupUi(this);
}

Acerca_de::~Acerca_de()
{
    delete ui;
}
