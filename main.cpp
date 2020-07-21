#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Objeto para manejar las traducciones
    QTranslator traduccion;
    //Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Italiano" << "Francés" << "Español";

    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                   "Idioma",
                                   "Seleccione un idioma",
                                   idiomas);
    //Dependiendo del idioma seleccionado, carga el archivo de traduccion
    if (idiomaSeleccionado == "Italiano"){
        traduccion.load(":/Salario1_it.qm");
    }else if (idiomaSeleccionado == "Francés"){
        traduccion.load(":/Salario1_fr_FR.qm");
    }
    //Si es diferente de español, se instala la traduccion en TODA la aplicacion
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traduccion);
    }

    //Ventana principal
    Principal w;
    w.show();
    return a.exec();
}
