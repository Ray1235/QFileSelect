#ifndef QFILESELECT_H
#define QFILESELECT_H

#include <QWidget>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>

class QFileSelect : public QWidget
{
	Q_OBJECT

public:
	QFileSelect(QStringList fileFilter = QStringList(), QString label = "", QWidget *parent = NULL);
	~QFileSelect();
	
	QString getPath();

	QLabel *m_pPathLabel;
	QHBoxLayout *m_pPathLayout;
	QLineEdit *m_pPathBox;
	QPushButton *m_pPathBrowse;

	QFileDialog *m_pFileDialog;

protected slots:
	void OnBrowsePath();
};

#endif
