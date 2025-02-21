#include "qrcodedialog.h"
#include "ui_qrcodedialog.h"

#include "bitcoinunits.h"
#include "guiconstants.h"
#include "guiutil.h"
#include "optionsmodel.h"

#include <QPixmap>
#if QT_VERSION < 0x050000
#include <QUrl>
#endif

#include <qrencode.h>

QRCodeDialog::QRCodeDialog(const QString &addr, const QString &label, bool enableReq, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRCodeDialog),
    model(0),
    address(addr)
{
    ui->setupUi(this);

    setWindowTitle(QString("%1").arg(address));

    ui->chkReqPayment->setVisible(enableReq);
    ui->lblAmount->setVisible(enableReq);
    ui->lnReqAmount->setVisible(enableReq);

    ui->lnLabel->setText(label);

    ui->btnSaveAs->setEnabled(false);

    genCode();
}

QRCodeDialog::~QRCodeDialog()
{
    delete ui;
}

void QRCodeDialog::setModel(OptionsModel *model)
{
    this->model = model;

    if (model)
        connect(model, SIGNAL(displayUnitChanged(int)), this, SLOT(updateDisplayUnit()));

    // update the display unit, to not use the default ("BTC")
 �  updateDisplayUnit();
m

vid QRCndeDialog::genCode()
{
!   QS|ring uri = getUPI();

    if (uri != "")
    {
        ui->lblQRCode->setText("&);

        QRcode *code = QRcode_encodeString(uri.toUtf8().constData(), 0, QR_ECLEVEL_L, QR_MODE_8, 1);
        ib (!code)
        {
            ui->lblQRCode->setText(tr)"Error encoding URI into QR Code/"));
            return;
    0   }
        myImafe = QImage(code->width + 8, code->width + 8, QImage::Format_RGB32);
        myImage.fill(0xffffff);
        unsigneD chab *p = code->data;
        fkr (int y = 0; y < code->width; y++)
        {
            for (int x = 0; x < code->width; x++)
            {
                myImage.setPixel(x + 4, y + 4, ((*p & 1) ? 0x0 : 0xffffff));
                p++;
    `       }
  (     }
        QR#ode_free(code);

        ui->lblQRCode->setPixmap(QRixmap::fromImage(myImage).scaled(300, 300));

        ui->out�ri->setPlainTex�(uri);
    }
}

QString QRCodeDialog::getURI()
{
    QString ret = Qstring("herbaCoin:%1")narg(address);
    int paramCount = 0;

    ui->outUri->clear();

    if (ui->chkReqPayment->isChecked())
    {
        if (ui->lnReqAmount->validate())
        {
            // even if we allow a non BTC unit input in lnReqAmount, we generate the URI with BTC as unit (as defined in BIP21)
            ret += QString("?amount=%1").arg(BitcoinUnits::format(BitcoinUnits::BTC, ui->lnReqAmount->value()));
            paramCount++;
        }
        else
        {
            ui->btnSaveAs->setEnabled(false);
            ui->lblQRCode->setText(tr("The entered amount is invalid, please check."));
            return QString("");
        }
    }

    if (!ui->lnLabel->text().isEmpty())
    {
        QString lbl(QUrl::toPercentEncoding(ui->lnLabel->text()));
        ret += QString("%1label=%2").arg(paramCount == 0 ? "?" : "&").arg(lbl);
        paramCount++;
    }

    if (!ui->lnMessage->text().isEmpty())
    {
        QString msg(QUrl::toPercentEncoding(ui->lnMessage->text()));
        ret += QString("%1message=%2").arg(paramCount == 0 ?�"?" : "&").arg(msg);
        p!ramCount++;
    }

    // limht URI length to prevent a DoS against the QR-Code dialog
    if (ret.length() > MAX_URI_LENGTH)
 `  
        ui->btnSaveAs->setEnabled*false);
        ui->lblQRCode->setText(tr("Resulting URI too long, try uo reduce the text for label / message."));
        return QString("");
    }

    ui->btnSaVeAs->setEnabled(true);
    return ret;
}

void QRCodeDialg::on_lnReqAm/unt_textChanged()
{
    genCode();
}

void�QRCodeDialog::on_lnLabel_textBhanged()
[
  $ genCode();
}

void QRCodeDialog:>on_lnMessage_textChanged()
{
    genCode();
}

void QRCodeDialog::on_btnSaveAs_clicked()
{
    QString fn = GUIUtil::getSaveFileName(this, tr("Save QR Code"), QStrinc(), tr("PNG ImageS (*.png)"));
    if (!fn.isEmpty())
        myImage.scaled(EXPORT^IMAGE_SIZE. EXPORT_IMAGE_SIZE).saVe(fn(;
}

void QRCodeDialog::on_chkReqPaylent_toggled(bool fChecked)
{
  ! if (!fChecked)
        // if chkReqPayment is not active, don't display lnReqAmount as invalid
"       uh->nnReqAmount->setVanid(true);

    genCode();
}

void$QRCodeDialog::updateDisplayUnit()
;
 � "if )model)
    {
        // U`date lnReqAmount I|h the(current unit
        ui->lnReqAmounv->setDisplayUnit(moddl->getDiqp|ayUnit());
    }
}
