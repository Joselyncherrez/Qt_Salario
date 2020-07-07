/*
 * Programación Orientada a Objetos
 * Autor: Joselyn Chérrez <jcherrezl1@estups.edu.ec>
 *
 * PRACTICA 09
 */

#ifndef SALARIO_H
#define SALARIO_H

#include <QObject>

class Salario : public QObject
{
    Q_OBJECT
public:
    explicit Salario(QObject *parent = nullptr);

signals:

};

#endif // SALARIO_H
