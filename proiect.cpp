#include "proiect.h"
#include "qcustomplot.h"


proiect::proiect(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    connect(ui.filtru_alfa, SIGNAL(released()), this, SLOT(afisareFiltruAlpha()));
    connect(ui.filtru_mediere, SIGNAL(released()), this, SLOT(afisareFiltruMediere()));
    connect(ui.integrare, SIGNAL(released()), this, SLOT(afisareFiltruIntegrare()));
    connect(ui.derivare, SIGNAL(released()), this, SLOT(afisareFiltruDerivare()));

}


QVector<double> proiect::filtruCoeficientAlfa(QVector<double> y) {
    double alfa = ui.alfa->text().toDouble();
    if (alfa < 0.1 || alfa >0.9) {
        throw std::invalid_argument("Alfa trebuie sa fie intre 0 si 1");
    }
    QVector<double> alphaFilter(y.count());
    for (int i = 1; i < y.count()-1; i++) {
        alphaFilter[i] = ((1 - alfa) * alphaFilter[i - 1] + alfa * y[i]);
    }
    return alphaFilter;
}

QVector<double> proiect::filtruMediere(QVector<double> y) {
    int avgWndLen = ui.esantion->text().toInt();
    QVector<double> averageFilter(y.count());
    double sum = 0;
    for (int i = 0; i < avgWndLen; ++i) {
        averageFilter[i] = y[i];
        sum += averageFilter[i];
    }
    for (int i = avgWndLen; i < y.count(); ++i) {
        averageFilter[i] = sum / avgWndLen;
        sum -= y[i - avgWndLen];
        sum += y[i];
    }
    averageFilter[y.count() - 1] = sum / avgWndLen;
    return averageFilter;
}

QVector<double> proiect::Integrare(QVector<double> y) {
    QVector<double> integrat(y.count());
    integrat[0]=y[0];
    for (int i = 1; i < y.count()-1; i++) {
            integrat[i] = (y[i + 1] - y[i]) * ((y[i] + y[i + 1]) / 2);
    }
    return integrat;
}

QVector<double> proiect::Derivare(QVector<double> y) {
    QVector<double> derivat(y.count());
    derivat[0] = 0;
    for (int i = 1; i < y.count(); i++) {
        derivat[i] = y[i] - y[i - 1];
    }
    return derivat;
}

double maxim(QVector<double> y) {
    int n = y.count();
    double max = *(std::max_element(y.constBegin(), y.constEnd()));
    return max;
}

double minim(QVector<double> y)
{
    int n = y.count();
    double min = *(std::min_element(y.constBegin(), y.constEnd()));
    return min;
}

double minim(double *v, int n)
{
    double min = *(std::min_element(&v[0], &v[n - 1]));
    return min;
}

double maxim(double* v, int n)
{
    double max = *(std::max_element(&v[0], &v[n - 1]));
    return max;
}

proiect::~proiect()
{
    delete v;
}

QVector<double> proiect::deschidereFisierSiReturneazaValori() {
    QFile f("input.csv");
    QStringList word;
    if (f.open(QIODevice::ReadOnly)) {
        QString data;
        while (!f.atEnd()) {
            QByteArray line = f.readLine();

            int index = line.indexOf(',');
            if (index != -1) {
                QByteArray second = line.mid(index + 1);
                word.append(second);
            }
            else {
                word.append(line);
            }
        }
        int n = word.count();
        v = new double[n];
        int i = 0;
        for (; i < n; i++) {
            v[i] = word[i].toDouble();
        }
   
        QVector<double> vector_y(n);
         for (int j = 0; j < n; j++)
        {
            vector_y[j] = v[j];
        }
        return vector_y;
    }
}


void proiect::afisareSemnal(QVector<double> y)
{
        QVector<double> x(y.count()), z(y.count());
         for (int j = 0; j < y.count(); j++)
         {
             x[j] = j;
             z[j] = v[j];
         }
        ui.customplot->addGraph();
        ui.customplot->graph(0)->setData(x, y);
        ui.customplot->graph(0)->setPen(QPen(Qt::blue));
        ui.customplot->xAxis->setLabel("x");
        ui.customplot->yAxis->setLabel("y");
        ui.customplot->xAxis->setRange(0, y.count());
        double min_range = minim(v, y.count());
        double max_range = maxim(v, y.count());
        ui.customplot->yAxis->setRange(min_range, max_range);
        ui.customplot->xAxis->setVisible(true);
        ui.customplot->yAxis->setVisible(true);
        ui.customplot->graph(0)->rescaleAxes();
        ui.customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui.customplot->replot();
}

