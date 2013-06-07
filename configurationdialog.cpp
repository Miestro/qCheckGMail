#include "configurationdialog.h"
#include "ui_configurationdialog.h"

configurationDialog::configurationDialog( KWallet::Wallet * wallet,QWidget * parent ) : QDialog( parent ),
	m_ui( new Ui::configurationDialog ),m_wallet( wallet )
{
	m_ui->setupUi( this );
	this->setFixedSize( this->size() );
	this->setWindowFlags( Qt::Window | Qt::Dialog );
	if( parent ){
		this->setFont( parent->font() );
	}
}

void configurationDialog::ShowUI()
{
	this->show();
}

configurationDialog::~configurationDialog()
{
	emit accountsInfo( m_wallet ) ;
	delete m_ui ;
}

void configurationDialog::closeEvent( QCloseEvent * e )
{
	e->ignore();
	this->HideUI();
}


void configurationDialog::HideUI()
{
	this->hide();
	this->deleteLater();
}
