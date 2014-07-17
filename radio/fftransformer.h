#ifndef FFTRANSFORMER_H
#define FFTRANSFORMER_H

#include <QObject>
#include "mainwindow.h"
#include "fftw3.h"

typedef std::complex<double> Complex;

//todo: a worker, make sample queue, ttransform fixed count - 10000
class FFTransformer : public QObject
{
    Q_OBJECT

private:
    fftw_complex *m_inBuffer, *m_outBuffer;
    fftw_plan m_plan;
    size_t m_bufferSize;

public:
    explicit FFTransformer(size_t bufferSize, MainWindow *parent = 0);
    ~FFTransformer();

signals:

public slots:
    void onDataReceived(Complex * data, size_t count);
    void init();

};

#endif
