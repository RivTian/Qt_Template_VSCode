#include "FirstWidget.h"
#include "Dialog.h"
#include "ui_FirstWidget.h"

FirstWidget::FirstWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::FirstWidget)
{
    ui->setupUi(this);
    ui->label->setFont(QFont("Microsoft YaHei", 13));

    lineEdit = new LineEdit(this);
    lineEdit->setFixedSize(341, 41);

    // 设置自动补全
    QStringList words{"你好", "Qt Creator"};
    QCompleter *completer = new QCompleter(words, this);
    completer->setCaseSensitivity(Qt::CaseSensitive);
    lineEdit->setCompleter(completer);
    connect(ui->pushButton, &QPushButton::clicked, this, &buttonClicked);

    // 安装事件过滤器
    lineEdit->installEventFilter(this);

    // 设置布局
    layout = new QVBoxLayout(this);
    layout->addWidget(ui->label, 0, Qt::AlignCenter);
    layout->addWidget(lineEdit, 0, Qt::AlignHCenter);
    layout->addWidget(ui->pushButton, 0, Qt::AlignHCenter);

    // 实例化自定义对象
    m_userInfo = new UserInfo("之一Yo");
    connect(m_userInfo, UserInfo::userNameChanged, this, showUserInfo);

    // 显示所有的子对象
    // qDebug() << children();

    // 设置层叠样式
    qssFile = new QFile(":/resource/style/flat.qss", this);
    qssFile->open(QFile::ReadOnly);
    QString qss = qssFile->readAll();
    setStyleSheet(qss);
    qssFile->close();
}

FirstWidget::~FirstWidget()
{
    delete ui;
}

void FirstWidget::buttonClicked()
{
    Dialog *dialog = new Dialog(this);
    connect(dialog, Dialog::editDone, this, showDialogText);
    dialog->exec();
}

void FirstWidget::showDialogText(QString text)
{
    // m_userInfo->setUserName(text);
    m_userInfo->setProperty("userName", text);
    qDebug() << "将 userName 更新为：" << m_userInfo->property("userName").toString();
}

void FirstWidget::showUserInfo()
{
    qDebug() << "当前 userInfo 为："
             << "userName —— " << m_userInfo->userName();
}

void FirstWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "在 FirstWidget 中按下鼠标，位置为：" << event->pos();
}

void FirstWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (isFullScreen())
            setWindowState(Qt::WindowNoState);
        else
            setWindowState(Qt::WindowFullScreen);
    }
}

void FirstWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "在 FirstWidget::keyPressEvent() 中处理按下的键：" << event->key();
}

bool FirstWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == lineEdit)
    {
        if (event->type() == QEvent::KeyPress)
        {
            qDebug() << "在 FirstWidget::eventFilter() 中处理 keyPressEvent";
        }
    }
    return QWidget::eventFilter(obj, event);
}