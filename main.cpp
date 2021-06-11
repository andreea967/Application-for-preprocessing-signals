#include "proiect.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	int n=16;
	double alfa = 0.5;
	QApplication a(argc, argv);
	proiect w;

	w.deschidereFisierSiReturneazaValori();
	w.afisareSemnal(w.deschidereFisierSiReturneazaValori());

	w.showMaximized();
	
	return a.exec();
}
