#include "QFileSelect.h"

QFileSelect::QFileSelect(QStringList fileFilter, QString label, QWidget *parent)
	: QWidget(parent)
{
	m_pFileDialog = new QFileDialog(this, label);
	m_pPathLayout = new QHBoxLayout(this);
	this->setLayout(m_pPathLayout);

	m_pPathLabel = new QLabel(label);
	m_pPathBox = new QLineEdit();
	m_pPathBrowse = new QPushButton("...");

	m_pPathLayout->addWidget(m_pPathLabel);
	m_pPathLayout->addWidget(m_pPathBox);
	m_pPathLayout->addWidget(m_pPathBrowse);

	m_pFileDialog->setNameFilters(fileFilter);

	connect(m_pPathBrowse, SIGNAL(clicked()), this, SLOT(OnBrowsePath()));
}

QFileSelect::~QFileSelect()
{
}

void QFileSelect::OnBrowsePath()
{
    if (m_pFileDialog->exec() && m_pFileDialog->result() == QDialog::Accepted)
	{
		m_pPathBox->setText(m_pFileDialog->selectedFiles()[0]);
	}
}