void proiect::afisareFiltruMediere()
{

    QVector<double> y = filtruMediere(deschidereFisierSiReturneazaValori());
    QVector<double> x(y.count()), z(y.count());
    for (int j = 0; j < y.count(); j++)
    {
        x[j] = j;
        z[j] = v[j];
    }
    ui.filtru->addGraph();
    ui.filtru->graph(0)->setData(x, y);
    ui.filtru->graph(0)->setPen(QPen(Qt::red));
    ui.filtru->xAxis->setLabel("x");
    ui.filtru->yAxis->setLabel("y");
    ui.filtru->xAxis->setRange(0, y.count());
    double min_range = minim(v, y.count());
    double max_range = maxim(v, y.count());
    ui.filtru->yAxis->setRange(-3, 3);
    ui.filtru->xAxis->setVisible(true);
    ui.filtru->yAxis->setVisible(true);
    ui.filtru->graph(0)->rescaleAxes();
    ui.filtru->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui.filtru->replot();
}

void proiect::afisareFiltruAlpha()
{
    try {
        QVector<double> y = filtruCoeficientAlfa(deschidereFisierSiReturneazaValori());
        QVector<double> x(y.count()), z(y.count());
        for (int j = 0; j < y.count(); j++)
        {
            x[j] = j;
            z[j] = v[j];
        }
        ui.filtru->addGraph();
        ui.filtru->graph(0)->setData(x, y);
        ui.filtru->graph(0)->setPen(QPen(Qt::green));
        ui.filtru->xAxis->setLabel("x");
        ui.filtru->yAxis->setLabel("y");
        ui.filtru->xAxis->setRange(0, y.count());
        double min_range = minim(v, y.count());
        double max_range = maxim(v, y.count());
        ui.filtru->yAxis->setRange(-3, 3);
        ui.filtru->xAxis->setVisible(true);
        ui.filtru->yAxis->setVisible(true);
        ui.filtru->graph(0)->rescaleAxes();
        ui.filtru->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui.filtru->replot();
    }
    catch (std::invalid_argument & e) {
        QMessageBox::about(this, "Message", "Alfa trebuie sa fie intre 0 si 1");
    }

}

void proiect::afisareFiltruIntegrare()
{
 
    QVector<double> y = Integrare(deschidereFisierSiReturneazaValori());
    QVector<double> x(y.count()), z(y.count());
    for (int j = 0; j < y.count(); j++)
    {
        x[j] = j;
        z[j] = v[j];
    }
    ui.filtru->addGraph();
    ui.filtru->graph(0)->setData(x, y);
    ui.filtru->graph(0)->setPen(QPen(Qt::magenta));
    ui.filtru->xAxis->setLabel("x");
    ui.filtru->yAxis->setLabel("y");
    ui.filtru->xAxis->setRange(0, y.count());
    double min_range = minim(v, y.count());
    double max_range = maxim(v, y.count());
    ui.filtru->yAxis->setRange(-3, 3);
    ui.filtru->xAxis->setVisible(true);
    ui.filtru->yAxis->setVisible(true);
    ui.filtru->graph(0)->rescaleAxes();
    ui.filtru->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui.filtru->replot();
}

void proiect::afisareFiltruDerivare()
{
    
    QVector<double> y = Derivare(deschidereFisierSiReturneazaValori());
    QVector<double> x(y.count()), z(y.count());
    for (int j = 0; j < y.count(); j++)
    {
        x[j] = j;
        z[j] = v[j];
    }
    ui.filtru->addGraph();
    ui.filtru->graph(0)->setData(x, y);
    ui.filtru->graph(0)->setPen(QPen(Qt::red));
    ui.filtru->xAxis->setLabel("x");
    ui.filtru->yAxis->setLabel("y");
    ui.filtru->xAxis->setRange(0, y.count());
    double min_range = minim(v, y.count());
    double max_range = maxim(v, y.count());
    ui.filtru->yAxis->setRange(-3, 3);
    ui.filtru->xAxis->setVisible(true);
    ui.filtru->yAxis->setVisible(true);
    ui.filtru->graph(0)->rescaleAxes();
    ui.filtru->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui.filtru->replot();
}
