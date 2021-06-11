#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_proiect.h"
#include <__msvc_all_public_headers.hpp>
#include "qcustomplot.h"
#include <QFile>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <QDebug>
#include <QStringList>
#include <QPushButton>
#include <iostream>
#include "filt.h"
#include "math.h"
#define _USE_MATH_DEFINES

using namespace std;

class proiect : public QMainWindow
{
	Q_OBJECT

public:
	
	proiect(QWidget *parent = Q_NULLPTR);
	~proiect();
	QVector<double> deschidereFisierSiReturneazaValori();
	double* v;
	void afisareSemnal(QVector<double> y);
	
	QVector<double> filtruCoeficientAlfa(QVector<double> y);
	QVector<double> filtruMediere(QVector<double> y);
	QVector<double> Integrare(QVector<double> y);
	QVector<double> Derivare(QVector<double> y);

	
	
private:
	Ui::proiectClass ui;
	

private slots:
	
	void afisareFiltruMediere();
	void afisareFiltruAlpha();
	void afisareFiltruIntegrare();
	void afisareFiltruDerivare();

};


double minim(QVector<double> y);
double maxim(QVector<double> y);
double minim(double* v, int n);
double maxim(double* v, int n);