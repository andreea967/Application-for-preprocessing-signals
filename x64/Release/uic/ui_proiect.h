/********************************************************************************
** Form generated from reading UI file 'proiect.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROIECT_H
#define UI_PROIECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_proiectClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customplot;
    QCustomPlot *filtru;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *min;
    QLineEdit *max;
    QLineEdit *alfa;
    QLineEdit *esantion;
    QLineEdit *taps;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QPushButton *banda;
    QPushButton *filtru_alfa;
    QPushButton *filtru_sus;
    QPushButton *filtru_jos;
    QPushButton *filtru_mediere;
    QPushButton *derivare;
    QPushButton *integrare;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *proiectClass)
    {
        if (proiectClass->objectName().isEmpty())
            proiectClass->setObjectName(QString::fromUtf8("proiectClass"));
        proiectClass->resize(1737, 999);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(proiectClass->sizePolicy().hasHeightForWidth());
        proiectClass->setSizePolicy(sizePolicy);
        proiectClass->setMinimumSize(QSize(0, 0));
        proiectClass->setMouseTracking(false);
        proiectClass->setStyleSheet(QString::fromUtf8("background-color: rgb(122, 118, 127);\n"
"background-color: rgb(230, 234, 255);"));
        proiectClass->setIconSize(QSize(100, 100));
        centralWidget = new QWidget(proiectClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 11, 1721, 911));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        customplot = new QCustomPlot(layoutWidget);
        customplot->setObjectName(QString::fromUtf8("customplot"));
        customplot->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(customplot);

        filtru = new QCustomPlot(layoutWidget);
        filtru->setObjectName(QString::fromUtf8("filtru"));

        verticalLayout->addWidget(filtru);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);


        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        min = new QLineEdit(layoutWidget);
        min->setObjectName(QString::fromUtf8("min"));

        verticalLayout_2->addWidget(min);

        max = new QLineEdit(layoutWidget);
        max->setObjectName(QString::fromUtf8("max"));

        verticalLayout_2->addWidget(max);

        alfa = new QLineEdit(layoutWidget);
        alfa->setObjectName(QString::fromUtf8("alfa"));

        verticalLayout_2->addWidget(alfa);

        esantion = new QLineEdit(layoutWidget);
        esantion->setObjectName(QString::fromUtf8("esantion"));

        verticalLayout_2->addWidget(esantion);

        taps = new QLineEdit(layoutWidget);
        taps->setObjectName(QString::fromUtf8("taps"));

        verticalLayout_2->addWidget(taps);


        gridLayout->addLayout(verticalLayout_2, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 1, 3, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        banda = new QPushButton(layoutWidget);
        banda->setObjectName(QString::fromUtf8("banda"));

        verticalLayout_4->addWidget(banda);

        filtru_alfa = new QPushButton(layoutWidget);
        filtru_alfa->setObjectName(QString::fromUtf8("filtru_alfa"));

        verticalLayout_4->addWidget(filtru_alfa);

        filtru_sus = new QPushButton(layoutWidget);
        filtru_sus->setObjectName(QString::fromUtf8("filtru_sus"));

        verticalLayout_4->addWidget(filtru_sus);

        filtru_jos = new QPushButton(layoutWidget);
        filtru_jos->setObjectName(QString::fromUtf8("filtru_jos"));

        verticalLayout_4->addWidget(filtru_jos);

        filtru_mediere = new QPushButton(layoutWidget);
        filtru_mediere->setObjectName(QString::fromUtf8("filtru_mediere"));

        verticalLayout_4->addWidget(filtru_mediere);

        derivare = new QPushButton(layoutWidget);
        derivare->setObjectName(QString::fromUtf8("derivare"));

        verticalLayout_4->addWidget(derivare);

        integrare = new QPushButton(layoutWidget);
        integrare->setObjectName(QString::fromUtf8("integrare"));

        verticalLayout_4->addWidget(integrare);


        gridLayout->addLayout(verticalLayout_4, 1, 0, 1, 1);

        proiectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(proiectClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1737, 18));
        proiectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(proiectClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        proiectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(proiectClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        proiectClass->setStatusBar(statusBar);

        retranslateUi(proiectClass);
        QObject::connect(filtru_jos, SIGNAL(clicked()), filtru, SLOT(show()));
        QObject::connect(filtru_sus, SIGNAL(clicked()), filtru, SLOT(show()));
        QObject::connect(filtru_alfa, SIGNAL(clicked()), filtru, SLOT(show()));
        QObject::connect(filtru_mediere, SIGNAL(clicked()), filtru, SLOT(show()));
        QObject::connect(derivare, SIGNAL(clicked()), filtru, SLOT(show()));

        QMetaObject::connectSlotsByName(proiectClass);
    } // setupUi

    void retranslateUi(QMainWindow *proiectClass)
    {
        proiectClass->setWindowTitle(QApplication::translate("proiectClass", "proiect", nullptr));
        label->setText(QApplication::translate("proiectClass", "Frecventa minima", nullptr));
        label_2->setText(QApplication::translate("proiectClass", "Frecventa maxima", nullptr));
        label_3->setText(QApplication::translate("proiectClass", "         alfa     ", nullptr));
        label_4->setText(QApplication::translate("proiectClass", "nr. esantioane", nullptr));
        label_5->setText(QApplication::translate("proiectClass", "Number of taps", nullptr));
        banda->setText(QApplication::translate("proiectClass", "Filtru banda", nullptr));
        filtru_alfa->setText(QApplication::translate("proiectClass", "Filtru Alfa", nullptr));
        filtru_sus->setText(QApplication::translate("proiectClass", "Filtru trece-sus", nullptr));
        filtru_jos->setText(QApplication::translate("proiectClass", "Filtru trece-jos", nullptr));
        filtru_mediere->setText(QApplication::translate("proiectClass", "Filtru mediere", nullptr));
        derivare->setText(QApplication::translate("proiectClass", "Derivare", nullptr));
        integrare->setText(QApplication::translate("proiectClass", "Integrare", nullptr));
    } // retranslateUi

};

namespace Ui {
    class proiectClass: public Ui_proiectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROIECT_H
