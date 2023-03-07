#include "clickableLabels.h"

clickablelabels::clickablelabels(const QString & text, QWidget* parent) : QLabel(parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(slotClicked()));
}

void clickablelabels::mousePressEvent(QMouse * event)
{
    emit clicked();
}

void clickablelabels::slotClicked()
{
    qDebug() << "clicked\n";
}
